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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;

		unsigned int len1 = GetListLength(pHead1);
		unsigned int len2 = GetListLength(pHead2);
		ListNode* pHeadLong = pHead1;
		ListNode* pHeadShort = pHead2;

		int LengthDif = len1 - len2;
		if (len1<len2){
			ListNode* pHeadLong = pHead2;
			ListNode* pHeadShort = pHead1;
			int LengthDif = len2 - len1;
		}
		for (int i = 0; i < LengthDif; i++) {
			pHeadLong = pHeadLong->next;
		}
		while (pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort) {
			pHeadLong = pHeadLong->next;
			pHeadShort = pHeadShort->next;
		}
		return pHeadLong;
	}
	unsigned int GetListLength(ListNode* pHead) {
		if (pHead == NULL)
			return 0;
		unsigned int length = 1;
		while (pHead->next != NULL) {
			pHead = pHead->next;
			length++;
		}
		return length;
	}
};
