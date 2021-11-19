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
int dp[1001]; //dp[i]: i번째 숫자까지 갔을때 최대부분증가수열 길이
int num[1001];
int answer = 0;

int DP(int n) {
	if (n == 1)return 1;
	if (n == 2)return 2;
	else return DP(n - 1) + DP(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> num[i];

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int maxLen = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (num[j]<num[i] && dp[j]>maxLen)
				maxLen = dp[j];
		}
		dp[i] = maxLen + 1;
		answer = max(answer, dp[i]);
	}

	cout << answer;
	return 0;

	


}