#include "camLoop.hpp"
#include "convert888MatrixTo565Array.hpp"
#include "getDevicePath.hpp"
#include "getVideoDevices.hpp"
#include "scale565MatrixTo565Array.hpp"
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <thread>

const std::string videoDevices = getVideoDevices();

int main()
{
    cv::VideoCapture driveCamera;
    cv::VideoCapture gunCamera;
    cv::Mat driveFrame;
    cv::Mat gunFrame;
    bool gotDrive;
    bool gotGun;
    //  cv::VideoCapture thermalCamera;

    driveCamera.open(getDevicePath(videoDevices, "046d:0825"), cv::CAP_V4L2);
    driveCamera.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
    driveCamera.set(cv::CAP_PROP_FRAME_HEIGHT, 320);
    driveCamera.set(cv::CAP_PROP_BRIGHTNESS, 64);
    driveCamera.set(cv::CAP_PROP_CONTRAST, 32);
    driveCamera.set(cv::CAP_PROP_SATURATION, 80);
    driveCamera.set(cv::CAP_PROP_GAIN, 0);
    driveCamera.set(cv::CAP_PROP_SHARPNESS, 6);
    driveCamera.set(cv::CAP_PROP_BACKLIGHT, 12);
    driveCamera.set(cv::CAP_PROP_BUFFERSIZE, 1);

    gunCamera.open(getDevicePath(videoDevices, "HD USB Camera"), cv::CAP_V4L2);
    gunCamera.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
    gunCamera.set(cv::CAP_PROP_FRAME_HEIGHT, 320);
    gunCamera.set(cv::CAP_PROP_BRIGHTNESS, 64);
    gunCamera.set(cv::CAP_PROP_CONTRAST, 32);
    gunCamera.set(cv::CAP_PROP_SATURATION, 80);
    gunCamera.set(cv::CAP_PROP_GAIN, 0);
    gunCamera.set(cv::CAP_PROP_SHARPNESS, 6);
    gunCamera.set(cv::CAP_PROP_BACKLIGHT, 12);
    gunCamera.set(cv::CAP_PROP_BUFFERSIZE, 1);
    // thermalCamera.open(getDeviceID(videoDevices, "fw:v1.3.0"));

    std::thread driveThread(driveCamLoop, driveCamera);
    std::thread gunThread(gunCamLoop, gunCamera);

    // Keep the main thread alive
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
