#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, string_state, comment_state;

  // if c == left brackets add 1 and c == right brackets sub1
  int round_counter, square_counter, curly_counter;
  round_counter = square_counter = curly_counter = 0;

  string_state = comment_state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == '"' && string_state == OUT) {
      string_state = IN;
    } else if (c == '"' && string_state == IN) {
      string_state = OUT;
    }

    // /* pattern
    if (c == '/' && string_state == OUT && comment_state == OUT) {
      int nextc = getchar();
      if (nextc == EOF) {
        break;
      }
      if (nextc == '*') {
        comment_state = IN;
      } else if (nextc == '(') {
        round_counter += 1;
      } else if (nextc == '[') {
        square_counter += 1;
      } else if (nextc == '{') {
        curly_counter += 1;
      } else if (nextc == ')') {
        round_counter -= 1;
      } else if (nextc == ']') {
        square_counter -= 1;
      } else if (nextc == '}') {
        curly_counter -= 1;
      }
    }

    // */ pattern
    if (c == '*' && string_state == OUT && comment_state == IN) {
      int nextc = getchar();
      if (nextc == EOF) {
        break;
      }
      if (nextc == '/') {
        comment_state = OUT;
      } else if (nextc == '(') {
        round_counter += 1;
      } else if (nextc == '[') {
        square_counter += 1;
      } else if (nextc == '{') {
        curly_counter += 1;
      } else if (nextc == ')') {
        round_counter -= 1;
      } else if (nextc == ']') {
        square_counter -= 1;
      } else if (nextc == '}') {
        curly_counter -= 1;
      }
    }

    if (!(string_state == IN || comment_state == IN)) {
      if (c == '(') {
        round_counter += 1;
      } else if (c == '[') {
        square_counter += 1;
      } else if (c == '{') {
        curly_counter += 1;
      } else if (c == ')') {
        round_counter -= 1;
      } else if (c == ']') {
        square_counter -= 1;
      } else if (c == '}') {
        curly_counter -= 1;
      }
    }

    putchar(c);
  }

  if (round_counter != 0) {
    printf("rounder_brackets is invalid\n");
  } else if (square_counter != 0) {
    printf("square_brackets is invalid\n");
  } else if (curly_counter != 0) {
    printf("curly_brackets is invalid\n");
  } else {
    printf("the program is valid\n");
  }
}
