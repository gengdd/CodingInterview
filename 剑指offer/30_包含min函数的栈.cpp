#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
	void push(int value) {
		m_data.push(value);

		if (m_min.size() == 0 || m_min.top() > value)
			m_min.push(value);
		else
			m_min.push(m_min.top());
	}
	void pop() {
		m_data.pop();
		m_min.pop();
	}
	int top() {
		return m_data.top();
	}
	int min() {
		return m_min.top();
	}
private:
	stack<int> m_data, m_min;
};