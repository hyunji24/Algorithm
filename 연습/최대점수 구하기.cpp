#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
#include<set>
#include<iostream>
using namespace std;
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int score ,time;
	for (int i = 0; i < n; i++) {
		cin >> score >> time;
		for (int j = m; j >= time; j--) {
			dp[j] = max(dp[j], dp[j - time] + score);
		}
	}
	cout << dp[m];
	return 0;
}