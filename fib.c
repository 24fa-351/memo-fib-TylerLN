#include <stdio.h>
#include <stdlib.h>


unsigned long long int memo_array[100];


unsigned long long int fib_i_wrapper(int n) {
   if (memo_array[n] != 0) {
      return memo_array[n];
   }
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   unsigned long long int first = 0, second = 1, next_value;
   for (int i = 3; i <= n; i++) {
      next_value = first + second;
      first = second;
      second = next_value;
   }
   memo_array[n] = second;
   return second;
}


unsigned long long int fib_r_wrapper(int n) {
   if (memo_array[n] != 0) {
      return memo_array[n];
   }
   if(n == 1){
      return 0;
   } else if (n == 2) {
      return 1;
   }
   memo_array[n] = fib_r_wrapper(n-1) + fib_r_wrapper(n-2);
   return memo_array[n];
}


unsigned long long int FibIterative(int n) {
   return fib_i_wrapper(n);
}
unsigned long long int FibRecursive(int n) {
   return fib_r_wrapper(n);
}


int main(int argc, char *argv[]) {
   int value = atoi(argv[1]);

   int N = value;


   if (argv[2][0] == 'i') {
      unsigned long long int result = fib_i_wrapper(N);
      printf("%llu", result);
   } else if (argv[2][0] == 'r') {
      unsigned long long int result = fib_r_wrapper(N);
      printf("%llu", result);
   }
   return 0;


}

