#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>
#include <QtWidgets/QMessageBox>
#include <QRegExpValidator>


int device_index;
typedef struct _DeviceInfo
{
    UINT device_type;  //设备类型
    UINT channel_count;//设备的通道个数
}DeviceInfo;
static const DeviceInfo kDeviceType[] = {
    {ZCAN_USBCAN_2E_U, 2},
    {ZCAN_USBCAN1, 1},
    {ZCAN_USBCAN2, 2},
    {ZCAN_USBCAN_E_U, 1},
    {ZCAN_PCIE_CANFD_100U, 1},
    {ZCAN_PCIE_CANFD_200U, 2},
    {ZCAN_PCIE_CANFD_400U, 4},
    {ZCAN_USBCANFD_200U, 2},
    {ZCAN_USBCANFD_100U, 1},
    {ZCAN_USBCANFD_MINI, 1},
    {ZCAN_CANETTCP, 1},
    {ZCAN_CANETUDP, 1},
    {ZCAN_CLOUD, 1},
};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //显示默认设备的通道数
    ui->cBoxChannel->clear();//清除一次之前的数据
    device_index= ui->cBoxDevice->currentIndex();  //选择的设备
    ui->textBrowser->setText(QString::number(kDeviceType[device_index].channel_count ));
    for (int i=0;i<kDeviceType[device_index].channel_count;i++)
    {
        ui->cBoxChannel->addItem(QString::number(i));
    }

    /* 1ms 定时触发事件  start */
    QTimer *timer=new QTimer(this);
    timer->start(1);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_1ms()));
    update_1ms();
    /* 1ms 定时触发事件  end */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_1ms(void)  //每1ms需要更新的信息
{
    //
}

void MainWindow::on_btnOpenDevice_clicked()
{
    device_index= ui->cBoxDevice->currentIndex();       //选择的设备类型
    suoYin_index=ui->cBoxSuoYin->currentIndex();        //索引号
    device_handle_ = ZCAN_OpenDevice(kDeviceType[device_index].device_type, suoYin_index, 0);  //设备类型  索引号  保留
    if(INVALID_DEVICE_HANDLE == device_handle_)
    {
        qDebug()<<"打开设备失败!"<<endl;
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("打开设备失败!\r\n");
        return;
    }
    else
    {
        device_opend_=true;
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("打开设备成功!\r\n");
    }

}

void MainWindow::on_cBoxDevice_currentIndexChanged(int index)
{
//    device_index= ui->cBoxDevice->currentIndex();  //选择的设备
    ui->cBoxChannel->clear();//清除一次之前的数据
    for (int i=0;i<kDeviceType[index].channel_count;i++)
    {
        ui->cBoxChannel->addItem(QString::number(i));
    }
    ui->textBrowser->setText(QString::number(kDeviceType[device_index].channel_count ));
}

static const UINT kAbitTiming[] = {
    0x00018B2E,//1Mbps
    0x00018E3A,//800kbps
    0x0001975E,//500kbps
    0x0001AFBE,//250kbps
    0x0041AFBE,//125kbps
    0x0041BBEE,//100kbps
    0x00C1BBEE //50kbps
};
static const UINT kDbitTiming[] = {
    0x00010207,//5Mbps
    0x0001020A,//4Mbps
    0x0041020A,//2Mbps
    0x0081830E //1Mbps
};
static const BYTE kTiming0[] = {
    0x00,//1000kbps
    0x00,//800kbps
    0x00,//500kbps
    0x01,//250kbps
    0x03,//125kbps
    0x04,//100kbps
    0x09,//50kbps
    0x18,//20kbps
    0x31,//10kbps
    0xBF //5kbps
};
static const BYTE kTiming1[] = {
    0x14,//1000kbps
    0x16,//800kbps
    0x1C,//500kbps
    0x1C,//250kbps
    0x1C,//125kbps
    0x1C,//100kbps
    0x1C,//50kbps
    0x1C,//20kbps
    0x1C,//10kbps
    0xFF //5kbps
};
static const unsigned kBaudrate[] = {
    1000000,
    800000,
    500000,
    250000,
    125000,
    100000,
    50000,
    20000,
    10000,
    5000
};

void MainWindow::on_btnInitDevice_clicked()
{
    if(!device_opend_)
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("设备未打开！\r\n");
        return;
    }
    ZCAN_CHANNEL_INIT_CONFIG config;
    memset(&config,0,sizeof(config));
    UINT type=kDeviceType[device_index].device_type;
    const bool cloudDevice = type==ZCAN_CLOUD;
    const bool netDevice = type==ZCAN_CANETUDP || type==ZCAN_CANETTCP;
    const bool tcpDevice = type==ZCAN_CANETTCP;
    const bool server = net_mode_index_ == 0;
    const bool usbcanfd = type==ZCAN_USBCANFD_100U ||
        type==ZCAN_USBCANFD_200U || type==ZCAN_USBCANFD_MINI;
    const bool pciecanfd = type==ZCAN_PCIE_CANFD_100U ||
        type==ZCAN_PCIE_CANFD_200U || type==ZCAN_PCIE_CANFD_400U;
    const bool canfdDevice = usbcanfd || pciecanfd;
//    qDebug()<<type<<endl;
    property_ = GetIProperty(device_handle_);
    if (cloudDevice) //   cloud设备 不用
    {

    }
    else if (netDevice) //  网络设备 不用
    {

    }
    else
    {
        //设置波特率
        if (0)  //设置自定义波特率 不用
        {

        }
        else
        {
            if (!canfdDevice && !SetBaudrate())
            {
                ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
                ui->textBrowser->insertPlainText("设置波特率失败!\r\n");
                return;
            }
            ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
            ui->textBrowser->insertPlainText("设置波特率成功!\r\n");
        }
        if (pciecanfd)   //PCIE CAN 设备，不用。
        {
            //设置发送方式
            if (!SetTransmitType())
            {
                ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
                ui->textBrowser->insertPlainText("设置发送方式失败!\r\n");
                return;
            }
        }
        if (usbcanfd)    //USBCANFD 设备 不用。
        {
            IProperty* p = GetIProperty(device_handle_);
            channel_index_=ui->cBoxChannel->currentIndex();  //获取当前通道值
            QString str=QString::number(channel_index_,10);  //数字转字符串
            QString path_=str+"/canfd_standard";  //字符串拼接

            char *path;
            path=path_.toLatin1().data();  //字符串转char
            property_->SetValue(path, 0);
        }
        if (canfdDevice)  //USBFD 设备 不用。
        {
            work_mode_index_=ui->cBoxMode->currentIndex();
            filter_mode_=ui->cBoxLvbo->currentIndex();
            config.can_type = TYPE_CANFD;
            config.canfd.mode = work_mode_index_;
            config.canfd.abit_timing = kAbitTiming[abit_baud_index_];
            config.canfd.dbit_timing = kDbitTiming[dbit_baud_index_];
            config.canfd.filter = filter_mode_;
//            config.canfd.acc_code = _tcstoul(acc_code_, 0, 16);
//            config.canfd.acc_mask = _tcstoul(acc_mask_, 0, 16);
//            config.canfd.acc_code = acc_code_;
//            config.canfd.acc_mask = acc_mask_;
        }
        else
        {
            baud_index_=ui->cBoxBoud->currentIndex();
            work_mode_index_=ui->cBoxMode->currentIndex();
            config.can_type = TYPE_CAN;
            config.can.mode = work_mode_index_;
            config.can.timing0 = kTiming0[baud_index_];
            config.can.timing1 = kTiming1[baud_index_];
            config.can.filter = filter_mode_;
            config.can.acc_code = 0;
            config.can.acc_mask = 0xFFFFFFFF;
        }
    }
        channel_handle_ = ZCAN_InitCAN(device_handle_, channel_index_, &config);
        if (INVALID_CHANNEL_HANDLE == channel_handle_)
        {
            ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
            ui->textBrowser->insertPlainText("初始化CAN失败!\r\n");
            return;
        }
        else
        {
            ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
            ui->textBrowser->insertPlainText("初始化CAN成功!\r\n");
        }
}

void MainWindow::on_btnDeviceMessage_clicked()
{
    UINT status=ZCAN_GetDeviceInf(device_handle_,deviceInfo);
    QString hw_ver;
    QString fw_ver;
    QString dr_ver;
    QString in_ver;
    QString irq_num;
    QString can_num;
    QString str_SN;  //811309160285\000\000\000\000\000\000\000\000
    QString str_hw_type;
    QString disp_text;

    if(STATUS_OK==status)
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("读取设备信息成功!\r\n");


        hw_ver=(QByteArray::number(deviceInfo->hw_Version,16));
        fw_ver=(QByteArray::number(deviceInfo->fw_Version,16));
        dr_ver=(QByteArray::number(deviceInfo->dr_Version,16));
        in_ver=(QByteArray::number(deviceInfo->in_Version,16));
        irq_num=(QByteArray::number(deviceInfo->irq_Num,16));
        can_num=(QByteArray::number(deviceInfo->can_Num,16));
        str_SN=char2String(deviceInfo->str_Serial_Num,20);
        str_hw_type=char2String(deviceInfo->str_hw_Type,40);

        hw_ver="硬件版本号：V"+hw_ver+"\r\n";
        fw_ver="固件版本号：V"+fw_ver+"\r\n";
        dr_ver="驱动程序版本号：V"+dr_ver+"\r\n";
        in_ver="接口库版本号：V"+in_ver+"\r\n";
        irq_num="板卡所用中断号："+irq_num+"\r\n";
        can_num="共有CAN路数："+can_num+"\r\n";
        str_SN="板卡序列号："+str_SN+"\r\n";
        str_hw_type="硬件类型："+str_hw_type+"\r\n";
        disp_text="\r\n\r\n"+hw_ver+fw_ver+dr_ver+in_ver+irq_num+can_num+str_SN+str_hw_type;
        QMessageBox::information(NULL,QString("板卡信息"),disp_text);
    }
    else
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("读取设备信息失败!\r\n");
        return;
    }

}
bool MainWindow::SetBaudrate()  //设备波特率
{
    //通道号
    channel_index_=ui->cBoxChannel->currentIndex();  //获取当通道号
    QString str=QString::number(channel_index_,10);  //数字转字符串
    QString path_=str+"/canfd_standard";  //字符串拼接
    char *path;
    path=path_.toLatin1().data();  //字符串转char

    //波特率
    baud_index_=ui->cBoxBoud->currentIndex();
    int temp=kBaudrate[baud_index_];
    QString str2=QString::number(temp,10);
    char *value;
    value=str2.toLatin1().data();
    property_->SetValue(path, value);
    qDebug()<<path_<<endl;
    qDebug()<<value<<endl;
}
bool MainWindow::SetTransmitType()
{
    //

}

void MainWindow::on_btnCloseDevice_clicked()  //关闭设备
{
    bool status;
    status=ZCAN_CloseDevice(device_handle_);
    if(STATUS_OK == status)  //设备关闭成功
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("设备关闭成功!\r\n");
    }
    else        //设备关闭失败
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("设备关闭失败!\r\n");
    }
}
QString MainWindow::char2String(UCHAR *p,uint8_t length)
{
    uint8_t i;
    QString str;
    for(i=0;i<length;i++)
    {
        str+=QString((*(p++)));
    }
    return str;
}

void MainWindow::on_btnClear_clicked()  //清除显示窗口的内容
{
    ui->textBrowser->setText("");
}

void MainWindow::on_btnStartDevice_clicked()
{
    if (ZCAN_StartCAN(channel_handle_) != STATUS_OK)
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("启动CAN失败!\r\n");
        return;
    }
    else
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("启动CAN成功!\r\n");
    }
    start_ = true;
}

void MainWindow::on_btnResetDevice_clicked()
{
    if (ZCAN_ResetCAN(channel_handle_) != STATUS_OK)
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("复位CAN失败!\r\n");
        return;
    }
    else
    {
        ui->textBrowser->moveCursor(QTextCursor::Start);  //显示内容在第一行显示。
        ui->textBrowser->insertPlainText("复位CAN成功!\r\n");
    }
    start_ = false;
}
