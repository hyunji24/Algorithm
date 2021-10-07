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
vector<int> tower;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	tower.resize(n);
	for (int i = 0; i < n; i++)cin >> tower[i];

	stack<pair<int,int>> st;
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			cout << 0 << " ";
		}
		else { //스택 비어있지 않은 경우
			while (!st.empty() && st.top().second <= tower[i])st.pop();
			if (st.empty())cout << 0 << " ";
			else cout << st.top().first << " ";
		}
		st.push({ i + 1,tower[i] });
	}
	return 0;

}