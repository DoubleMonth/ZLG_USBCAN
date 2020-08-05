#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "zlgcan_x86/zlgcan.h"
#include <QTimer>
#include <QLabel>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_btnOpenDevice_clicked();
    void update_1ms(void);
    void on_cBoxDevice_currentIndexChanged(int index);

    void on_btnInitDevice_clicked();

    void on_btnDeviceMessage_clicked();

    void on_btnCloseDevice_clicked();

    void on_btnClear_clicked();

    void on_btnStartDevice_clicked();

    void on_btnResetDevice_clicked();

private:
    Ui::MainWindow *ui;

    int device_index_;
    int channel_index_;
    bool device_opend_=false;  //设备打开标志,more默认为false
    bool start_;  //CAN启动标志
    int net_mode_index_;
    int work_mode_index_;
    int abit_baud_index_;
    int dbit_baud_index_;
    int filter_mode_;
    int baud_index_;
    int suoYin_index;
    IProperty* property_;
    DEVICE_HANDLE device_handle_;
    CHANNEL_HANDLE channel_handle_;
    ZCAN_DEVICE_INFO* deviceInfo;

    bool SetBaudrate();  //设置波特率
    bool SetTransmitType();//发送方式
    QString char2String(UCHAR *p,uint8_t length);

};

#endif // MAINWINDOW_H
