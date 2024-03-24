#pragma once

#define BIT_UTILS_VERSION "0.2.0"

#include <stdint.h>

/// Number of bits in a byte / char
#define BYTE_BITS 8

#ifdef __cplusplus
extern "C" {
#endif

/// @brief reverses the bit pattern of a byte
/// @param byte
/// @return reversed byte
uint8_t bitu_reverse_bits(uint8_t byte);

/// @brief converts given sequence of 8 bits into a byte
/// @param bits - array of bits.
/// @return byte with bits[0] as MSB, through bits[7] as LSB
uint8_t bitu_convert_bits_to_byte(const bool *bits);

/// @brief converts given sequence of bits into a sequence of bytes
///
/// byte[0] = byte with bits[0] as MSB, through bits[7] as LSB
/// byte[1] = byte with bits[8] as MSB, through bits[15] as LSB, and so on.
///
/// nbits must be integer multiple of 8 (so we get round number of bytes)
void bitu_convert_bits_to_bytes(size_t nbits, const bool *bits, uint8_t *bytes);

/// @brief expands a sequence of bytes to array of bits
void bitu_convert_bytes_to_bit_array(size_t nbytes, const uint8_t *bytes, bool *bits);

#ifdef __cplusplus
} // extern "C"
#endif

// Modern C declarations not supported by C++
#ifndef __cplusplus

uint8_t bitu_convert_bits_to_byte(const bool bits[static BYTE_BITS]);
void bitu_convert_bytes_to_bit_array(size_t nbytes, const uint8_t bytes[static nbytes], bool bits[nbytes * BYTE_BITS]);
void bitu_convert_bits_to_bytes(size_t nbits, const bool bits[static nbits], uint8_t bytes[static nbits / BYTE_BITS]);

#endif // Not C++

