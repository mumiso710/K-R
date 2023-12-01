#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("line: %s\n", line);

        reverse(line);

        printf("reversed: %s\n", line);
    }

    return 0;
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[]) {
    int len;

    len = 0;

    for (int i = 0; i < MAXLINE && s[i] != '\0'; i++) {
        len += 1;
    }

    for (int i = 0; i < len / 2; i++) {
        int temp = s[i];
        s[i] = s[(len - 1) - i];
        s[(len - 1) - i] = temp;
    }
}