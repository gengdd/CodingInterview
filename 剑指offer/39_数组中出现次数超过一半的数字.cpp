#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		int res = numbers[0];
		int times = 1;
		for (int i = 1; i < numbers.size(); ++i) {
			if (times == 0) {
				res = numbers[i];
				times = 1;
			}
			else if (numbers[i] == res) {
				times++;
			}
			else {
				times--;
			}
		}
		times = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == res) {
				times++;
			}
		}
		return (times > (numbers.size() >> 1)) ? res : 0;
	}
};
