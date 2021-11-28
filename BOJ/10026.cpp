#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, answer, answer2;
char map[101][101];
bool visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int> > green;

void DFS(int x, int y, char color) {

	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (xx >= 0 && yy >= 0 && xx < n && yy < n && map[xx][yy] == color && !visited[xx][yy]) {
			visited[xx][yy] = true;
			DFS(xx, yy, color);
		}
	}
}

int check(int ans) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				DFS(i, j, map[i][j]);
				ans++;
			}
		}
	}
	return ans;
}

void changeToRed() {
	for (int i = 0; i < green.size(); i++) {
		map[green[i].first][green[i].second] = 'R';
	}
	memset(visited, 0, sizeof(visited));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'G')green.push_back({ i,j });
		}
	}

	answer = check(0);
	changeToRed();
	answer2 = check(0);

	cout << answer<<" "<<answer2;
	return 0;
}