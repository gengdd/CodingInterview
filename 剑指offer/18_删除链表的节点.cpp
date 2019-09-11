#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	if (!pListHead || !pToBeDeleted)
		return;
	if (pToBeDeleted->next != NULL) {
		ListNode* pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else {
		ListNode* pNode = *pListHead;
		while (pNode->next != pToBeDeleted) {
			pNode = pNode->next;
		}
		pNode->next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}


//class Solution {
//public:
//	ListNode* deleteDuplication(ListNode* pHead) {
//		ListNode* PreNode = NULL;
//		ListNode* Node = pHead;
//		while (Node != NULL) {
//			ListNode* Next = Node->next;
//			bool needDelete = false;
//			if (Next != NULL && Next->val == Next->next->val)
//				needDelete = true;
//			if (!needDelete) {
//				PreNode = Node;
//				Node = Node->next;
//			}
//			else {
//				int val = Node->val;
//				ListNode* ToBeDel = Node;
//				while (ToBeDel != NULL && ToBeDel->val == val) {
//					Next = ToBeDel->next;
//					delete ToBeDel;
//					ToBeDel = NULL;
//					ToBeDel = Next;
//				}
//				if (PreNode == NULL)
//					pHead = Next;
//				else 
//					PreNode->next = Next;
//				Node = Next;
//			}
//		}
//		return pHead;
//	}
//};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == NULL) {
			return NULL;
		}
		ListNode* pPre = NULL;
		ListNode* pCur = pHead;
		ListNode* pNext = NULL;

		while (pCur != NULL) {
			if (pCur->next != NULL && pCur->val == pCur->next->val) {
				pNext = pCur->next;
				while (pNext->next != NULL && pNext->next->val == pCur->val) {
					pNext = pNext->next;
				}
				if (pCur == pHead) {
					pHead = pNext->next;
				}
				else {
					pPre->next = pNext->next;
				}
				pCur = pNext->next;
			}
			else {
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		return pHead;
	}
};


