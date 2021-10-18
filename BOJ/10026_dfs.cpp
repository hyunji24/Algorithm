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
int n;
char map[100][100];
bool visited[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int x, int y) {

	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k], yy = y + dy[k];
		if (xx >= 0 && yy >= 0 && xx < n && yy < n && !visited[xx][yy] && map[xx][yy] == map[x][y]) {
			visited[xx][yy] = true;
			dfs(xx, yy);
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int ori_cnt = 0, new_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(i, j);
				ori_cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G')map[i][j] = 'R';
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(i, j);
				new_cnt++;
			}
		}
	}
	cout << ori_cnt << " " << new_cnt;
	return 0;


}