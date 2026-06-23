#include "convert888MatrixTo565Array.hpp"
#include "getBufferFileDescriptor.hpp"
#include "writeFrame.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

void driveCamLoop(cv::VideoCapture &driveCamera);
void gunCamLoop(cv::VideoCapture &gunCamera);
