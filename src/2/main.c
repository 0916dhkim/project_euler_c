#include <stdio.h>

int sum_of_even_fibonacci(int limit) {
	int n1 = 0;
	int n2 = 1;
	int ret = 0;

	while (n2 <= limit) {
		int tmp = n1 + n2;

		// Add the current fibonacci number if it is even.
		if (n2 % 2 == 0) ret += n2;

		// Calculate next fibonacci number.
		n1 = n2;
		n2 = tmp;
	}

	return ret;
}

int main() {
	printf("Sum of even fibonacci numbers that do not exceed 4000000 is %d\n", sum_of_even_fibonacci(4000000));
}
