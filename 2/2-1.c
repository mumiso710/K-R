#include <limits.h>
#include <stdio.h>

int main() {
  printf("CHAR_MIN:   %20d\n", CHAR_MIN);
  printf("CHAR_MAX:   %20d\n", CHAR_MAX);
  printf("UCHAR_MAX:  %20d\n", UCHAR_MAX);
  printf("SHRT_MIN:   %20d\n", SHRT_MIN);
  printf("SHRT_MAX:   %20d\n", SHRT_MAX);
  printf("USHRT_MAX:  %20d\n", USHRT_MAX);
  printf("INT_MIN:    %20d\n", INT_MIN);
  printf("INT_MAX:    %20d\n", INT_MAX);
  printf("UINT_MAX:   %20u\n", UINT_MAX);
  printf("LONG_MIN:   %20ld\n", LONG_MIN);
  printf("LONG_MAX:   %20ld\n", LONG_MAX);
  printf("ULONG_MAX:  %20lu\n", ULONG_MAX);

  printf("--------------------------------\n");

  printf("CHAR_MIN:   %20d\n", ~((1 << sizeof(char) * 8 - 1) - 1));
  printf("CHAR_MAX:   %20d\n", (1 << sizeof(char) * 8 - 1) - 1);
  printf("UCHAR_MAX:  %20u\n", ((unsigned)1 << sizeof(char) * 8) - 1);
  printf("SHRT_MIN:   %20d\n", ~((1 << sizeof(short) * 8 - 1) - 1));
  printf("SHRT_MAX:   %20d\n", (1 << sizeof(short) * 8 - 1) - 1);
  printf("USHRT_MAX:  %20u\n",
         ((unsigned short)1 << sizeof(unsigned short) * 8) - 1);
  printf("INT_MIN:    %20d\n", ~((1 << sizeof(int) * 8 - 1) - 1));
  printf("INT_MAX:    %20ld\n", ((long)1 << sizeof(int) * 8 - 1) - 1);
  printf("UINT_MAX:   %20u\n", ((unsigned)1 << sizeof(unsigned int) * 8) - 1);
  printf("LONG_MIN:   %20ld\n", ~(((long)1 << sizeof(long) * 8 - 1) - 1));
  printf("LONG_MAX:   %20lld\n", ((long long)1 << sizeof(long) * 8 - 1) - 1);
  printf("ULONG_MAX:  %20lu\n",
         ((unsigned long)1 << sizeof(unsigned long) * 8) - 1);
}
