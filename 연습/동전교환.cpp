#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
#include<set>
#include<iostream>
using namespace std;


int main() {
	int n, m;
	cin >> n;
	vector<int>coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cin >> m;
	vector<int> dp(m + 1, 1000);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= m; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	cout << dp[m];
	return 0;
	
}