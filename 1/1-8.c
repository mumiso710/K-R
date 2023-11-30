#include<stdio.h>

int main() {

    int c;
    int blank, tab, nl;
    
    blank = 0;
    tab = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blank += 1;
        }

        if (c == '\t') {
            tab += 1;
        }

        if (c == '\n') {
            nl += 1;
        }
    }

    printf("blank: %d, tab: %d, new_line: %d", blank, tab, nl);
}