#include <stdio.h>

struct date {
	short day;
	short month;
	short year;
	short weekday;
};

struct date next_day(struct date d) {
	struct date ret = d;

	ret.day++;

	ret.weekday = (ret.weekday + (short)1) % (short)7;

	switch (ret.month) {
		case 1: case 3: case 5: case 7: case 8: case 10:
			if (ret.day == 32) {
				ret.month++;
				ret.day = 1;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (ret.day == 31) {
				ret.month++;
				ret.day = 1;
			}
			break;
		case 12:
			// December
			if (ret.day == 32) {
				ret.year++;
				ret.month = 1;
				ret.day = 1;
			}
			break;
		default:
			// February
			if (ret.year % 4 == 0 && (ret.year % 400 == 0 || ret.year % 100 != 0)) {
				// Leap year
				if (ret.day == 30) {
					ret.month++;
					ret.day = 1;
				}
			} else {
				// Not leap year
				if (ret.day == 29) {
					ret.month++;
					ret.day = 1;
				}
			}
			break;
	}
	return ret;
}

int main() {
	int count = 0;

	// 1901 Jan 1 was Tue
	struct date temp;
	temp.day = 1;
	temp.month = 1;
	temp.year = 1901;
	temp.weekday = 2;

	while(!(temp.year == 2001 && temp.month == 1 && temp.day == 1)) {
		if (temp.day == 1 && temp.weekday == 0) count++;
		temp = next_day(temp);
	}

	printf("%d Sundays fell on the first of the month during the twentieth century.\n", count);
}