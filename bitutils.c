#include "bitutils.h"

uint8_t bitu_reverse_bits(uint8_t byte)
{
    // Adapted from "Bit Twiddling Hacks" by Sean Eron Anderson
    // https://web.archive.org/web/20200601123740/https://graphics.stanford.edu/~seander/bithacks.html
    uint8_t reversed = (byte * 0x0202020202ULL & 0x010884422010ULL) % 1023;
    return reversed;
}
