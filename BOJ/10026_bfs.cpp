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
char map[100][100];
bool visited[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ori_cnt, color_cnt;
int n;
int answer = 0;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int xx = a + dx[k];
			int yy = b + dy[k];
			if (xx < 0 || yy < 0 || xx >= n || yy >= n || visited[xx][yy])continue;
			if (map[a][b] == map[xx][yy]) {
				q.push({xx,yy });
				visited[xx][yy] = true;
			}
		}
	}
}

int main() {
	
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				answer++;
			}
		}
	}
	cout << answer;
}