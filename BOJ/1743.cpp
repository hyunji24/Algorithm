#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
using namespace std;
int n, m, k;
int map[101][101];
int visited[101][101];
int answer = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int i, int j) {
	queue<pair<int, int> > q;
	
	q.push({ i,j });
	int cnt = 1;
	visited[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
			if (map[xx][yy] == 0 || visited[xx][yy])continue;
			
			q.push({ xx,yy });
			cnt++;
			visited[xx][yy] = 1;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				answer = max(answer, bfs(i, j));
			}
		}
	}
	cout << answer << endl;
	return 0;
}