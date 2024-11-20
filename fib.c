#include <stdio.h>
#include <stdlib.h>
#define MEMO_ARRAY_SIZE 10000

unsigned long long int memo_array[MEMO_ARRAY_SIZE];

unsigned long long int fib_i_core(int f_index) {
  if (f_index == 1) {
    return 0;
  } else if (f_index == 2) {
    return 1;
  }

  unsigned long long int first = 0;
  unsigned long long int second = 1;
  unsigned long long int next_value;

  for (int ix = 3; ix <= f_index; ix++) {
    next_value = first + second;
    first = second;
    second = next_value;
  }
  return second;
}

unsigned long long int fib_r_core(int r_index) {
  if (r_index == 1) {
    return 0;
  } else if (r_index == 2) {
    return 1;
  } else {
    return fib_r_core(r_index - 1) + fib_r_core(r_index - 2);
  }
}

unsigned long long int FibIterative(int fib_i) {
  if (memo_array[fib_i] != 0) {
    return memo_array[fib_i];
  }
  if (fib_i <= 1) {
    return 0;
  } else if (fib_i == 2) {
    return 1;
  }
  memo_array[fib_i] = fib_i_core(fib_i);
  return memo_array[fib_i];
}

unsigned long long int FibRecursive(int rec_i) {
  if (memo_array[rec_i] != 0) {
    return memo_array[rec_i];
  }
  if (rec_i <= 1) {
    return 0;
  } else if (rec_i == 2) {
    return 1;
  }
  memo_array[rec_i] = fib_r_core(rec_i);
  return memo_array[rec_i];
}

int main(int argc, char *argv[]) {
  int user_int = atoi(argv[1]);

  if (argv[2][0] == 'i') {
    unsigned long long int result = FibIterative(user_int);
    printf("%llu", result);
  } else if (argv[2][0] == 'r') {
    unsigned long long int result = FibRecursive(user_int);
    printf("%llu", result);
  }
  return 0;
}