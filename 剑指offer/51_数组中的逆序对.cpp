#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0)
			return 0;
		vector<int> copy;
		for (int i = 0; i < data.size(); ++i) {
			copy.push_back(data[i]);
		}
		return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
	}
	long InversePairsCore(vector<int>& data, vector<int>& copy, int begin, int end) {
		if (begin == end) {
			copy[begin] = data[end];
			return 0;
		}
		int mid = (begin + end) / 2;
		long leftCount = InversePairsCore(copy, data, begin, mid);
		long rightCount = InversePairsCore(copy, data, mid + 1, end);

		int i = mid;
		int j = end;
		int indexcopy = end;
		long count = 0;
		while (i >= begin && j >= mid + 1) {
			if (data[i] > data[j]) {
				copy[indexcopy--] = data[i--];
				count += j - mid;
			}
			else {
				copy[indexcopy--] = data[j--];
			}
		}
		for (; i >= begin; --i) {
			copy[indexcopy--] = data[i];
		}
		for (; j >= mid + 1; --j) {
			copy[indexcopy--] = data[j];
		}
		return leftCount + rightCount + count;
	}
};

class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0) {
			return 0;
		}
		// 排序的辅助数组
		vector<int> copy;
		for (int i = 0; i < data.size(); ++i) {
			copy.push_back(data[i]);
		}
		return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
	}
	long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end) {
		// 如果指向相同位置，则没有逆序对。
		if (begin == end) {
			copy[begin] = data[end];
			return 0;
		}
		// 求中点
		int mid = (end + begin) >> 1;
		// 使data左半段有序，并返回左半段逆序对的数目
		long leftCount = InversePairsCore(copy, data, begin, mid);
		// 使data右半段有序，并返回右半段逆序对的数目
		long rightCount = InversePairsCore(copy, data, mid + 1, end);

		int i = mid; // i初始化为前半段最后一个数字的下标
		int j = end; // j初始化为后半段最后一个数字的下标
		int indexcopy = end; // 辅助数组复制的数组的最后一个数字的下标
		long count = 0; // 计数，逆序对的个数，注意类型

		while (i >= begin && j >= mid + 1) {
			if (data[i] > data[j]) {
				copy[indexcopy--] = data[i--];
				count += j - mid;
			}
			else {
				copy[indexcopy--] = data[j--];
			}
		}
		for (; i >= begin; --i) {
			copy[indexcopy--] = data[i];
		}
		for (; j >= mid + 1; --j) {
			copy[indexcopy--] = data[j];
		}
		return leftCount + rightCount + count;
	}
};
