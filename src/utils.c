#include "utils.h"
#include <stdbool.h>
#include <math.h>

// Naive primilaty test
uchr isPrime(uint n)
{
    uint i, s;

    if (n == 1 || n%2 == 0)
        return false;

    s = (uint) sqrt(n);
    for (i = 3; i <= s; i += 2)
    {
        if (n%i == 0)
            return false;
    }

    return true;
}

