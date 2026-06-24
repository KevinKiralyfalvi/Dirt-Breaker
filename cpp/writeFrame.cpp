// Kevin Kiralyfalvi
// writeFrame
// November 27, 2025

#include "writeFrame.hpp"

constexpr int FRAMEBUFFER_BYTES = 320 * 240 * sizeof(uint16_t);

void writeFrame(const std::array<std::array<uint16_t, 320>, 240> &frame, uint8_t *buffer)
{
    // Loop through every row
    memcpy(buffer, frame.data(), FRAMEBUFFER_BYTES);
}
