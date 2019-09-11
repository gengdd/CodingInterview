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
	ListNode* EntryNodeOfLoop(ListNode* pHead) {
		ListNode *slow = pHead, *fast = pHead;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		if (!fast || !fast->next)
			return NULL;
		slow = pHead;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
};