#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.empty() || k > input.size()) {
			return res;
		}
		sort(input.begin(), input.end());
		for (int i = 0; i < k; ++i) {
			res.push_back(input[i]);
		}
		return res;
	}
};

//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		vector<int> res;
//		if (input.empty() || k > input.size()) {
//			return res;
//		}
//		for (int i = 0; i < input.size(); ++i) {
//			if (i < k) {
//				maxHeap.push(input[i]);
//			}
//			if (i>= k && maxHeap.top() > input[i]) {
//				maxHeap.pop();
//				maxHeap.push(input[i]);
//			}
//		}
//
//		for (int i = 0; i < k; i++) {
//			res.push_back(maxHeap.top());
//			maxHeap.pop();
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//private:
//	priority_queue<int, vector<int>, less<int>> maxHeap;
//};

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		int length = input.size();
		bool change = true;
		if (length <= 0 || k <= 0 || k > length)
			return res;
		for (int i = 0; i < input.size(); i++) {
			if (res.size() < k) {
				res.push_back(input[i]);
			}
			else {
				if (change == true) {
					for (int j = k / 2; j >= 0; j--) {
						HeadAdjust(res, j, k);
					}
					for (int j = k - 1; j > 0; j--) {
						swap(res[0], res[j]);
						HeadAdjust(res, 0, j);
					}
					change = false;
				}
				if (res[k - 1] > input[i]) {
					res[k - 1] = input[i];
					change = true;
				}
			}
		}
		return res;
	}
private:
	void HeadAdjust(vector<int> &input, int parent, int length) {
		int temp = input[parent];
		int child = 2 * parent + 1;
		while (child < length) {
			if (child + 1 < length && input[child] < input[child + 1]) {
				child++;
			}
			if (temp >= input[child]) {
				break;
			}
			input[parent] = input[child];

			parent = child;
			child = 2 * parent + 1;
		}
		input[parent] = temp;
	}
};
