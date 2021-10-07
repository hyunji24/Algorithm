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
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	set<string,greater<string>> s; //set에도 정렬기준을 넣어줄수 있음!!
	for (int i = 0; i < n; i++) {
		string name, status;
		cin >> name >> status;
		if (status == "enter")s.insert(name);
		else if (status == "leave")s.erase(name);
	}

	for (auto i : s)cout << i << '\n';
	return 0;
}