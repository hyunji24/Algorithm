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
int dp[101];

struct Info {
	int bottom, h, w;
};

bool cmp(Info& a, Info& b) {
	return a.bottom < b.bottom;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Info> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].bottom >> v[i].h >> v[i].w;
	}

	sort(v.begin(), v.end(),cmp);
	
	int answer = 0;
	dp[1] = v[1].h;
	for (int i = 2; i <= n; i++) {
		int maxHeight = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (v[j].w < v[i].w && maxHeight < dp[j])
				maxHeight = dp[j];
		}
		dp[i] = maxHeight + v[i].h;
		answer = max(dp[i], answer);
		
	}
	cout << answer;

	return 0;
}