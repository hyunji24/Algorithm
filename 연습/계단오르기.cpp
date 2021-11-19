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
int dp[46];

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

	cout << DP(n);
	return 0;
}