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
int dice[10001][7];
int answer = 0;
bool visited[7];

void go(int diceNum, int sum, int botidx) { //총 주사위 개수, 옆면 최대 누적합, 맨 밑면)
	memset(visited, 0, sizeof(visited));
	
	if (diceNum == 0) {
		answer = max(answer, sum);
		return;
	}
	int bottom=botidx;
	if (diceNum != n) {
		for (int i = 1; i <= 6; i++) {
			if (dice[diceNum][i] == dice[diceNum +1][botidx])
				bottom = i;
		}
	}
	
	visited[dice[diceNum][bottom]] = true;
	
	int upidx = bottom + 3;
	if (upidx >= 7)upidx -= 6; //dice[i][up] 반대쪽면
	visited[dice[diceNum][upidx]] = true;
	

	int maxnum = 0;
	for (int i = 1; i <= 6; i++) {
		if (!visited[i]) {
			maxnum = max(maxnum, i);
		}
	}
	go(diceNum - 1, sum + maxnum, upidx);


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; //주사위 개수
	for (int i = n; i >=1 ; i--) {
		cin >> dice[i][1] >> dice[i][2] >> dice[i][3] >> dice[i][5] >> dice[i][6] >> dice[i][4];
	}

	for (int i = 1; i <= 6; i++)go(n, 0, i);

	cout << answer;
	return 0;
}