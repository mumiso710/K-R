#include<stdio.h>

int main() {
    int c, prev;

    prev = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && prev == ' ') {
            ;
        } else {
            printf("%c", c);
        }
        prev = c;
    }
}