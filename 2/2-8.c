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

unsigned rightrot(unsigned x, int n) {
  unsigned rotted = x;
  for (int i = 0; i < n; i++) {
    unsigned right_bit = rotted & 1;
    right_bit = right_bit << 31;
    rotted = rotted >> 1;
    rotted = rotted | right_bit;
  }
  return rotted;
}

int main(void) {
  int x = 10;

  printb(x);

  printb(rightrot(x, 1));
  printb(rightrot(x, 2));
  printb(rightrot(x, 3));
  printb(rightrot(x, 4));
}
