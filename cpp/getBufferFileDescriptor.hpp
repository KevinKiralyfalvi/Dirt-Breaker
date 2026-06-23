#pragma once
#include <cstdint>
#include <fcntl.h>
#include <linux/fb.h>
#include <opencv2/videoio.hpp>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

uint8_t *writeFrame(const std::array<std::array<uint16_t, 320>, 240> frame, const int bufferID);
