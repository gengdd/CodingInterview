#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode) {
		if (pNode == NULL)
			return NULL;
		TreeLinkNode* pNext = NULL;
		if (pNode->right != NULL) {
			TreeLinkNode* pRight = pNode->right;
			while (pRight->left != NULL) {
				pRight = pRight->left;
			}
			pNext = pRight;
		}
		else if (pNode->next!=NULL) {
			TreeLinkNode* pCur = pNode;
			TreeLinkNode* pPar = pNode->next;
			while (pPar != NULL && pCur == pPar->right) {
				pCur = pPar;
				pPar = pCur->next;
			}
			pNext = pPar;
		}
		return pNext;
	}
};