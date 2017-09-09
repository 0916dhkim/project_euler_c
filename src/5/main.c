#include <stdio.h>
#include <number_theory.h> /* for LCM */

int main() {
	long answer = 1L;
	long i = 1L;
	for (; i <= 20L; i++) {
		answer = lcm(answer, i);
	}
	printf("The smallest positive integer that is evenly divisible by all of the numbers from 1 to 20 is %ld\n", answer);
}
