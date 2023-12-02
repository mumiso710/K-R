#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int detab(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = detab(line, MAXLINE)) > 0) {
        printf("line: %s\n", line);
    }
    return 0;
}

int detab(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == '\t') {
            int space_nums = TABSTOP - (i % TABSTOP);
            for (int j = 0; j < space_nums && (j + i) < lim - 1; ++j) {
                s[i] = ' ';
                if (j != space_nums - 1) {
                    ++i;
                }
            }
        } else {
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}