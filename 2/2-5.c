#include <stdio.h>
#include <string.h>

int any(char target[], char patterns[]);

int main() {
  char s1[] = "aiueo";
  char s2[] = "o";
  printf("target: %s\n", s1);
  printf("patterns: %s\n", s2);
  printf("pos: %d\n", any(s1, s2));
}

int any(char target[], char patterns[]) {
  int i, j;
  i = 0;
  while (target[i] != '\0') {
    j = 0;
    while (patterns[j] != '\0') {
      if (target[i] == patterns[j++]) {
        return i + 1;
      }
    }
    i += 1;
  }
  return -1;
}
