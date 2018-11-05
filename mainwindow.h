/*
 *  Copyright (c) 2018 ARDev1161 <radtarasov@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#undef main
#include "pch.h"

#define NO_PICTURE "./data/images/no_picture.jpeg"
#define SOURCE_STREAM 0
//#define SOURCE_STREAM "udpsrc port=1488 ! application/x-rtp, encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! appsink"

using namespace cv;
using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;

    QTimer *tmrTimer;
    QString *hostName;

    VideoCapture capture;
    Mat sourceMat;
    Mat outputMat;

    Control *zanyaControl;
    Sensors *zanyaSensors;
    Logic *zanyaLogic;

    CamSettingsHolder *camHolder;

    JoystickDialog *joystickDialog;
    JoystickIdHolder *idHolder;

    Joystick *joyThread;
    TCP *tcpThread;

    int LoopTime=50;

signals:
    void timeout();

private slots:
    void calibDialogOpen();
    void frameUpdate();
    void menuJoystick();
    void fetchJoystickId();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void startCap();
    void startTimer();
    void worker();
    void outMat(Mat &toOut);
    void connMenu();
    void undistortMat(Mat &inMat, Mat &outMat);
    void initFields();

};

#endif // MAINWINDOW_H
