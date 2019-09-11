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
	void Mirror(TreeNode *pRoot) {
		if ((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL)) {
			return;
		}

		TreeNode* pTemp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTemp;

		if (pRoot->left)
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
	}
};


