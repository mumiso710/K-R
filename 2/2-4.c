#include <stdio.h>
#include <string.h>

void squeeze(char target[], char patterns[]);

int main() {
  char s1[] = "aiueo";
  char s2[] = "o";
  printf("before squeeze: %s\n", s1);
  squeeze(s1, s2);
  printf("patterns: %s\n", s2);
  printf("after squeeze: %s\n", s1);
}

void squeeze(char target[], char patterns[]) {
  int i, j, k;
  i = k = 0;

  int len = strlen(target);
  char temp_target[len + 1];
  strcpy(temp_target, target);

  while (temp_target[i] != '\0') {
    int in_patterns = 0;
    j = 0;
    while (patterns[j] != '\0') {
      if (temp_target[i] == patterns[j++]) {
        in_patterns = 1;
      }
    }
    if (!in_patterns) {
      target[k++] = temp_target[i];
    }
    i += 1;
  }
  target[k] = '\0';
}
