#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		int maxSum = array[0];
		int curSum = array[0];
		for (int i = 1; i < array.size(); i++) {
			if (curSum < 0)
				curSum = array[i];
			else
				curSum = curSum + array[i];
			if (curSum > maxSum)
				maxSum = curSum;
		}
		return maxSum;
	}
};