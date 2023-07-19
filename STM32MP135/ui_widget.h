/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_15;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_6;
    QWidget *musicDisplayer;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *videoDisplayer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_13;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_10;
    QWidget *pushMode;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_12;
    QWidget *envState;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QSlider *horizontalSlider;
    QWidget *speed;
    QVBoxLayout *verticalLayout;
    QLabel *label_15;
    QDial *dial;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *timeAndDl;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_9;
    QProgressBar *progressBar;
    QLabel *label_19;
    QLCDNumber *lcdNumber;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QWidget *modeSlect;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        verticalLayout_15 = new QVBoxLayout(Widget);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 50));
        label_4->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Tlwg Typist"));
        font.setPointSize(30);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setKerning(true);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_4);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        musicDisplayer = new QWidget(Widget);
        musicDisplayer->setObjectName(QString::fromUtf8("musicDisplayer"));
        musicDisplayer->setMinimumSize(QSize(300, 0));
        musicDisplayer->setStyleSheet(QString::fromUtf8("QWidget#musicDisplayer{\n"
"    background-color:white;\n"
"    border-radius:20px;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(musicDisplayer);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_6 = new QLabel(musicDisplayer);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(20);
        font1.setItalic(false);
        font1.setKerning(true);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_6);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_7 = new QPushButton(musicDisplayer);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(80, 80));
        pushButton_7->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(musicDisplayer);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(80, 80));
        pushButton_8->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(musicDisplayer);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(80, 80));
        pushButton_9->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(musicDisplayer);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(80, 80));
        pushButton_4->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(musicDisplayer);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(80, 80));
        pushButton_5->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(musicDisplayer);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(80, 80));
        pushButton_6->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout);


        verticalLayout_6->addWidget(musicDisplayer);

        videoDisplayer = new QWidget(Widget);
        videoDisplayer->setObjectName(QString::fromUtf8("videoDisplayer"));
        videoDisplayer->setStyleSheet(QString::fromUtf8("QWidget#videoDisplayer{\n"
"    background-color:white;\n"
"    border-radius:20px;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(videoDisplayer);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_13 = new QLabel(videoDisplayer);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(300, 30));
        QFont font2;
        font2.setPointSize(20);
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_13);

        widget_2 = new QWidget(videoDisplayer);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(300, 160));
        widget_2->setMaximumSize(QSize(300, 200));

        verticalLayout_4->addWidget(widget_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_12 = new QPushButton(videoDisplayer);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(120, 50));
        pushButton_12->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(videoDisplayer);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(120, 50));
        pushButton_13->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_13);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_6->addWidget(videoDisplayer);


        horizontalLayout_13->addLayout(verticalLayout_6);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        pushMode = new QWidget(Widget);
        pushMode->setObjectName(QString::fromUtf8("pushMode"));
        pushMode->setStyleSheet(QString::fromUtf8("QWidget#pushMode{\n"
"    background-color:white;\n"
"    border-radius:20px;\n"
"}"));
        verticalLayout_12 = new QVBoxLayout(pushMode);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_14 = new QLabel(pushMode);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_14);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(pushMode);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(150, 80));
        label_7->setMaximumSize(QSize(150, 80));
        QFont font3;
        font3.setPointSize(25);
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("QLabel#label_7{background-color:green}"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_7);

        label_8 = new QLabel(pushMode);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(150, 80));
        label_8->setMaximumSize(QSize(150, 80));
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("QLabel#label_8{background-color:green}"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_8);


        verticalLayout_12->addLayout(horizontalLayout_6);


        verticalLayout_10->addWidget(pushMode);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        envState = new QWidget(Widget);
        envState->setObjectName(QString::fromUtf8("envState"));
        envState->setStyleSheet(QString::fromUtf8("QWidget#envState{\n"
"    background-color:white;\n"
"    border-radius:20px;\n"
"}"));
        verticalLayout_13 = new QVBoxLayout(envState);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(envState);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font4;
        font4.setPointSize(15);
        label_11->setFont(font4);

        horizontalLayout_7->addWidget(label_11);

        horizontalSlider_2 = new QSlider(envState);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_2);


        verticalLayout_13->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(envState);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font4);

        horizontalLayout_8->addWidget(label_10);

        horizontalSlider = new QSlider(envState);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider);


        verticalLayout_13->addLayout(horizontalLayout_8);


        horizontalLayout_12->addWidget(envState);

        speed = new QWidget(Widget);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setStyleSheet(QString::fromUtf8("QWidget#speed\n"
"{\n"
"    background-color:white;\n"
"    border-radius:20px;\n"
"}"));
        verticalLayout = new QVBoxLayout(speed);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_15 = new QLabel(speed);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font4);
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_15);

        dial = new QDial(speed);
        dial->setObjectName(QString::fromUtf8("dial"));

        verticalLayout->addWidget(dial);

        label_16 = new QLabel(speed);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_16);


        horizontalLayout_12->addWidget(speed);


        verticalLayout_10->addLayout(horizontalLayout_12);


        verticalLayout_14->addLayout(verticalLayout_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_6 = new QWidget(Widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(40);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalSlider = new QSlider(widget_6);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMinimumSize(QSize(20, 120));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        verticalSlider_2 = new QSlider(widget_6);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setMinimumSize(QSize(20, 120));
        verticalSlider_2->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_17 = new QLabel(widget_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(75, 25));
        label_17->setFont(font4);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_17);

        label_18 = new QLabel(widget_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(75, 25));
        label_18->setFont(font4);
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_18);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_5->addWidget(widget_6);

        timeAndDl = new QWidget(Widget);
        timeAndDl->setObjectName(QString::fromUtf8("timeAndDl"));
        timeAndDl->setStyleSheet(QString::fromUtf8("QWidget#timeAndDl{\n"
"    background-color:white;\n"
"    border-radius:20px;\n"
"}"));
        verticalLayout_11 = new QVBoxLayout(timeAndDl);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_9 = new QLabel(timeAndDl);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(120, 20));
        label_9->setFont(font4);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_9);

        progressBar = new QProgressBar(timeAndDl);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(120, 50));
        progressBar->setMaximumSize(QSize(135, 100));
        progressBar->setValue(24);

        verticalLayout_11->addWidget(progressBar);

        label_19 = new QLabel(timeAndDl);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(120, 20));
        label_19->setFont(font4);
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_19);

        lcdNumber = new QLCDNumber(timeAndDl);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(120, 50));
        lcdNumber->setMaximumSize(QSize(135, 100));

        verticalLayout_11->addWidget(lcdNumber);


        horizontalLayout_5->addWidget(timeAndDl);


        verticalLayout_14->addLayout(horizontalLayout_5);


        horizontalLayout_13->addLayout(verticalLayout_14);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(300, 16777215));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_12);

        textBrowser = new QTextBrowser(widget_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(300, 100));
        textBrowser->setMaximumSize(QSize(300, 100));

        verticalLayout_3->addWidget(textBrowser);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_10 = new QPushButton(widget_3);
        buttonGroup_2 = new QButtonGroup(Widget);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(pushButton_10);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(120, 50));
        pushButton_10->setCheckable(true);

        horizontalLayout_3->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(widget_3);
        buttonGroup_2->addButton(pushButton_11);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(120, 50));
        pushButton_11->setCheckable(true);

        horizontalLayout_3->addWidget(pushButton_11);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(widget_3);


        verticalLayout_9->addLayout(verticalLayout_5);

        modeSlect = new QWidget(Widget);
        modeSlect->setObjectName(QString::fromUtf8("modeSlect"));
        modeSlect->setFont(font4);
        modeSlect->setStyleSheet(QString::fromUtf8("QWidget#modeSlect{\n"
"    background-color:white;\n"
"    border-radius:20px;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(modeSlect);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_5 = new QLabel(modeSlect);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font5;
        font5.setPointSize(20);
        font5.setItalic(true);
        label_5->setFont(font5);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label = new QLabel(modeSlect);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 80));
        label->setMaximumSize(QSize(80, 80));
        label->setStyleSheet(QString::fromUtf8("QLabel#label{\n"
"	border-image:url(:/image/1.png);\n"
"}\n"
"\n"
"QLabel{\n"
"	border-radius:10px\n"
"}"));

        horizontalLayout_11->addWidget(label);

        pushButton = new QPushButton(modeSlect);
        buttonGroup = new QButtonGroup(Widget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(150, 80));
        pushButton->setMaximumSize(QSize(200, 200));
        pushButton->setCheckable(true);

        horizontalLayout_11->addWidget(pushButton);


        verticalLayout_8->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_2 = new QLabel(modeSlect);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 80));
        label_2->setMaximumSize(QSize(80, 80));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2{\n"
"	border-image:url(:/image/2.png);\n"
"}"));

        horizontalLayout_10->addWidget(label_2);

        pushButton_2 = new QPushButton(modeSlect);
        buttonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 80));
        pushButton_2->setMaximumSize(QSize(200, 200));
        pushButton_2->setCheckable(true);

        horizontalLayout_10->addWidget(pushButton_2);


        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_3 = new QLabel(modeSlect);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 80));
        label_3->setMaximumSize(QSize(80, 80));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3{\n"
"	border-image:url(:/image/3.png)\n"
"}"));

        horizontalLayout_9->addWidget(label_3);

        pushButton_3 = new QPushButton(modeSlect);
        buttonGroup->addButton(pushButton_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(150, 80));
        pushButton_3->setMaximumSize(QSize(200, 200));
        pushButton_3->setCheckable(true);

        horizontalLayout_9->addWidget(pushButton_3);


        verticalLayout_8->addLayout(horizontalLayout_9);


        verticalLayout_9->addWidget(modeSlect);


        horizontalLayout_13->addLayout(verticalLayout_9);


        verticalLayout_15->addLayout(horizontalLayout_13);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label_4->setText(QApplication::translate("Widget", "\346\231\272\350\203\275\345\251\264\345\204\277\350\275\246", nullptr));
        label_6->setText(QApplication::translate("Widget", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", nullptr));
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        label_13->setText(QApplication::translate("Widget", "\350\247\206\351\242\221\346\222\255\346\224\276", nullptr));
        pushButton_12->setText(QApplication::translate("Widget", "PLAY", nullptr));
        pushButton_13->setText(QApplication::translate("Widget", "NEXT", nullptr));
        label_14->setText(QApplication::translate("Widget", "\346\211\213\346\216\250\346\250\241\345\274\217", nullptr));
        label_7->setText(QApplication::translate("Widget", "\345\267\246\346\211\213", nullptr));
        label_8->setText(QApplication::translate("Widget", "\345\217\263\346\211\213", nullptr));
        label_11->setText(QApplication::translate("Widget", "\346\271\277\345\272\246:47", nullptr));
        label_10->setText(QApplication::translate("Widget", "\346\270\251\345\272\246:31", nullptr));
        label_15->setText(QApplication::translate("Widget", "\350\275\246\351\200\237", nullptr));
        label_16->setText(QApplication::translate("Widget", "TextLabel", nullptr));
        label_17->setText(QApplication::translate("Widget", "\344\272\256\345\272\246:50", nullptr));
        label_18->setText(QApplication::translate("Widget", "\345\243\260\351\237\263:50", nullptr));
        label_9->setText(QApplication::translate("Widget", "\347\224\265\346\261\240\347\224\265\351\207\217", nullptr));
        label_19->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label_12->setText(QApplication::translate("Widget", "\350\277\234\347\250\213\346\216\247\345\210\266", nullptr));
        pushButton_10->setText(QApplication::translate("Widget", "\345\274\200\345\220\257\350\277\234\347\250\213\346\216\247\345\210\266", nullptr));
        pushButton_11->setText(QApplication::translate("Widget", "\345\205\263\351\227\255\350\277\234\347\250\213\346\216\247\345\210\266", nullptr));
        label_5->setText(QApplication::translate("Widget", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("Widget", "\346\211\213\346\216\250\346\250\241\345\274\217", nullptr));
        label_2->setText(QString());
        pushButton_2->setText(QApplication::translate("Widget", "\350\272\253\345\211\215\350\267\237\351\232\217", nullptr));
        label_3->setText(QString());
        pushButton_3->setText(QApplication::translate("Widget", "\350\272\253\345\220\216\350\267\237\351\232\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
