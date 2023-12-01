#include <stdio.h>

int main() {
    int c;
    int letters_counter[26];

    for (int i = 0; i < 26; i++) {
        letters_counter[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        letters_counter[c - 'a'] += 1;
    }

    int letter_num = 0;

    for (int i = 0; i < 26; i++) {
        if (letters_counter[i] != 0) {
            letter_num += 1;
        }
    }

    printf("%d\n", letter_num);
}