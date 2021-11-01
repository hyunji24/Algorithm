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
int n, s, answer;
int v[20];

void dfs(int idx, int sum)
{
	if (idx == n) {
		if (sum == s) answer++;
		return;
	}

	dfs(idx + 1, sum); 
	dfs(idx + 1, sum + v[idx]); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	
	dfs(0, 0);
	if (s == 0)answer--;
	cout << answer;
	return 0;

}