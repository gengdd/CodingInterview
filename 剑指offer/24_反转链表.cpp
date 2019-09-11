#include<iostream>

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
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* pReverseListHead = NULL;
		ListNode* pNode = pHead;
		ListNode* pPre = NULL;
		while (pNode != NULL) {
			ListNode* pNext = pNode->next;
			if (pNext == NULL)
				pReverseListHead = pNode;
			pNode->next = pPre;
			pPre = pNode;
			pNode = pNext;
		}
		return pReverseListHead;
	}
};
