#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
#include<set>
#include<iostream>
using namespace std;
int dp[18]; //dp[i]: 무게가 i 일때 가치의 최댓값


int main() {

	int n, limit;
	cin >> n >> limit;
	vector<pair<int, int> > v(n+1);
	for (int i = 1; i <=n; i++)cin >> v[i].first >> v[i].second;

	for (int i = 1; i <= n; i++) {
		int weight = v[i].first;
		int value = v[i].second;
		for (int j = weight; j <= limit; j++) {
			dp[j] = max(dp[j],dp[j - weight] + value);
		}
	}

	for (int i = 1; i <= limit; i++)cout << dp[i] << " ";
	cout << dp[n];




}