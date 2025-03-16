#include "sum-nbo.h"

void print_hex(uint32_t value)
{
    int byte_size = 0;

    if (value <= 0xFF)
        byte_size = 2;
    else if (value <= 0xFFFF)
        byte_size = 4;
    else if (value <= 0xFFFFFF)
        byte_size = 6;
    else
        byte_size = 8;

    printf("(0x%0*x) ", byte_size, value);
}

void print_dec(uint32_t value)
{
    printf("%u", value);
}

void print_plus()
{
    printf("+ ");
}

void print_equal()
{
    printf("= ");
}