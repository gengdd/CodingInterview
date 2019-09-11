#include<iostream>
#include<sstream>
#include<ostream>
#include<istream>
#include<string>
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
	char* Serialize(TreeNode *root) {
		if (!root)
			return NULL;
		string str;
		SerializeCore(root, str);

		int length = str.length();
		char* res = new char[length + 1];
		for (int i = 0; i < length; i++) {
			res[i] = str[i];
		}
		res[length] = '\0';
		return res;
	}
	void SerializeCore(TreeNode *root, string& str) {
		if (!root) {
			str += '#';
			return;
		}
		string tmp = to_string(root->val);
		str += tmp;
		str += ',';
		SerializeCore(root->left, str);
		SerializeCore(root->right, str);
	}

	TreeNode* Deserialize(char *str) {
		if (!str)
			return NULL;
		TreeNode *res = DeserializeCore(&str);
		return res;
	}
	TreeNode* DeserializeCore(char** str) {
		if (**str == '#') {
			(*str)++;
			return NULL;
		}
		int num = 0;
		while (**str != ','&&**str != '\0') {
			num = num * 10 + ((**str) - '0');
			(*str)++;
		}
		TreeNode* root = new TreeNode(num);
		if (**str == '\0')
			return root;
		else
			(*str)++;
		root->left = DeserializeCore(str);
		root->right = DeserializeCore(str);
		return root;
	}
};