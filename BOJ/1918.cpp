#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
#include<set>
using namespace std;

int main() {

	string str;
	cin >> str;
	stack<char> st;
	string answer;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')st.push(str[i]);
		else if (str[i] >= 'A' && str[i] <= 'Z')answer+=str[i];
		else if (str[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				answer += st.top();
				st.pop();
			}
			st.pop(); //(까지 pop
		}
		else {//연산자인 경우
			if (str[i] == '*' || str[i] == '/') {
				while (!st.empty() && (st.top()=='*' ||st.top()=='/')) {
					answer += st.top();
					st.pop();

				}
				st.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-') {
				while (!st.empty() && st.top() != '(') {
					answer += st.top();
					st.pop();
				}
				st.push(str[i]);
			}

		}
	}
	while (!st.empty())
	{
		answer += st.top();
		st.pop();
	}
	cout << answer;
}