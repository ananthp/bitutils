#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h> // size_t

#include "bitutils.h"

uint8_t bitu_reverse_bits(uint8_t byte)
{
    // Adapted from "Bit Twiddling Hacks" by Sean Eron Anderson
    // https://web.archive.org/web/20200601123740/https://graphics.stanford.edu/~seander/bithacks.html
    uint8_t reversed = (byte * 0x0202020202ULL & 0x010884422010ULL) % 1023;
    return reversed;
}

uint8_t bitu_convert_bits_to_byte(const bool bits[static BYTE_BITS])
{
    uint8_t byte = 0;
    for (size_t i = 0; i < BYTE_BITS; i++) {
        byte <<= 1;
        byte |= bits[i];
    }

    return byte;
}

void bitu_convert_bits_to_bytes(size_t nbits, const bool bits[static nbits], uint8_t bytes[nbits / BYTE_BITS])
{
    // if number of bits do not correspond to integer number of bytes,
    // then we don't know what to do with the extra bits.
    assert((nbits % 8) == 0);

    int bytePos = 0;
    for (size_t i = 0; i < nbits; i += 8) {
        bytes[bytePos++] = bitu_convert_bits_to_byte(&bits[i]);
    }
}

void bitu_convert_bytes_to_bit_array(size_t nbytes, const uint8_t bytes[static nbytes], bool bits[nbytes * BYTE_BITS])
{
    const int MSB_BIT_MASK = 128;
    assert(MSB_BIT_MASK == 0b10000000);

    for (size_t byteIdx = 0; byteIdx < nbytes; ++byteIdx) {
        uint8_t byte = bytes[byteIdx];
        // extract bits from MSB to LSB
        for (size_t i = 0; i < 8; ++i) {
            bool bit = (byte << i) & MSB_BIT_MASK;
            bits[(byteIdx * 8) + i] = bit;
        }
    }
}
