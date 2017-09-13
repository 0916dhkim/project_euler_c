#include <stdio.h>
#include <stdbool.h>

int main() {
	int a = 1;
	int b = 1;
	int c = 1;
	bool solved = false;

	for (a = 1; a < 1000; a++) {
		for (b = a; a + b < 1000; b++) {
			c = 1000 - a - b;
			int c_squared = c * c;
			int c_squared_pythagorean = a * a + b * b;
			if (c_squared < c_squared_pythagorean) {
				break;
			} else if (c_squared == c_squared_pythagorean) {
				solved = true;
			}

			if (solved) {
				break;
			}
		}

		if (solved) {
			break;
		}
	}

	printf("%d^2 + %d^2 = %d^2 and %d + %d + %d = 1000\n", a, b, c, a, b, c);
	printf("%d * %d * %d = %d\n", a, b, c, a * b * c);
}