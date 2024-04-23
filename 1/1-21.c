#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int entab(char line[], int maxline);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = entab(line, MAXLINE)) > 0) {
    printf("%s\n", line);
  }
  return 0;
}

int entab(char s[], int lim) {
  int c, i;

  int space_counter = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == ' ') {
      space_counter += 1;
      s[i] = c;
      if (space_counter == TABSTOP) {
        i -= TABSTOP - 1;
        s[i] = '\t';
        space_counter = 0;
      }
    } else {
      s[i] = c;
      space_counter = 0;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
