#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H

#include <stdbool.h>

long gcd(long, long);

long lcm(long, long);

bool is_prime(long);

void factor(long, int*, int);

#endif // NUMBER_THEORY_H
