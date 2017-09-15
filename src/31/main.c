#include <stdio.h>

const int coin_worth_arr[8] = {1, 2, 5, 10, 20, 50, 100, 200};

long f(int sum, int num_types) {
	if (num_types == 1) {
		return 1;
	} else {
		long ret = 0L;
		int i;
		for (i = 0; coin_worth_arr[num_types - 1] * i <= sum; i++) {
			ret += f(sum - coin_worth_arr[num_types - 1] * i, num_types - 1);
		}
		return ret;
	}
}

int main() {
	printf("2 pounds can be made in %ld different ways.\n", f(200, 8));
}