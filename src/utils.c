#include <math.h>

#include "utils.h"

// Naive primilaty test
unsigned char isPrime(int n)
{
    int i, s;

    if (n == 1 || n%2 == 0)
        return 0;

    s = (int) sqrt(n);
    for (i = 3; i <= s; i += 2)
    {
        if (n%i == 0)
            return 0;
    }

    return 1;
}
