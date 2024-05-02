#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, char s[], int b) {
  int i, sign;

  sign = n;

  i = 0;

  do {
    if (abs(n % b) >= 10) {
      s[i++] = abs(n % b) + 'A' - 10;
    } else {
      s[i++] = abs(n % b) + '0';
    }
  } while ((n /= b) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
int main() {
  char s[100];
  itob(15, s, 16);
  printf("%s\n", s);
}
