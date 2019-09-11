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
//class Solution {
//public:
//	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
//		bool res = false;
//		if (pRoot1 != NULL && pRoot2 != NULL) {
//			if (Equal(pRoot1->val, pRoot2->val))
//				res = DoesTree1HaveTree2(pRoot1, pRoot2);
//			if (!res)
//				res = HasSubtree(pRoot1->left, pRoot2);
//			if (!res)
//				res = HasSubtree(pRoot1->right, pRoot2);
//		}
//		return res;
//	}
//private:
//	bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
//		if (pRoot2 == NULL)
//			return true;
//		if (pRoot2 == NULL)
//			return false;
//		if (!Equal(pRoot1->val, pRoot2->val))
//			return false;
//		return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
//	}
//
//	bool Equal(double num1, double num2) {
//		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
//			return true;
//		else
//			return false;
//	}
//};

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL) {
			if (pRoot1->val == pRoot2->val) {
				result = DoesTree1HasTree2(pRoot1, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
private:
	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL) {
			return true;
		}
		if (pRoot1 == NULL) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};
