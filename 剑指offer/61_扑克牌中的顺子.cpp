#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5)
			return false;

		sort(numbers.begin(), numbers.end());

		int numberOfZero = 0;
		int numberOfGap = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == 0)
				++numberOfZero;
		}

		int small = numberOfZero;
		int big = small + 1;
		while (big < numbers.size()) {
			if (numbers[small] == numbers[big])
				return false;
			numberOfGap += numbers[big] - numbers[small] - 1;
			small = big;
			++big;
		}
		return (numberOfGap > numberOfZero) ? false : true;
	}
};