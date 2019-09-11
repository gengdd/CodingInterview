#include<iostream>
#include<vector>
#include<queue>
#include<stack>

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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return res;
		tmp.push_back(root->val);
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL)
			res.push_back(tmp);

		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);

		tmp.pop_back();
		return res;
	}
private:
	vector<vector<int>> res;
	vector<int> tmp;
};
