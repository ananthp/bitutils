#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "bitutils.h"

static void test_bitu_reverse_bits(void)
{
    assert(0 == bitu_reverse_bits(0));

    assert(0b10000000 == bitu_reverse_bits(0b00000001));
    assert(0b01000000 == bitu_reverse_bits(0b00000010));
    assert(0b00100000 == bitu_reverse_bits(0b00000100));
    assert(0b00010000 == bitu_reverse_bits(0b00001000));
    assert(0b00001000 == bitu_reverse_bits(0b00010000));
    assert(0b00000100 == bitu_reverse_bits(0b00100000));
    assert(0b00000010 == bitu_reverse_bits(0b01000000));
    assert(0b00000001 == bitu_reverse_bits(0b10000000));

    assert(0b10101010 == bitu_reverse_bits(0b01010101));
    assert(0b10110111 == bitu_reverse_bits(0b11101101));
}

void test_bitu_convert_bytes_to_bit_array(void)
{
    // Test case 1: simple sequence, multiple bytes
    {
        uint8_t bytes[4]    = { 1, 2, 3, 4 };
        bool    bits[4 * 8] = { 0 };
        bitu_convert_bytes_to_bit_array(4, bytes, bits);

        assert(bits[0] == 0);
        assert(bits[1] == 0);
        assert(bits[2] == 0);
        assert(bits[3] == 0);
        assert(bits[4] == 0);
        assert(bits[5] == 0);
        assert(bits[6] == 0);
        assert(bits[7] == 1);

        assert(bits[8 + 0] == 0);
        assert(bits[8 + 1] == 0);
        assert(bits[8 + 2] == 0);
        assert(bits[8 + 3] == 0);
        assert(bits[8 + 4] == 0);
        assert(bits[8 + 5] == 0);
        assert(bits[8 + 6] == 1);
        assert(bits[8 + 7] == 0);

        assert(bits[16 + 0] == 0);
        assert(bits[16 + 1] == 0);
        assert(bits[16 + 2] == 0);
        assert(bits[16 + 3] == 0);
        assert(bits[16 + 4] == 0);
        assert(bits[16 + 5] == 0);
        assert(bits[16 + 6] == 1);
        assert(bits[16 + 7] == 1);

        assert(bits[24 + 0] == 0);
        assert(bits[24 + 1] == 0);
        assert(bits[24 + 2] == 0);
        assert(bits[24 + 3] == 0);
        assert(bits[24 + 4] == 0);
        assert(bits[24 + 5] == 1);
        assert(bits[24 + 6] == 0);
        assert(bits[24 + 7] == 0);
    }
}

void test_convert_bits_to_byte(void)
{
    const bool b0[8] = { 0 };
    assert(0b00000000 == bitu_convert_bits_to_byte(b0));

    const bool b10000000[8] = { 1, 0, 0, 0, 0, 0, 0, 0 };
    const bool b01000000[8] = { 0, 1, 0, 0, 0, 0, 0, 0 };
    const bool b00100000[8] = { 0, 0, 1, 0, 0, 0, 0, 0 };
    const bool b00010000[8] = { 0, 0, 0, 1, 0, 0, 0, 0 };
    const bool b00001000[8] = { 0, 0, 0, 0, 1, 0, 0, 0 };
    const bool b00000100[8] = { 0, 0, 0, 0, 0, 1, 0, 0 };
    const bool b00000010[8] = { 0, 0, 0, 0, 0, 0, 1, 0 };
    const bool b00000001[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };

    assert(0b00000001 == bitu_convert_bits_to_byte(b00000001));
    assert(0b00000010 == bitu_convert_bits_to_byte(b00000010));
    assert(0b00000100 == bitu_convert_bits_to_byte(b00000100));
    assert(0b00001000 == bitu_convert_bits_to_byte(b00001000));
    assert(0b00010000 == bitu_convert_bits_to_byte(b00010000));
    assert(0b00100000 == bitu_convert_bits_to_byte(b00100000));
    assert(0b01000000 == bitu_convert_bits_to_byte(b01000000));
    assert(0b10000000 == bitu_convert_bits_to_byte(b10000000));

    // expect a compiler warning/error
    const bool fewerBits[7]          = { 1, 1, 1, 0, 0, 0, 1 };
    uint8_t    expectCompilerWarning = bitu_convert_bits_to_byte(fewerBits);
    (void) expectCompilerWarning;
}

int main(void)
{
#if defined(NDEBUG)
    fprintf(stderr, "ERROR: NDEBUG defined. No point in running tests since assert() is noop.\n");
    fprintf(stderr, "ERROR: To run tests, rebuild in release mode.\n");
    return -1;
#else
    test_bitu_reverse_bits();
    test_bitu_convert_bytes_to_bit_array();
    test_convert_bits_to_byte();
    printf("bitutils tests passed\n");
#endif
}
