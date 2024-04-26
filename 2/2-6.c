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

int main(void) {
  int x = 10;
  int y = 31;

  printb(x);
  printb(y);

  printb(setbits(x, 3, 4, y));
}
