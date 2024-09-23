#include <stdio.h>
#include <stdlib.h>
#define MEMO_ARRAY_SIZE 10000

unsigned long long int memo_array[MEMO_ARRAY_SIZE];

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

   unsigned long long int first = 0;
   unsigned long long int second = 1;
   unsigned long long int next_value;

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
   memo_array[n] = fib_i_core(n);
   return memo_array[n];
}

unsigned long long int FibRecursive(int n)
{
   if (memo_array[n] != 0)
   {
      return memo_array[n];
   }
   memo_array[n] = fib_r_core(n);
   return memo_array[n];
}

int main(int argc, char *argv[])
{
   int user_int = atoi(argv[1]);

   if (argv[2][0] == 'i')
   {
      unsigned long long int result = FibIterative(user_int);
      printf("%llu", result);
   }
   else if (argv[2][0] == 'r')
   {
      unsigned long long int result = FibRecursive(user_int);
      printf("%llu", result);
   }
   return 0;
}