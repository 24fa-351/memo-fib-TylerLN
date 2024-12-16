#include <stdio.h>
#include <stdlib.h>
#define MEMO_ARRAY_SIZE 10000

unsigned long long int memo_array[MEMO_ARRAY_SIZE];

unsigned long long int fib_ix_core(int fib_index) {
    if (fib_index == 1)
        return 0;
    else if (fib_index == 2)
        return 1;

    unsigned long long int first  = 0;
    unsigned long long int second = 1;
    unsigned long long int next_value;

    for (int ix = 3; ix <= fib_index; ix++) {
        next_value = first + second;
        first      = second;
        second     = next_value;
    }
    return second;
}

unsigned long long int fib_r_core(int rec_index) {
    if (rec_index == 1)
        return 0;
    else if (rec_index == 2)
        return 1;
    else
        return fib_r_core(rec_index - 1) + fib_r_core(rec_index - 2);
}

unsigned long long int fib_ixterative(int fib_ix) {
    if (memo_array[fib_ix] != 0)
        return memo_array[fib_ix];
    if (fib_ix <= 1)
        return 0;
    else if (fib_ix == 2)
        return 1;
    memo_array[fib_ix] = fib_ix_core(fib_ix);
    return memo_array[fib_ix];
}

unsigned long long int fib_recursive(int rec_ix) {
    if (memo_array[rec_ix] != 0)
        return memo_array[rec_ix];
    if (rec_ix <= 1)
        return 0;
    else if (rec_ix == 2)
        return 1;
    memo_array[rec_ix] = fib_r_core(rec_ix);

    return memo_array[rec_ix];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./fib <number> <i/r>\n");
        return 1;
    }

    int user_int = atoi(argv[1]);

    if (argv[2][0] == 'i') {
        unsigned long long int result = fib_ixterative(user_int);
        printf("%llu", result);
    } else if (argv[2][0] == 'r') {
        unsigned long long int result = fib_recursive(user_int);
        printf("%llu", result);
    }

    return 0;
}