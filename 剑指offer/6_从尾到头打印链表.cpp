#include<iostream>
#include<stack>
#include<vector>
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
//	vector<int> printListFromTailToHead(ListNode* head) {
//		vector<int> res;
//		while (head != nullptr) {
//			res.push_back(head->val);
//			head = head->next;
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int> nodes;
		vector<int> res;
		ListNode* node = head;
		while (node != NULL) {
			nodes.push(node->val);
			node = node->next;
		}
		while (!nodes.empty()) {
			res.push_back(nodes.top());
			nodes.pop();
		}
		return res;
	}
};
