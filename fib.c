#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long int memo_array[INT_MAX];

unsigned long long int fib_i_core(int n)
{
   if (n == 1)
   {
      return 0;
   }
   else if (n == 2)
   {
      return 1;
   }
   unsigned long long int first = 0, second = 1, next_value;
   for (int i = 3; i <= n; i++)
   {
      next_value = first + second;
      first = second;
      second = next_value;
   }
   return second;
}

unsigned long long int fib_r_core(int n)
{
   if (n == 1)
   {
      return 0;
   }
   else if (n == 2)
   {
      return 1;
   }
   else
   {
      return fib_r_core(n - 1) + fib_r_core(n - 2);
   }
}

unsigned long long int FibIterative(int n)
{
   if (memo_array[n] != 0)
   {
      return memo_array[n];
   }
   if (n <= 1)
   {
      return 0;
   }
   else if (n == 2)
   {
      return 1;
   }
   memo_array[n] = fib_i_core(n);
   return memo_array[n];
}
unsigned long long int FibRecursive(int n)
{
   if (memo_array[n] != 0)
   {
      return memo_array[n];
   }
   if (n <= 1)
   {
      return 0;
   }
   else if (n == 2)
   {
      return 1;
   }
   memo_array[n] = fib_r_core(n);
   return memo_array[n];
}

int main(int argc, char *argv[])
{
   int value = atoi(argv[1]);

   int N = value;

   if (argv[2][0] == 'i')
   {
      unsigned long long int result = FibIterative(N);
      printf("%llu", result);
   }
   else if (argv[2][0] == 'r')
   {
      unsigned long long int result = FibRecursive(N);
      printf("%llu", result);
   }
   return 0;
}
