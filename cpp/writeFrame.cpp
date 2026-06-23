// Kevin Kiralyfalvi
// writeFrame
// November 27, 2025

#include "writeFrame.hpp"

constexpr int BYTES_PER_ROW = 320 * sizeof(uint16_t);
constexpr int HEIGHT = 240;

void writeFrame(const std::array<std::array<uint16_t, 320>, 240> &frame, uint8_t *buffer, uint32_t line_length)
{
    // Loop through every row
    for (int y = 0; y < HEIGHT; y++)
    {
        // Shift the output buffer down each row
        // Expose the internal data for the frame array, and shift it down each row
        // The rows may be different sizes because of padding
        memcpy(buffer + y * line_length, frame[y].data(), BYTES_PER_ROW);
    }
}
