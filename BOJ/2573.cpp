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
int map[300][300], visited[300][300];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, land_cnt = 1;
int time = 0;
int answer = 0;
int bvisited[300][300];

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (map[xx][yy] != 0 && !bvisited[xx][yy]) {
				q.push({ xx,yy });
				bvisited[xx][yy] = true;
			}
		}
	}
}

int chk_cnt() { //빙산 몇개로 분리됐는지 반환
	int cnt = 0;
	memset(bvisited, 0, sizeof(bvisited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && !bvisited[i][j]) {
				bvisited[i][j] = true;
				bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;

}

bool chk_allmelt() { //빙산 다 녹았으면 true return
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0)return false;
		}
	}
	return true;
}

void melt(int x,int y) {
	int melt_cnt = 0;
	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (map[xx][yy] == 0 && !visited[xx][yy])
			melt_cnt++;

	}
	map[x][y] -= melt_cnt;
	if (map[x][y] < 0) {
		map[x][y] = 0;
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	
	int land_cnt;
	//cout << "lane cnt" << chk_cnt() << endl;
	while(1){
		land_cnt = chk_cnt();

		if (chk_allmelt() && land_cnt == 1) {
			answer = 0;
			break;
		}
		memset(visited, 0, sizeof(visited));
		time++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0 && !visited[i][j]) {
					visited[i][j] = 1;
					melt(i, j);
				}
			}
		}//한바퀴 다돎
		/*for(int i=0;i<n;i++){
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
		if (chk_cnt()>1) { //랜드 개수가 2개 이상이면
			answer = time;
			break;
		}
		
	}
	cout << answer;
}