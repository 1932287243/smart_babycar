#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPalette>
#include <QPixmap>
#include <QGuiApplication>
#include <QScreen>
#include <QFileInfoList>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QList <QScreen *> list_screen =  QGuiApplication::screens();

    /* 如果是ARM平台，直接设置大小为屏幕的大小 */
#if __arm__
    /* 重设大小 */
    this->resize(list_screen.at(0)->geometry().width(),
                 list_screen.at(0)->geometry().height());
#else
    /* 否则则设置主窗体大小为800x480 */
    this->resize(1024,600);
#endif
    /* 初始化 */
    serialPort = new QSerialPort(this);
    connect(serialPort, SIGNAL(readyRead()),
            this, SLOT(serialPortReadyRead()));

    /* 媒体播放器初始化 */
    mediaPlayerInit();
    /* 扫描歌曲 */
    scanSongs();
    /* 按钮信号槽连接 */
    connect(ui->pushButton_4, SIGNAL(clicked()),
            this, SLOT(btn_previous_clicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()),
            this, SLOT(btn_play_clicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()),
            this, SLOT(btn_next_clicked()));

    videoWidget = new QVideoWidget();
    videoWidget->setStyleSheet("border-image: none;"
                               "background: transparent;"
                               "border:none");
    videoWidget->setMinimumSize(300, 160);

    vLayout = new QVBoxLayout();
    vLayout->addWidget(videoWidget);
    ui->widget_2->setLayout(vLayout);

    /* 媒体初始化 */
    mediaPlayerInitVideo();

    /* 扫描本地视频 */
    scanVideoFiles();

    /* 按钮连接信号槽 */
    connect(ui->pushButton_12, SIGNAL(clicked()),
            this, SLOT(btn_play_clicked_video()));
    connect(ui->pushButton_13, SIGNAL(clicked()),
            this, SLOT(btn_next_clicked_video()));

    //初始化模式
    modestate = 0;

    fileBeep.setFileName("/sys/devices/platform/leds/leds/beep/brightness");
    if (!fileBeep.exists())
        /* 设置按钮的初始化文本 */
        qDebug() << "打开Beep成功" << endl;

    //设置背景
    //    QPixmap pixmap = QPixmap(":/image/background.jpg").scaled(this->size());
    //    QPalette palette(this->palette());
    //    palette.setBrush(QPalette::Background, QBrush(pixmap));
    //    this->setPalette(palette);

    //    QPalette pal = this->palette();
    //    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/background.jpg")));
    //    this->setPalette(pal);
    //this->setStyleSheet("background-image:url(:/image/background.png);");
    this->setGeometry(0, 0, 1024, 600);
    //ui->pushButton_4->setCheckable(true);
    ui->pushButton_5->setCheckable(true);
    ui->pushButton_7->setCheckable(true);
    //显示时间
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    QTime time = QTime::currentTime();
    ui->lcdNumber->display(time.toString("hh:mm:ss"));
    timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this,SLOT(timerTimeOut()));

    //显示当前实时电量
    /* 设置progressBar的范围值 */
    ui->progressBar->setRange(0, 100);
    /* 初始化value为0 */
    value = 100;
    /* 给progressBar设置当前值 */
    ui->progressBar->setValue(value);
    /* 设置当前文本字符串的显示格式 */
    ui->progressBar->setFormat("%p%");

    /* 定时器实例化设置每100ms发送一个timeout信号 */
    timer = new QTimer(this);
    timer->start(100000);

    /* 信号槽连接 */
    connect(timer, SIGNAL(timeout()),this, SLOT(timerTimeOut1()));

    //速度显示
    //ui->dial->setGeometry(500,100,200,200);
    /* 设置页长（两个最大刻度的间距）*/
    ui->dial->setPageStep(10);

    /* 设置刻度可见 */
    ui->dial->setNotchesVisible(true);

    /* 设置两个凹槽之间的目标像素数 */
    ui->dial->setNotchTarget(1.00);

    /* 设置ui->dial值的范围 */
    ui->dial->setRange(0,100);

    /* 开启后可指向圆的任何角度 */
    //ui->dial->setWrapping(true);

    /* 设置显示位置与大小 */
    //ui->label_16->setGeometry(370, 300, 200, 50);

    /* 初始化为0km/h */
    ui->label_16->setText("0km/h");

    /* 信号槽连接 */
    connect(ui->dial, SIGNAL(valueChanged(int)),this, SLOT(dialValueChanged(int)));
    //亮度调节
    ui->verticalSlider->setRange(0, 99);
    ui->verticalSlider->setValue(50);
    connect(ui->verticalSlider, SIGNAL(valueChanged(int)),this, SLOT(verticalSliderValueChanged(int)));
    //声音调节
    ui->verticalSlider_2->setRange(0, 99);
    ui->verticalSlider_2->setValue(50);
    connect(ui->verticalSlider_2, SIGNAL(valueChanged(int)),this, SLOT(vertical1SliderValueChanged(int)));

    //温度
    ui->horizontalSlider->setRange(0,99);
    ui->horizontalSlider->setValue(31);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),this, SLOT(horizontalSliderValueChanged(int)));
    //湿度
    ui->horizontalSlider_2->setRange(0, 99);
    ui->horizontalSlider_2->setValue(47);
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),this, SLOT(horizontal1SliderValueChanged(int)));


    //设置label文字居中显示
    //ui->label_16->setAlignment(Qt::AlignHCenter);
    //ui->label_17->setAlignment(Qt::AlignHCenter);
    //ui->label_18->setAlignment(Qt::AlignHCenter);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_toggled(bool checked)
{
    qDebug()<<"手推模式"<< checked << endl;
    modestate = 1;
}

void Widget::on_pushButton_2_toggled(bool checked)
{
    qDebug()<<"身前跟随"<< checked << endl;
    modestate = 2;
    //关闭Beep
    setBeepState(1);
    ui->label_7->setStyleSheet("QLabel#label_7{background-color:green;}");
}

void Widget::on_pushButton_3_toggled(bool checked)
{
    qDebug()<<"身后跟随"<< checked << endl;
    modestate = 3;
    //关闭Beep
    setBeepState(1);
    ui->label_7->setStyleSheet("QLabel#label_7{background-color:green;}");
}

void Widget::on_pushButton_5_clicked()
{
    qDebug()<<"开始播放"<< endl;
}

void Widget::on_pushButton_5_toggled(bool checked)
{
    if(checked)
        qDebug()<<"开始播放"<< endl;
    else
        qDebug()<<"暂停播放"<< endl;
}

void Widget::timerTimeOut()
{
    /* 当定时器计时 1000 毫秒后，刷新 lcd 显示当前系统时间 */
    QTime time = QTime::currentTime();
    /* 设置显示的样式 */
    ui->lcdNumber->display(time.toString("hh:mm:ss"));
}
void Widget::timerTimeOut1()
{
    /* 定显示器时间到，value值自加一 */
    value --;
    ui->progressBar->setValue(value);
    /* 若value值大于100，令value再回到0 */
    if(value<0)
        value = 100;
}

void Widget::dialValueChanged(int val)
{
    /* QString::number()转换成字符串 */
    ui->label_16->setText(QString::number(val) + "km/h");
}

void Widget::verticalSliderValueChanged(int val)
{
    /* 当水平滑动条的值改变时，改变垂直滑动条的值 */
    ui->verticalSlider->setSliderPosition(val);

    /* 将 int 类型转变成字符 */

    QString str = "亮度:" + QString::number(val);

    /* 显示当前垂直或水平滑动条的值 */
    ui->label_17->setText(str);

}

void Widget::vertical1SliderValueChanged(int val)
{
    ui->verticalSlider_2->setSliderPosition(val);
    QString str = "声音:" + QString::number(val);

    /* 显示当前垂直或水平滑动条的值 */
    ui->label_18->setText(str);
}

void Widget::horizontalSliderValueChanged(int val)
{
    /* 当水平滑动条的值改变时，改变垂直滑动条的值 */
    ui->horizontalSlider->setSliderPosition(val);

    /* 将 int 类型转变成字符 */

    QString str = "温度:" + QString::number(val);

    /* 显示当前垂直或水平滑动条的值 */
    ui->label_10->setText(str);
}

void Widget::horizontal1SliderValueChanged(int val)
{
    /* 当水平滑动条的值改变时，改变垂直滑动条的值 */
    ui->horizontalSlider_2->setSliderPosition(val);

    /* 将 int 类型转变成字符 */

    QString str = "湿度:" + QString::number(val);

    /* 显示当前垂直或水平滑动条的值 */
    ui->label_11->setText(str);
}

void Widget::serialPortReadyRead()
{
    /* 接收缓冲区中读取数据 */
    QByteArray buf = serialPort->readAll();
    ui->textBrowser->insertPlainText(QString(buf));
}

void Widget::on_pushButton_10_clicked()
{
    /* 设置串口名 */
    serialPort->setPortName("ttySTM1");
    /* 设置波特率 */
    serialPort->setBaudRate(9600);
    /* 设置数据位数 */
    serialPort->setDataBits(QSerialPort::Data8);
    /* 设置奇偶校验 */
    serialPort->setParity(QSerialPort::NoParity);
    /* 设置停止位 */
    serialPort->setStopBits(QSerialPort::OneStop);

    /* 设置流控制 */
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    if (!serialPort->open(QIODevice::ReadWrite))
        QMessageBox::about(NULL, "错误",
                           "串口无法打开！可能串口已经被占用！");
    else
    {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        serialPort->write("Welcom to use the intelligent stroller remote control terminal!!!");
    }
}

void Widget::on_pushButton_11_clicked()
{
    serialPort->close();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
}

void Widget::scanSongs()
{
    QDir dir(QCoreApplication::applicationDirPath()
             + "/myMusic");
    QDir dirbsolutePath(dir.absolutePath());
    qDebug()<<dirbsolutePath.absolutePath()<< endl;
    /* 如果目录存在 */
    if (dirbsolutePath.exists()) {
        /* 定义过滤器 */
        QStringList filter;
        /* 包含所有.mp3后缀的文件 */
        filter << "*.mp3";
        /* 获取该目录下的所有文件 */
        QFileInfoList files =
                dirbsolutePath.entryInfoList(filter, QDir::Files);
        /* 遍历 */
        qDebug()<<files.count()<< endl;
        for (int i = 0; i < files.count(); i++) {
            MediaObjectInfo info;
            /* 使用utf-8编码 */
            QString fileName = QString::fromUtf8(files.at(i)
                                                 .fileName()
                                                 .replace(".mp3", "")
                                                 .toUtf8()
                                                 .data());
            info.fileName = fileName + "\n"
                    + fileName.split("-").at(1);
            info.filePath = QString::fromUtf8(files.at(i)
                                              .filePath()
                                              .toUtf8()
                                              .data());
            qDebug() << info.filePath << endl;
            /* 媒体列表添加歌曲 */
            if (mediaPlaylist->addMedia(
                        QUrl::fromLocalFile(info.filePath))) {
                /* 添加到容器数组里储存 */
                mediaObjectInfo.append(info);
                /* 添加歌曲名字至列表 */
                //listWidget->addItem(info.fileName);
            } else {
                qDebug()<<
                           mediaPlaylist->errorString()
                           .toUtf8().data()
                        << endl;
                qDebug()<< "  Error number:"
                        << mediaPlaylist->error()
                        << endl;
            }
        }
    }
}

void Widget::mediaPlayerInit()
{
    musicPlayer = new QMediaPlayer(this);
    mediaPlaylist = new QMediaPlaylist(this);
    /* 确保列表是空的 */
    mediaPlaylist->clear();
    /* 设置音乐播放器的列表为mediaPlaylist */
    musicPlayer->setPlaylist(mediaPlaylist);
    /* 设置播放模式，Loop是列循环 */
    mediaPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    qDebug() << "音乐播放器初始化成功！！！" <<endl;
}

void Widget::btn_play_clicked()
{
    int state = musicPlayer->state();

    switch (state) {
    case QMediaPlayer::StoppedState:
        /* 媒体播放 */
        musicPlayer->play();
        qDebug() << "hhh播放开始" << endl;
        break;

    case QMediaPlayer::PlayingState:
        /* 媒体暂停 */
        musicPlayer->pause();
        qDebug() << "hhh播放暂停" << endl;
        break;

    case QMediaPlayer::PausedState:
        musicPlayer->play();
        qDebug() << "hhh播放开始" << endl;
        break;
    }
}

void Widget::btn_next_clicked()
{
    musicPlayer->stop();
    int count = mediaPlaylist->mediaCount();
    if (0 == count)
        return;
    qDebug() << "下一首" << endl;
    /* 列表下一个 */
    mediaPlaylist->next();
    musicPlayer->play();
}

void Widget::btn_previous_clicked()
{
    musicPlayer->stop();
    int count = mediaPlaylist->mediaCount();
    if (0 == count)
        return;

    /* 列表上一个 */
    qDebug() << "上一首" << endl;
    mediaPlaylist->previous();
    musicPlayer->play();
}

void Widget::mediaPlayerInitVideo()
{
    videoPlayer = new QMediaPlayer(this);
    mediaPlaylistVideo = new QMediaPlaylist(this);
    /* 确保列表是空的 */
    mediaPlaylistVideo->clear();
    /* 设置视频播放器的列表为mediaPlaylist */
    videoPlayer->setPlaylist(mediaPlaylistVideo);
    /* 设置视频输出窗口 */
    videoPlayer->setVideoOutput(videoWidget);
    /* 设置播放模式，Loop是列循环 */
    mediaPlaylistVideo->setPlaybackMode(QMediaPlaylist::Loop);
    /* 设置默认软件音量为50% */
    videoPlayer->setVolume(50);
}

void Widget::scanVideoFiles()
{
    QDir dir(QCoreApplication::applicationDirPath()
             + "/myVideo");
    QDir dirbsolutePath(dir.absolutePath());
    /* 如果目录存在 */
    if (dirbsolutePath.exists()) {
        /* 定义过滤器 */
        QStringList filter;
        /* 包含所有xx后缀的文件 */
        filter << "*.mp4" << "*.mkv" << "*.wmv" << "*.avi";
        /* 获取该目录下的所有文件 */
        QFileInfoList files =
                dirbsolutePath.entryInfoList(filter, QDir::Files);
        /* 遍历 */
        for (int i = 0; i < files.count(); i++) {
            MediaObjectInfo info;
            /* 使用utf-8编码 */
            info.fileName = QString::fromUtf8(files.at(i)
                                              .fileName()
                                              .toUtf8()
                                              .data());
            info.filePath = QString::fromUtf8(files.at(i)
                                              .filePath()
                                              .toUtf8()
                                              .data());
            qDebug() << info.filePath << endl;
            /* 媒体列表添加视频 */
            if (mediaPlaylistVideo->addMedia(
                        QUrl::fromLocalFile(info.filePath))) {
                /* 添加到容器数组里储存 */
                mediaObjectInfoVideo.append(info);
                /* 添加视频名字至列表 */
                //listWidget->addItem(info.fileName);
            } else {
                qDebug()<<
                           mediaPlaylistVideo->errorString()
                           .toUtf8().data()
                        << endl;
                qDebug()<< "  Error number:"
                        << mediaPlaylistVideo->error()
                        << endl;
            }
        }
    }
}

void Widget::btn_play_clicked_video()
{
    int state = videoPlayer->state();
    switch (state) {
    case QMediaPlayer::StoppedState:
        /* 媒体播放 */
        videoPlayer->play();
        break;

    case QMediaPlayer::PlayingState:
        /* 媒体暂停 */
        videoPlayer->pause();
        break;

    case QMediaPlayer::PausedState:
        /* 设置视频输出窗口 */
        videoPlayer->play();
        break;
    }
}

void Widget::btn_next_clicked_video()
{
    videoPlayer->stop();
    int count = mediaPlaylistVideo->mediaCount();
    if (0 == count)
        return;

    /* 列表下一个 */
    mediaPlaylistVideo->next();
    videoPlayer->play();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
#if __arm__
    /* 判断按下的按键，也就是板子 KEY 按键 */
    if(event->key() == Qt::Key_VolumeDown && modestate == 1) {
        setBeepState(1);
        ui->label_7->setStyleSheet("QLabel#label_7{background-color:green;}");
    }
#else
    /* 判断按下的按键，也就是"↓"方向键 */
    if(event->key() == Qt::Key_Down) {
        /* 设置 label 的文本 */
        ui->label_7->setStyleSheet("QLabel#label_7{background-color:red;}");
        qDebug() << "按键按下" <<endl;
    }

#endif
    /* 保存默认事件 */
    QWidget::keyPressEvent(event);
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
#if __arm__
    /* 判断松开的按键，也就是板子 KEY0 按键 */
    if(event->key() == Qt::Key_VolumeDown  && modestate == 1) {
        /* 设置 label 的文本 */
        //label->setText("VolumeDown 按键松开");
        setBeepState(0);
        ui->label_7->setStyleSheet("QLabel#label_7{background-color:red;}");
    }
#else
    /* 判断按下的按键，也就是"↓"方向键 */
    if(event->key() == Qt::Key_Down) {
        /* 设置 label 的文本 */
        //label->setText("Down 按键松开");
        ui->label_7->setStyleSheet("QLabel#label_7{background-color:green;}");
        qDebug() << "按键松开" <<endl;
    }
#endif
    /* 保存默认事件 */
    QWidget::keyReleaseEvent(event);
}

void Widget::setBeepState(int state)
{
    /* 如果文件不存在，则返回 */
    if (!fileBeep.exists())
        return;

    if(!fileBeep.open(QIODevice::ReadWrite))
        qDebug()<<fileBeep.errorString();

    QByteArray buf[2] = {"0", "1"};

    if (state)
        fileBeep.write(buf[0]);
    else
        fileBeep.write(buf[1]);

    fileBeep.close();
}


