#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if (matrix.empty() || matrix[0].empty())
			return {};
		int m = matrix.size(), n = matrix[0].size();
		vector<int> res;
		int up = 0, down = m - 1, left = 0, right = n - 1;
		while (true) {
			for (int i = left; i <= right; ++i)
				res.push_back(matrix[up][i]);
			if (++up > down) break;
			for (int i = up; i <= down; ++i)
				res.push_back(matrix[i][right]);
			if (--right < left) break;
			for (int i = right; i >= left; --i)
				res.push_back(matrix[down][i]);
			if (--down < up) break;
			for (int i = down; i >= up; --i)
				res.push_back(matrix[i][left]);
			if (++left > right) break;
		}
		return res;
	}
};


