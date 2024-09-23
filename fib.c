#include <stdio.h>
#include <stdlib.h>
#define MEMO_ARRAY_SIZE 10000

unsigned long long int memo_array[MEMO_ARRAY_SIZE];

typedef unsigned long long int (*FibFunc)(int);

unsigned long long int fib_i_core(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  }

  unsigned long long int first = 0;
  unsigned long long int second = 1;
  unsigned long long int next_value;

  for (int ix = 3; ix <= n; ix++) {
    next_value = first + second;
    first = second;
    second = next_value;
  }
  return second;
}

unsigned long long int fib_r_core(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return fib_r_core(n - 1) + fib_r_core(n - 2);
  }
}

unsigned long long int FibMemo(int n, FibFunc chosenFib) {
  if (memo_array[n] != 0) {
    return memo_array[n];
  }
  if (n <= 1) {
    return 0;
  } else if (n == 2) {
    return 0;
  }
  memo_array[n] = chosenFib(n);
  return memo_array[n];
}

int main(int argc, char *argv[]) {
  int user_int = atoi(argv[1]);
  FibFunc chosenFunc;
  unsigned long long int result;

  if (argv[2][0] == 'i') {
    chosenFunc = fib_i_core;
  } else if (argv[2][0] = 'r') {
    chosenFunc = fib_r_core;
  }
  result = FibMemo(user_int, chosenFunc);
  printf("%llu", result);

  return 0;
}