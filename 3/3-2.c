#include <stdio.h>

void escape(char s[], char t[]) {
  int j = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    switch (s[i]) {
    case '\n':
      t[j] = '\\';
      j++;
      t[j] = 'n';
      j++;
      break;
    case '\t':
      t[j] = '\\';
      j++;
      t[j] = 't';
      j++;
      break;
    default:
      t[j] = s[i];
      j++;
      break;
    }
  }
  t[j] = '\0';
}

int main() {
  char s[] = "hello, world\n";
  char t[100];
  escape(s, t);
  printf("%s", t);
}
