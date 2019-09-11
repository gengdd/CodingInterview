#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> res;
		int length = array.size();
		if (length < 1) {
			return res;
		}
		int pright = length - 1;
		int pleft = 0;
		while (pright > pleft) {
			int curSum = array[pleft] + array[pright];
			if (curSum == sum) {
				res.push_back(array[pleft]);
				res.push_back(array[pright]);
				break;
			}
			else if (curSum > sum) {
				pright--;
			}
			else {
				pleft++;
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		int phigh = 2, plow = 1;

		while (phigh > plow) {
			int curSum = (plow + phigh)*(phigh - plow + 1) >> 1;
			if (curSum < sum)
				phigh++;
			if (curSum == sum) {
				vector<int> tmp;
				for (int i = plow; i <= phigh; i++)
					tmp.push_back(i);
				res.push_back(tmp);
				plow++;
			}
			if (curSum > sum) {
				plow++;
			}
		}
		return res;
	}
};
