#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int length = data.size();
		if (length == 0)
			return 0;
		int first = GetFirstK(data, k, 0, length - 1);
		int last = GetLastK(data, k, 0, length - 1);
		if (first != -1 && last != -1)
			return last - first + 1;
		return 0;
	}
	int GetFirstK(vector<int> data, int k, int begin, int end) {
		if (begin > end)
			return -1;
		int midIndex = (begin + end) >> 1;
		int midData = data[midIndex];

		if (midData == k) {
			if ((midIndex > 0 && data[midIndex - 1] != k) || midIndex == 0) {
				return midIndex;
			}
			else {
				end = midIndex - 1;
			}
		}
		else if (midIndex > k) {
			end = midIndex - 1;
		}
		else {
			begin = midIndex + 1;
		}
		return GetFirstK(data, k, begin, end);
	}
	int GetLastK(vector<int> data, int k, int begin, int end) {
		int length = data.size();
		int midIndex = (begin + end) >> 1;
		int midData = data[midIndex];

		while (begin <= end) {
			if (midData == k) {
				if ((midIndex < length - 1 && data[midIndex + 1] != k) || midIndex == length - 1)
					return midIndex;
				else
					begin = midIndex + 1;
			}
			else if (midData > k) {
				end = midIndex - 1;
			}
			else {
				begin = midIndex + 1;
			}
			midIndex = (begin + end) >> 1;
			midData = data[midIndex];
		}
		return -1;
	}
};


