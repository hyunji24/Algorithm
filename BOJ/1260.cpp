#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n, m, v;
vector<int> vec[1001];
bool visited[1001];

void bfs(int cur) {
	queue<int> q;
	q.push(cur);

	while (!q.empty()) {
		int now = q.front();
		cout << now << " ";
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

void dfs(int cur) {
	cout << cur << " ";
	for (int i = 0; i < vec[cur].size(); i++) {
		int next = vec[cur][i];
		if (!visited[next]) {
			visited[next] = true;
			dfs(next);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m>>v;
	int first, second;
	for (int i = 0; i < m; i++) {
		cin >> first >> second;
		vec[first].push_back(second);
		vec[second].push_back(first);
	}

	for (int i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end());

	visited[v] = true;
	dfs(v);
	cout << '\n';

	memset(visited, 0, sizeof(visited));
	visited[v] = true;
	bfs(v);


	return 0;
}