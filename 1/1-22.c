#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void print_fold(char line[], int len, int letter_per_line);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        print_fold(line, len, 10);
    }
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void print_fold(char s[], int len, int n) {
    for (int i = 0; i < len; i += n) {
        for (int j = 0; j < n && (i + j) < len; j++) {
            putchar(s[i + j]);
        }
        printf("\n");
    }
}