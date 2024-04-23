#include <stdio.h>

int main() {
  int i;
  int lim;
  int c;

  for (i = 0; i < lim - 1; ++i) {
    c = getchar();
    if (c == '\n') {
      break;
    }

    if (c == EOF) {
      break;
    }
  }
}
