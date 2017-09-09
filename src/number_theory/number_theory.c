#include <number_theory.h>

long gcd(long a, long b) {
	long less = 0;
	long greater = 0;
	long gcd = 0;

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

	for (gcd = less; gcd != 1L; gcd--) {
		// Return if gcd is a common divisor.
		if (a % gcd == 0L && b % gcd == 0L) {
			return gcd;
		}
	}

	// GCD is 1.
	return gcd;
}

long lcm(long a, long b) {
	// LCM = a * b / GCD
	return a * b / gcd(a, b);
}
