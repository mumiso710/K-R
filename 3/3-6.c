#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_len(int n) {

  int len = 0;
  do {
    len++;
  } while (n /= 10);
  return len;
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int width) {
  int i, sign;

  int len = int_len(n);

  sign = n;

  i = 0;

  do {
    s[i++] = abs(n % 10) + '0';
  } while (abs(n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
    len++;
  }

  while (len < width) {
    s[i++] = ' ';
    width--;
  }

  s[i] = '\0';
  reverse(s);
}
int main() {
  char s[100];
  itoa(-100, s, 10);
  printf("%s\n", s);
}
