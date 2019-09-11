#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		int pBegin = 0, pEnd = array.size() - 1;
//		while (pBegin < pEnd) {
//			while (pBegin < pEnd&&array[pBegin] % 2 != 0) {
//				pBegin++;
//			}
//			while (pBegin < pEnd&&array[pEnd] % 2 == 0) {
//				pEnd--;
//			}
//			if (pBegin < pEnd) {
//				swap(array[pBegin], array[pEnd]);
//			}
//		}
//	}
//};

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		deque<int> res;
		int num = array.size() - 1;
		for (int i = 0; i <= num; ++i) {
			if (array[num - i] % 2 == 1) {
				res.push_front(array[num - i]);
			}
			if (array[i] % 2 == 0) {
				res.push_back(array[i]);
			}
		}
		array.assign(res.begin(), res.end());
	}
};
