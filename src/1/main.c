#include <stdio.h>

int sum_of_multiples(int multiple_of, int limit) {
	int n = (limit - 1) / multiple_of;
	return multiple_of * (n * (n + 1)) / 2;
}

int gcd(int a, int b) {
	int less = 0;
	int greater = 0;
	int gcd = 0;

	// Determine which number is greater.
	if (a < b) {
		less = a;
		greater = b;
	} else {
		less = b;
		greater = a;
	}

	// Invert the smaller number if it is negative.
	if (less < 0) {
		less = -less;
	}

	for (gcd = less; gcd != 1; gcd--) {
		// Return if gcd is a common divisor.
		if (a % gcd == 0 && b % gcd == 0) {
			return gcd;
		}
	}

	// GCD is 1.
	return gcd;
}

int lcm(int a, int b) {
	// LCM = a * b / GCD
	return a * b / gcd(a, b);
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
