#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int length = data.size();
		if (length < 2)
			return;

		int resultExclusiveOR = 0;
		for (int i = 0; i < length; ++i) {
			resultExclusiveOR ^= data[i];
		}
		unsigned int indexOf1 = FindFirstBitsIs1(resultExclusiveOR);
		*num1 = *num2 = 0;
		for (int j = 0; j < length; j++) {
			if (IsBit1(data[j], indexOf1)) {
				*num1 ^= data[j];
			}
			else {
				*num2 ^= data[j];
			}
		}
	}
	unsigned int FindFirstBitsIs1(int num) {
		unsigned int indexBit = 0;
		while ((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))) {
			num = num >> 1;
			indexBit++;
		}
		return indexBit;
	}
	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return (num & 1);
	}
};

