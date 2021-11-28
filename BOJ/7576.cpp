#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[1001][1001];
bool visited[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int> > tomato;
int answer=-1, n, m;

struct Info {
	int x, y, day;
};

bool chk_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) { 
				return false;
			}
		}
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)tomato.push_back({ i,j });
		}
	}
	if (tomato.size() == m * n) { //모든 토마토가 익어있는 상태
		cout << 0;
		return 0;
	}

	queue<Info> q;
	for (int i = 0; i < tomato.size(); i++) {
		q.push({ tomato[i].first,tomato[i].second,0 });
		visited[tomato[i].first][tomato[i].second] = 1;
	}

	int x, y, day=0;
	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		day = q.front().day;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || visited[xx][yy])continue;
			if (map[xx][yy] == 0) {
				//map값이 0 이고 아직 방문 안한 상태
				q.push({ xx,yy,day + 1 });
				visited[x][y] = true;
				map[xx][yy] = 1;
			}
		}
	}

	if (chk_map())answer = day;
	cout << answer;
	
	return 0;
}