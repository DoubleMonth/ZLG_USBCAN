/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *cBoxDevice;
    QLabel *label_2;
    QComboBox *cBoxSuoYin;
    QComboBox *cBoxChannel;
    QLabel *label_3;
    QComboBox *cBoxMode;
    QComboBox *cBoxBoud;
    QCheckBox *checkBoxBound;
    QLineEdit *lEditBound;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *checkBox_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lEditYanShouMa;
    QLineEdit *lEditPingBiMa;
    QComboBox *cBoxLvbo;
    QCheckBox *cBoxAllChannel;
    QPushButton *btnOpenDevice;
    QPushButton *btnInitDevice;
    QPushButton *btnStartDevice;
    QPushButton *btnResetDevice;
    QPushButton *btnCloseDevice;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lEdit_ID;
    QComboBox *cBoxZhenType;
    QComboBox *cBoxProtocol;
    QComboBox *cBoxJiaSu;
    QLineEdit *lEditSendData;
    QComboBox *cBoxSendType;
    QPushButton *btnSend;
    QTextBrowser *textBrowser;
    QPushButton *btnClear;
    QPushButton *btnDeviceMessage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(649, 542);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 631, 111));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 31, 16));
        cBoxDevice = new QComboBox(groupBox);
        cBoxDevice->setObjectName(QStringLiteral("cBoxDevice"));
        cBoxDevice->setGeometry(QRect(58, 20, 101, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 20, 41, 16));
        cBoxSuoYin = new QComboBox(groupBox);
        cBoxSuoYin->setObjectName(QStringLiteral("cBoxSuoYin"));
        cBoxSuoYin->setGeometry(QRect(220, 20, 69, 22));
        cBoxChannel = new QComboBox(groupBox);
        cBoxChannel->setObjectName(QStringLiteral("cBoxChannel"));
        cBoxChannel->setGeometry(QRect(360, 20, 69, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 20, 31, 16));
        cBoxMode = new QComboBox(groupBox);
        cBoxMode->setObjectName(QStringLiteral("cBoxMode"));
        cBoxMode->setGeometry(QRect(60, 50, 101, 22));
        cBoxBoud = new QComboBox(groupBox);
        cBoxBoud->setObjectName(QStringLiteral("cBoxBoud"));
        cBoxBoud->setGeometry(QRect(220, 50, 69, 22));
        checkBoxBound = new QCheckBox(groupBox);
        checkBoxBound->setObjectName(QStringLiteral("checkBoxBound"));
        checkBoxBound->setGeometry(QRect(320, 50, 101, 21));
        lEditBound = new QLineEdit(groupBox);
        lEditBound->setObjectName(QStringLiteral("lEditBound"));
        lEditBound->setGeometry(QRect(420, 50, 113, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 50, 31, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 50, 41, 16));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(520, 20, 91, 16));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 80, 54, 12));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(170, 80, 61, 16));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(350, 80, 61, 16));
        lEditYanShouMa = new QLineEdit(groupBox);
        lEditYanShouMa->setObjectName(QStringLiteral("lEditYanShouMa"));
        lEditYanShouMa->setGeometry(QRect(230, 80, 113, 20));
        lEditPingBiMa = new QLineEdit(groupBox);
        lEditPingBiMa->setObjectName(QStringLiteral("lEditPingBiMa"));
        lEditPingBiMa->setGeometry(QRect(440, 80, 113, 20));
        cBoxLvbo = new QComboBox(groupBox);
        cBoxLvbo->setObjectName(QStringLiteral("cBoxLvbo"));
        cBoxLvbo->setGeometry(QRect(70, 80, 69, 22));
        cBoxAllChannel = new QCheckBox(groupBox);
        cBoxAllChannel->setObjectName(QStringLiteral("cBoxAllChannel"));
        cBoxAllChannel->setGeometry(QRect(440, 20, 71, 16));
        btnOpenDevice = new QPushButton(centralWidget);
        btnOpenDevice->setObjectName(QStringLiteral("btnOpenDevice"));
        btnOpenDevice->setGeometry(QRect(20, 140, 75, 23));
        btnInitDevice = new QPushButton(centralWidget);
        btnInitDevice->setObjectName(QStringLiteral("btnInitDevice"));
        btnInitDevice->setGeometry(QRect(210, 140, 75, 23));
        btnStartDevice = new QPushButton(centralWidget);
        btnStartDevice->setObjectName(QStringLiteral("btnStartDevice"));
        btnStartDevice->setGeometry(QRect(320, 140, 75, 23));
        btnResetDevice = new QPushButton(centralWidget);
        btnResetDevice->setObjectName(QStringLiteral("btnResetDevice"));
        btnResetDevice->setGeometry(QRect(400, 140, 75, 23));
        btnCloseDevice = new QPushButton(centralWidget);
        btnCloseDevice->setObjectName(QStringLiteral("btnCloseDevice"));
        btnCloseDevice->setGeometry(QRect(500, 140, 75, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 180, 631, 101));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 20, 41, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 20, 41, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(320, 20, 31, 16));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 50, 131, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(330, 50, 61, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(440, 20, 61, 16));
        lEdit_ID = new QLineEdit(groupBox_2);
        lEdit_ID->setObjectName(QStringLiteral("lEdit_ID"));
        lEdit_ID->setGeometry(QRect(60, 20, 101, 20));
        cBoxZhenType = new QComboBox(groupBox_2);
        cBoxZhenType->setObjectName(QStringLiteral("cBoxZhenType"));
        cBoxZhenType->setGeometry(QRect(230, 20, 69, 22));
        cBoxProtocol = new QComboBox(groupBox_2);
        cBoxProtocol->setObjectName(QStringLiteral("cBoxProtocol"));
        cBoxProtocol->setGeometry(QRect(350, 20, 69, 22));
        cBoxJiaSu = new QComboBox(groupBox_2);
        cBoxJiaSu->setObjectName(QStringLiteral("cBoxJiaSu"));
        cBoxJiaSu->setGeometry(QRect(520, 20, 69, 22));
        lEditSendData = new QLineEdit(groupBox_2);
        lEditSendData->setObjectName(QStringLiteral("lEditSendData"));
        lEditSendData->setGeometry(QRect(140, 50, 171, 20));
        cBoxSendType = new QComboBox(groupBox_2);
        cBoxSendType->setObjectName(QStringLiteral("cBoxSendType"));
        cBoxSendType->setGeometry(QRect(420, 50, 69, 22));
        btnSend = new QPushButton(groupBox_2);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(520, 70, 75, 23));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 280, 431, 192));
        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(510, 380, 75, 23));
        btnDeviceMessage = new QPushButton(centralWidget);
        btnDeviceMessage->setObjectName(QStringLiteral("btnDeviceMessage"));
        btnDeviceMessage->setGeometry(QRect(120, 140, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 649, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207", Q_NULLPTR));
        cBoxDevice->clear();
        cBoxDevice->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "USBCAN-2E-U", Q_NULLPTR)
         << QApplication::translate("MainWindow", "USBCAN1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "USBCAN2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "USBCAN-E-U", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PCIECANFD-100U", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PCIECANFD-200U", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PCIECANFD-400U", Q_NULLPTR)
         << QApplication::translate("MainWindow", "USBCANFD-100U", Q_NULLPTR)
         << QApplication::translate("MainWindow", "USBCANFD-MINI", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\347\264\242\345\274\225\345\217\267", Q_NULLPTR));
        cBoxSuoYin->clear();
        cBoxSuoYin->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "\351\200\232\351\201\223", Q_NULLPTR));
        cBoxMode->clear();
        cBoxMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\255\243\345\270\270", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\252\345\220\254", Q_NULLPTR)
        );
        cBoxBoud->clear();
        cBoxBoud->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1Mbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "800kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "500kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "250kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "125kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "100kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "50kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "20kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10kbps", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5kbps", Q_NULLPTR)
        );
        checkBoxBound->setText(QApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\250\241\345\274\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "\347\273\210\347\253\257\347\224\265\351\230\273\344\275\277\350\203\275", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242\346\250\241\345\274\217", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\351\252\214\346\224\266\347\240\201(0x)", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\345\261\217\350\224\275\347\240\201(0x)", Q_NULLPTR));
        lEditYanShouMa->setText(QApplication::translate("MainWindow", "00000000", Q_NULLPTR));
        lEditPingBiMa->setText(QApplication::translate("MainWindow", "FFFFFFFF", Q_NULLPTR));
        cBoxLvbo->clear();
        cBoxLvbo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\215\225\346\273\244\346\263\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\214\346\273\244\346\263\242", Q_NULLPTR)
        );
        cBoxAllChannel->setText(QApplication::translate("MainWindow", "\346\211\200\346\234\211\351\200\232\351\201\223", Q_NULLPTR));
        btnOpenDevice->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\256\276\345\244\207", Q_NULLPTR));
        btnInitDevice->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226CAN", Q_NULLPTR));
        btnStartDevice->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250CAN", Q_NULLPTR));
        btnResetDevice->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", Q_NULLPTR));
        btnCloseDevice->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\350\256\276\345\244\207", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207\350\256\276\347\275\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ID(0x)", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\270\247\347\261\273\345\236\213", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\345\215\217\350\256\256", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256(0x,\344\273\245\347\251\272\346\240\274\351\232\224\345\274\200)", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\271\345\274\217", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "CANFD\345\212\240\351\200\237", Q_NULLPTR));
        lEdit_ID->setText(QApplication::translate("MainWindow", "00000001", Q_NULLPTR));
        cBoxZhenType->clear();
        cBoxZhenType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\211\251\345\261\225\345\270\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206\345\270\247", Q_NULLPTR)
        );
        cBoxProtocol->clear();
        cBoxProtocol->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "CAN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CANFD", Q_NULLPTR)
        );
        cBoxJiaSu->clear();
        cBoxJiaSu->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\220\246", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\230\257", Q_NULLPTR)
        );
        lEditSendData->setText(QApplication::translate("MainWindow", "00 11 22 33 44 55 66 77", Q_NULLPTR));
        cBoxSendType->clear();
        cBoxSendType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\255\243\345\270\270\345\217\221\351\200\201", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\225\346\254\241\345\217\221\351\200\201", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\207\252\345\217\221\350\207\252\346\224\266", Q_NULLPTR)
        );
        btnSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        btnClear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        btnDeviceMessage->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
