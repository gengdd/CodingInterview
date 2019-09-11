#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		int m = array.size()-1, n = array[0].size()-1;
//		while (m >= 0 && n >= 0) {
//			if (target < array[0][n]) {
//				n = n - 1;
//				continue;
//			}
//			if (target < array[m][0]) {
//				m = m - 1;
//				continue;
//			}
//			for (int i = 0; i <= n; i++) {
//				if (target == array[m][i])
//					return true;
//			}
//			for (int i = 0; i <= m; i++) {
//				if (target == array[i][n])
//					return true;
//			}
//		}
//		return false;
//	}
//};

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size(), cols = array[0].size();
		if (!array.empty() && rows > 0 && cols > 0) {
			int row = 0;
			int col = cols - 1;
			while (row < rows&&col >= 0) {
				if (array[row][col] == target)
					return true;
				else if (array[row][col] > target) {
					--col;
				}
				else {
					++row;
				}
			}
		}
		return false;
	}
};
