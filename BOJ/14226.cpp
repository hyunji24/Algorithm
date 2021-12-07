#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
using namespace std;
bool visited[1001][1001]; //화면에 i개,클립보드에j개
struct Info {
	int scr, clip, time;
};

int main() {
	int s;
	cin >> s;
	queue<Info> q;
	visited[1][0] = true;
	q.push({ 1,0,0 });
	int answer = 0;
	while (!q.empty()) {
		int scr = q.front().scr;
		int clip = q.front().clip;
		int time = q.front().time;
		q.pop();

		if (scr == s) {
			answer = time; break;
		}
		if (scr > 0 && scr <= 1000) {
			if (visited[scr][scr] == false) {
				visited[scr][scr] = true;
				q.push({ scr,scr,time + 1 }); //화면->클립 복사
			}
			if (visited[scr - 1][clip] == false) {
				visited[scr - 1][clip] = true;
				q.push({ scr - 1,clip,time + 1 }); //화면에서 하나삭제
			}
		}
		if (clip > 0 && scr + clip <= 1000) {
			if (visited[scr + clip][scr] == false) {
				visited[scr + clip][clip] = true;
				q.push({ scr + clip,clip,time + 1 }); //클립보드에 있는걸 화면으로
			}
		}
	}
	cout << answer;
	return 0;
}