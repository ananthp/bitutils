#include <stdio.h>
#include <assert.h>

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

int main(void)
{
    test_bitu_reverse_bits();
    printf("bitutils tests passed\n");
}
