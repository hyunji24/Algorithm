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
int map[5][5];
int answer = 0;
set<int> s;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[1000000];

void dfs(int x, int y, int cnt,int num) {

	if (cnt == 6) {
		if (!visited[num]) {
			visited[num] = true;
			answer++;
		}
		return;
	}
	

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < 5 && yy < 5) {
			dfs(xx, yy, cnt + 1, num * 10 + map[xx][yy]);
		
			}
		}
	
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) { //°¢ Ä­¿¡¼­ ´Ù ½ÃÀÛÇØºÁ¾ß µÊ
			dfs(i, j,0,0);
		}
	}

	cout << answer;
	return 0;

}