#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int m, n;
int map[10][10];
int tmp_map[10][10];
bool visited[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;

vector<pair<int,int> > zero;
vector<pair<int, int> > virus;

int check_safeArea() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp_map[i][j] == 0)cnt++;
		}
	}
	return cnt;
}

void spread_virus() {
	queue<pair<int, int> > q;
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first,virus[i].second });
		visited[virus[i].first][virus[i].second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)continue;
			
			if (!visited[xx][yy] && tmp_map[xx][yy] == 0) {
				tmp_map[xx][yy] = 2;
				visited[xx][yy] = true;
				q.push({ xx,yy });
			}
		}
	}
}

void spread_dfs(int x,int y) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)continue;
		if (!visited[xx][yy] && tmp_map[xx][yy] == 0) {
			tmp_map[xx][yy] = 2;
			spread_dfs(xx, yy);
		}
	}
}

void choose_wall(int idx, int cnt) {
	if(cnt==3){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp_map[i][j] = map[i][j];
			}
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < virus.size(); i++) {
				spread_dfs(virus[i].first,virus[i].second);
		}

		//spread_virus();
		answer=max(answer,check_safeArea());
		return;
	}

	for (int i = idx; i < zero.size(); i++) { //벽 3군데 고름
		map[zero[i].first][zero[i].second] = 1;
		choose_wall(i + 1, cnt + 1);
		map[zero[i].first][zero[i].second] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)zero.push_back({ i,j });
			else if (map[i][j] == 2)virus.push_back({ i,j });
		}
	}

	choose_wall(0,0);
	cout << answer;

	return 0;
}