#include<iostream>
#include<vector>
#include<queue>
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (!root) return {};
		vector<int> res;
		queue<TreeNode*> queueTreeNode{ {root} };
		while (!queueTreeNode.empty()) {
			for (int i = queueTreeNode.size(); i > 0; --i) {
				TreeNode* t = queueTreeNode.front();
				res.push_back(t->val);
				queueTreeNode.pop();
				if (t->left) queueTreeNode.push(t->left);
				if (t->right) queueTreeNode.push(t->right);
			}
		}
		return res;
	}
};