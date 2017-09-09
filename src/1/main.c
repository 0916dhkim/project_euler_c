#include <stdio.h>
#include <number_theory.h> /* for GCD and LCM calculation */

int sum_of_multiples(int multiple_of, int limit) {
	int n = (limit - 1) / multiple_of;
	return multiple_of * (n * (n + 1)) / 2;
}

int sum_of_two_multiples(int a, int b, int limit) {
	// Sum of multiples of two numbers is
	// sum of multiples of the first number plus
	// sum of multiples of the second number minus
	// sum of common multiples.
	return sum_of_multiples(a, limit) + sum_of_multiples(b, limit) - sum_of_multiples(lcm(a, b), limit);
}

int main() {
	printf("The sum of all the multiples of 3 or 5 below 1000 is %d\n", sum_of_two_multiples(3, 5, 1000));
}
