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
		// ����ĸ�������
		vector<int> copy;
		for (int i = 0; i < data.size(); ++i) {
			copy.push_back(data[i]);
		}
		return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
	}
	long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end) {
		// ���ָ����ͬλ�ã���û������ԡ�
		if (begin == end) {
			copy[begin] = data[end];
			return 0;
		}
		// ���е�
		int mid = (end + begin) >> 1;
		// ʹdata�������򣬲�������������Ե���Ŀ
		long leftCount = InversePairsCore(copy, data, begin, mid);
		// ʹdata�Ұ�����򣬲������Ұ������Ե���Ŀ
		long rightCount = InversePairsCore(copy, data, mid + 1, end);

		int i = mid; // i��ʼ��Ϊǰ������һ�����ֵ��±�
		int j = end; // j��ʼ��Ϊ�������һ�����ֵ��±�
		int indexcopy = end; // �������鸴�Ƶ���������һ�����ֵ��±�
		long count = 0; // ����������Եĸ�����ע������

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
