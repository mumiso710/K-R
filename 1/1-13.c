#include <stdio.h>

int main() {
    int c, length;
    int word_length[10];

    for (int i = 0; i < 10; i++) {
        word_length[i] = 0;
    }

    length = 0;
    while ((c = getchar()) != EOF) {
        length += 1;
        if (c == '\n' || c == ' ' || c == '\t') {
            word_length[length - 1] += 1;
            length = 0;
        }
    }

    for (int i = 1; i < 10; i++) {
        printf("%d", i);
        for (int j = 0; j < word_length[i]; j++) {
            printf("-");
        }
        printf("\n");
    }
}
