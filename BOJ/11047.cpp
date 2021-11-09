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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> value(n);
	for (int i = 0; i < n; i++)cin >> value[i];

	int answer = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k == 0)break;
		if (k - value[i] >= 0) {
			answer += k / value[i];
			k -= value[i] * (k / value[i]);
		}
	}
	cout << answer;
	return 0;

}