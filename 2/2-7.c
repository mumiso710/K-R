#include <stdio.h>

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * 8 - 1);
  do
    putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
  printf("\n");
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return (y & (~0 << n)) | (getbits(x, p, n) & ~0);
}

unsigned invert(unsigned x, int p, int n) { return (x ^ setbits(~0, p, n, 0)); }

int main(void) {
  int x = 10;

  printb(x);

  printb(invert(x, 3, 4));
}
