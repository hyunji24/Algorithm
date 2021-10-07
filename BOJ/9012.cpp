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

bool isVPS(string str) {

	stack<char> st;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') st.push(str[i]);
		
		else if(str[i]==')')
		{
			if (st.empty())return false;
			else {
				if (st.top() == ')')return false;
				else st.pop();
			}
		
		}
	}
	if (!st.empty())return false;
	return true;


}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		if (isVPS(str))cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}