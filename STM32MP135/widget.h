#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QEvent>
#include <QFile>

/* 媒体信息结构体 */
struct MediaObjectInfo {
    /* 用于保存歌曲文件名 */
    QString fileName;
    /* 用于保存歌曲文件路径 */
    QString filePath;
};

/* 媒体信息结构体 */
struct MediaObjectInfoVideo{
    /* 用于保存视频文件名 */
    QString fileName;
    /* 用于保存视频文件路径 */
    QString filePath;
};

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_toggled(bool checked);

    void on_pushButton_2_toggled(bool checked);

    void on_pushButton_3_toggled(bool checked);

    void on_pushButton_5_clicked();

    void on_pushButton_5_toggled(bool checked);

    void timerTimeOut();

    void timerTimeOut1();

    void dialValueChanged(int);

    void verticalSliderValueChanged(int);

    void vertical1SliderValueChanged(int);

    void horizontalSliderValueChanged(int);

    void horizontal1SliderValueChanged(int);


    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void serialPortReadyRead();
    /* 播放按钮点击 */
    void btn_play_clicked();

    /* 下一曲按钮点击*/
    void btn_next_clicked();

    /* 上一曲按钮点击 */
    void btn_previous_clicked();

    /* 播放按钮点击 */
    void btn_play_clicked_video();

    /* 下一个视频按钮点击 */
    void btn_next_clicked_video();


private:
    Ui::Widget *ui;

    QTimer *timer;

    QVBoxLayout *vLayout;

    int value;

    int modestate;

    /* 文件 */
    QFile fileBeep;

    /* 串口对象 */
    QSerialPort *serialPort;

    /* 媒体播放器，用于播放音乐 */
    QMediaPlayer *musicPlayer;

    /* 媒体列表 */
    QMediaPlaylist *mediaPlaylist;
    /* 媒体信息存储 */
    QVector<MediaObjectInfo> mediaObjectInfo;

    /* 视频显示窗口 */
    QVideoWidget *videoWidget;

    /* 媒体播放器，用于播放视频 */
    QMediaPlayer *videoPlayer;

    /* 媒体列表 */
    QMediaPlaylist *mediaPlaylistVideo;

    /* 媒体信息存储 */
    QVector<MediaObjectInfo> mediaObjectInfoVideo;

    /* 扫描歌曲 */
    void scanSongs();

    /* 媒体播放器类初始化 */
    void mediaPlayerInit();


    /* 扫描本地视频文件 */
    void scanVideoFiles();

    /* 媒体初始化 */
    void mediaPlayerInitVideo();

    /* 设置 BEEP 的状态 */
     void setBeepState(int state);

    /* 重写按键事件 */
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};
#endif // WIDGET_H
