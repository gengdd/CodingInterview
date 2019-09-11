#include<iostream>
#include<algorithm>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* pAhead = pListHead;
		ListNode* pBehind = NULL;

		for (int i = 1; i < k; ++i) {
			if (pAhead->next != NULL) {
				pAhead = pAhead->next;
			}
			else {
				return NULL;
			}
		}

		pBehind = pListHead;
		while (pAhead->next != NULL) {
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pBehind;
	}
};

