#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		int *resNumber = new int[index];
		resNumber[0] = 1;
		int p2_index = 0, p3_index = 0, p5_index = 0;
		for (int i = 1; i < index; i++) {
			resNumber[i] = min(2 * resNumber[p2_index], min(3 * resNumber[p3_index], 5 * resNumber[p5_index]));
			if (2 * resNumber[p2_index] == resNumber[i])
				++p2_index;
			if (3 * resNumber[p3_index] == resNumber[i])
				++p3_index;
			if (5 * resNumber[p5_index] == resNumber[i])
				++p5_index;
		}
		return resNumber[index - 1];
	}
};

