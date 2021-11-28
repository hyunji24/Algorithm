#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, k, S, X, Y, second = 0;
int map[201][201];
bool visited[201][201];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Info {
	int x, y,virus;
	bool operator<(const Info& b)const {
		return virus > b.virus;
	}
};



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	priority_queue<Info> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				q.push({ i,j,map[i][j]});
				visited[i][j]=true;
			}
		}
	}
	cin >> S >> X >> Y;
	
	while (true) {
		second++;
		if (second == S + 1) {
			break;
		}
		int qSize = q.size(); 
		priority_queue<Info> newq;
		for (int i = 0; i < qSize; i++) {
			Info now = q.top();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int xx = now.x + dx[k];
				int yy = now.y + dy[k];
				if (xx >= 0 && yy >= 0 && xx < n && yy < n && map[xx][yy]==0 && !visited[xx][yy]) {
					map[xx][yy] = now.virus;
					visited[xx][yy] = true;
					newq.push({ xx,yy,map[xx][yy]});
				}
			}
		}
		while (!newq.empty()) {
			Info now = newq.top();
			newq.pop();
			q.push({ now.x,now.y,now.virus });
		}
	}
	cout << map[X - 1][Y - 1];
	return 0;

}