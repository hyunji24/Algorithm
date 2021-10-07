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

	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int cnt = 0;
	cout << "<";
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cnt++;
		if (cnt == k) {
			if (!q.empty())cout << x << ",";
			else cout << x;
			cnt = 0;
		}
		else q.push(x);
	}
	cout << ">";
	return 0;

}