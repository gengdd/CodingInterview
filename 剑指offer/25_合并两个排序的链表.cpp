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

//class Solution {
//public:
//	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
//		if (pHead1 == NULL)
//			return pHead2;
//		if (pHead2 == NULL)
//			return pHead1;
//
//		ListNode* MergeHead = NULL;
//		ListNode* Head = NULL;
//		Head->next = MergeHead;
//
//		while (pHead1 != NULL && pHead2 != NULL) {
//			if (pHead1->val < pHead2->val) {
//				MergeHead->next = pHead1;
//				pHead1 = pHead1->next;
//			}
//			if (pHead1->val > pHead2->val) {
//				MergeHead->next = pHead2;
//				pHead2 = pHead2->next;
//			}
//			MergeHead = MergeHead->next;
//		}
//		if (pHead1 == NULL)
//			MergeHead->next = pHead2;
//		if (pHead2 == NULL) {
//			MergeHead->next = pHead1;
//		}
//		return Head->next;
//	}
//};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;

		ListNode* pMergeHead = NULL;
		if (pHead1->val < pHead2->val) {
			pMergeHead = pHead1;
			pMergeHead->next = Merge(pHead1->next, pHead2);
		}
		else {
			pMergeHead = pHead2;
			pMergeHead->next = Merge(pHead1, pHead2->next);
		}
		return pMergeHead;
	}
};


