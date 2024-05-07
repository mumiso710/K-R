#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]) {
  double val, power;
  int i, sign;

  int exp_sign, exp_val;

  for (i = 0; isspace(s[i]); i++) {
    ;
  }

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') {
    i++;
  }
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
  }

  exp_sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  for (exp_val = 0.0; isdigit(s[i]); i++) {
    exp_val = 10.0 * exp_val + (s[i] - '0');
  }

  return sign * val / power * pow(10, exp_val * exp_sign);
}

int main() { printf("%f\n", atof("10.23E-2")); }
