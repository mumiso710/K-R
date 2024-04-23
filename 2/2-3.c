#include <math.h>
#include <stdio.h>
#include <string.h>

int htoi(char[]);

int main() {
  char hex[] = "0x3A";
  int converted = htoi(hex);
  printf("%d\n", converted);
}

int htoi(char s[]) {
  int len = strlen(s);
  int num = 0;
  int counter = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == 'x' || s[i] == 'X') {
      break;
    }

    if (s[i] >= 'A' && s[i] <= 'F') {
      num += pow(16, counter) * (s[i] - 'A' + 10);
    } else {
      num += pow(16, counter) * (s[i] - '0');
    }
    counter += 1;
  }
  return num;
}
