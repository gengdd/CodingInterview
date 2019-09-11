#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k) {
		if (pRoot == NULL || k == 0) {
			return NULL;
		}
		return KthNodeCore(pRoot, k);
	}
	TreeNode* KthNodeCore(TreeNode* pRoot, int &k) {
		TreeNode *target = NULL;
		if (pRoot->left != NULL) {
			target = KthNodeCore(pRoot->left, k);
		}
		if (target == NULL) {
			if (k == 1)
				target = pRoot;
			k--;
		}
		if (pRoot->right != NULL && target == NULL) {
			target = KthNodeCore(pRoot->right, k);
		}
		return target;
	}
};