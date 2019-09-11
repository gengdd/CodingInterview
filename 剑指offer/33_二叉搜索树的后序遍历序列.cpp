#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

//class Solution {
//public:
//	bool VerifySquenceOfBST(vector<int> sequence) {
//		if (sequence.size() <= 0)
//			return false;
//
//		int length = sequence.size();
//		int root = sequence[length - 1];
//		vector<int> leftseq;
//		vector<int> rightseq;
//
//		int i = 0;
//		for (; i < length; ++i) {
//			if (sequence[i] > root) {
//				break;
//			}
//			leftseq.push_back(sequence[i]);
//		}
//		int j = i;
//		for (; j < length - 1; ++j) {
//			if (sequence[j] < root)
//				return false;
//			rightseq.push_back(sequence[j]);
//		}
//		bool left = true;
//		if (i > 0)
//			left = VerifySquenceOfBST(leftseq);
//		bool right = true;
//		if (i < length - 1)
//			right = VerifySquenceOfBST(rightseq);
//
//		return (left&&right);
//	}
//};

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		return bst(sequence, 0, sequence.size() - 1);
	}
	bool bst(vector<int> seq, int begin, int end) {
		if (seq.empty() || begin > end)
			return false;

		int root = seq[end];
		int i = begin;
		for (; i < end; ++i) {
			if (seq[i] > root)
				break;
		}
		for (int j = i; j < end; ++j) {
			if (seq[j] < root)
				return false;
		}

		bool left = true;
		if (i > begin) {
			left = bst(seq, begin, i - 1);
		}
		bool right = true;
		if (i < end - 1) {
			right = bst(seq, i, end - 1);
		}
		return left && right;
	}
};