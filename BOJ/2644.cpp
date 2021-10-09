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
bool visited[101];
vector<int> v[101];
int main() {

	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	int answer = -1;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	queue<pair<int, int> > q;
	q.push({ a,0 });
	visited[a] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		//cout << x << " " << cnt << endl;

		if (x == b) {
			answer = cnt;
			break;
		}
		for (int i = 0; i < v[x].size(); i++)
		{
			int next = v[x][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
		}

		
	}
	cout << answer;
	return 0;
}