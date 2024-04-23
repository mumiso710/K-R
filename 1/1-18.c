#include <stdio.h>
#define MAXLINE 1000

int get_line_without_white_space(char line[], int maxline);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line_without_white_space(line, MAXLINE)) > 0) {
    printf("line length: %d\n", len);

    if (len > 0) {
      printf("line: %s", line);
    }
  }
  return 0;
}
int get_line_without_white_space(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c != ' ' && c != '\t') {
      s[i] = c;
    }

    if (c == ' ' || c == '\t') {
      --i;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
