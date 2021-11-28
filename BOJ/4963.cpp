#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int dx[8] = { 1,0,-1,0 ,1,1,-1,-1};
int dy[8] = { 0,1,0,-1,1,-1,1,-1 };
int map[51][51];
bool visited[51][51];
int answer = 0;

void dfs(int x, int y,int w,int h) {
	
	visited[x][y] = true;

	for (int k = 0; k < 8; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (xx < 0 || yy < 0 || xx >= h || yy >= w || map[xx][yy] == 0 || visited[xx][yy])continue;
		dfs(xx, yy,w,h);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h;

	while(true) {
		cin >> w >> h;
		answer = 0;
		if (w == 0 && h == 0)break;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					dfs(i, j,w,h);
					answer++;
				}
				
			}
		}
		cout << answer << '\n';
	}

	return 0;
}