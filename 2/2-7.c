#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

unsigned invert(unsigned x, int p, int n) {
    return setbits(x, p, n, ~x >> (p - n));
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    y = ~(~0 << n) & y;
    y = y << (p - n);
    x = x & ~((~(~0 << n)) << (p - n));
    return x | y;
}