// Kevin Kiralyfalvi
// Gun Camera Loop
// March 19th, 2025

#include "camLoop.hpp"

int gunCamLoop(cv::VideoCapture gunCamera)
{
    cv::Mat frame;
    while (true)
    {
        if (gunCamera.read(frame))
        {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
            writeFrame(convert888MatrixTo565Array(frame), 1);
        }
        else
            continue;
        // std::cout << "Error! Did not find gun frame!";
    }
}
