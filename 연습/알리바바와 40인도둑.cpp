#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
#include<set>
#include<iostream>
using namespace std;
int map[21][21];
int dp[21][21];


int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	dp[1][1] = map[1][1];
	for (int i = 2; i <= n; i++) {
		dp[1][i] = map[1][i] + dp[1][i - 1];
		dp[i][1] = map[i][1] + dp[i - 1][1];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			dp[i][j] = map[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}

		cout << dp[n][n];
		return 0;
	}

