#include<iostream>
#include<vector>

using namespace std;

int digitAtIndex(int index) {
	if (index < 0)
		return -1;
	int digit = 1;
	while (true) {
		int number = countOfIntegers(digit);
		if (index < number*digit)
			return digitAtIndex(index, digit);
		index -= digit * number;
		digit++;
	}
	return -1;
}

int countOfIntegers(int digit) {
	if (digit == 1)
		return 10;
	int count = (int)pow(10, digit - 1);
	return 9 * count;
}

int digitAtIndex(int index, int digit) {
	int number = beginNumber(digit) + index / digit;
	int indexFromRight = digit - index % digit;
	for (int i = 1; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;
}

int beginNumber(int digit) {
	if (digit == 1)
		return 0;
	return (int)pow(10, digit - 1);
}
