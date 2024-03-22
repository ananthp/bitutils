#pragma once

#define BIT_UTILS_VERSION "0.1.0"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @brief reverses the bit pattern of a byte
/// @param byte
/// @return reversed byte
uint8_t bitu_reverse_bits(uint8_t byte);

#ifdef __cplusplus
} // extern "C"
#endif
