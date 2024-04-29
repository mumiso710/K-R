#include <stdio.h>

void expand(char s1[], char s2[]) {
  int j = 0;
  for (int i = 0; s1[i] != '\0'; i++) {
    if (s1[i] == '-' && i != 0 && s1[i + 1] != '\0') {
      for (char c = s1[i - 1] + 1; c < s1[i + 1]; c++) {
        s2[j] = c;
        j++;
      }
    } else {
      s2[j] = s1[i];
      j++;
    }
  }
}
int main() {
  char s1[] = "-f-r0-9";
  char s2[100];

  expand(s1, s2);

  printf("%s\n", s2);
}
