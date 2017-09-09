#include <stdio.h>
#include <stdbool.h>

int count_digit(long num) {
	int ret;
	for (ret = 0; num > 0L; ret++) {
		num /= 10L;
	}
	return ret;
}

bool is_palindrome(long num) {
	// Calculate number of digits.
	int num_digit = count_digit(num);

	// Parse the number into decimal digits.
	int digits[num_digit];
	int i = 0;
	long tmp;
	for (tmp = num; i < num_digit; i++) {
		digits[i] = (int) (tmp % 10L);
		tmp /= 10L;
	}

	// Check each digits.
	for(i = 0; i < num_digit/2; i++) {
		if (digits[i] != digits[num_digit-i-1]) {
			// Non-symmetric digit exists.
			return false;
		}
	}
	// If there is no non-symmetric digit,
	// the number is a palindrome.
	return true;
}

int main() {
	long i;
	long j;
	long answer = 0;
	for (i = 100L; i < 1000L; i++) {
		for (j = 100L; j < 1000L; j++) {
			long product = i * j;
			if (product > answer && is_palindrome(product)) {
				answer = product;
			}
		}
	}
	printf("Largest palindrome made from the product of two 3-digit numbers is : %ld\n", answer);
}
