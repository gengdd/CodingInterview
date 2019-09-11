#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//		return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
//	}
//	TreeNode* reConstructBinaryTree(vector<int> pre, int pleft, int pright, vector<int> vin, int vleft, int vright) {
//		if (pleft > pright || vleft > vright)
//			return NULL;
//		int i = 0;
//		for (i = vleft; i <= vright; ++i) {
//			if (pre[pleft] == vin[i])
//				break;
//		}
//		TreeNode *cur = new TreeNode(pre[pleft]);
//		cur->left = reConstructBinaryTree(pre, pleft + 1, pleft + i - vleft, vin, vleft, i - 1);
//		cur->right = reConstructBinaryTree(pre, pleft + i - vleft + 1, pright, vin, i + 1, vright);
//		return cur;
//	}
//};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)
			return NULL;
		vector<int> left_pre, right_pre, left_vin, right_vin;
		TreeNode* head = new TreeNode(pre[0]);
		int root = 0;
		for (int i = 0; i < pre.size(); i++) {
			if (pre[0] == vin[i]) {
				root = i;
				break;
			}
		}

		for (int i = 0; i < root; i++) {
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);
		}
		for (int i = root + 1; i < pre.size(); i++) {
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}

		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;
	}
};