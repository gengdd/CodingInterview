#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || (pushV.size() != popV.size()))
			return false;
		stack<int> stackData;
		for (int i = 0, j = 0; i < pushV.size(); ++i) {
			stackData.push(pushV[i]);
			while (j < popV.size() && stackData.top() == popV[j]) {
				stackData.pop();
				j++;
			}
		}
		return stackData.empty();
	}
};