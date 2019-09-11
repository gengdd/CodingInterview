#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMaxValue(const int* value, int rows, int cols) {
	if (value == NULL || rows <= 0 || cols <= 0)
		return 0;
	int* maxValues = new int[cols];
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int left = 0;
			int up = 0;
			if (i > 0)
				up = maxValues[j];
			if (j > 0)
				left = maxValues[j - 1];

			maxValues[j] = max(up, left) + value[i*cols + j];
		}
	}
	int maxValue = maxValues[cols - 1];
	delete[] maxValues;
	return maxValue;
}

