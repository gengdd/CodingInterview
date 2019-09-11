#include<iostream>
#include<algorithm>
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
	int TreeDepth(TreeNode* pRoot) {
		if (pRoot == NULL)
			return 0;
		int nLeft = TreeDepth(pRoot->left);
		int nRight = TreeDepth(pRoot->right);
		return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)
			return true;

		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		int diff = left - right;
		if (diff > 1 || diff < -1)
			return false;
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
	int TreeDepth(TreeNode* pRoot) {
		if (pRoot == NULL)
			return 0;
		int nLeft = TreeDepth(pRoot->left);
		int nRight = TreeDepth(pRoot->right);
		return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
	}
};


