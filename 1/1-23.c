#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, string_state, comment_state;

  string_state = comment_state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == '"' && string_state == OUT) {
      string_state = IN;
    } else if (c == '"' && string_state == IN) {
      string_state = OUT;
    }

    if (c == '/' && string_state == OUT && comment_state == OUT) {
      int nextc = getchar();
      if (nextc == EOF) {
        break;
      }
      if (nextc == '*') {
        comment_state = IN;
      } else {
        putchar(c);
        putchar(nextc);
      }
    }

    if (c == '*' && string_state == OUT && comment_state == OUT) {
      putchar('*');
    }

    if (c == '*' && string_state == OUT && comment_state == IN) {
      int nextc = getchar();
      if (nextc == EOF) {
        break;
      }
      if (nextc == '/') {
        comment_state = OUT;
      }
    }

    if (c != '/' && c != '*' && comment_state == OUT || string_state == IN) {
      putchar(c);
    }
  }
  return 0;
}
