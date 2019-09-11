#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int res;
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		res = stack2.top(); 
		stack2.pop();
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};