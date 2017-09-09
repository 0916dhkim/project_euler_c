#include <stdio.h>

int main() {
	long i;
	long j;
	long answer = 0L;
	for (i = 1; i <= 100L; i++) {
		for (j = 1; j <= 100L; j++) {
			if (i != j) {
				answer += i * j;
			}
		}
	}
	printf("The difference between the sum of the squares of the first 100 natural numbers and the square of the sum is %ld\n", answer);
}
