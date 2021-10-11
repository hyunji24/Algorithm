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

int map[10][10];
//int num[5] = { 1,2,3,4,5 };
//int cnt[5];
//vector<pair<int, int> > v;
//int answer = 30;
//bool visited[10][10];
//
//
//bool chk(int x,int y,int len) {
//	if (x + len >= 10 || y + len >= 10)return false;
//	if (cnt[len] == 5)return false;
//	for (int i = x; i < x + len; i++) {
//		for (int j = y; j < y + len; j++) {
//			if (map[i][j] == 0)return false;
//		}
//	}
//	for (int i = x; i < x + len; i++) {
//		for (int j = y; j < y + len; j++) {
//			visited[i][j] = true;
//		}
//	}
//	return true;
//}
//
//pair<int, int> findNext(int x, int y) {
//	for (int i = x; i < 10; i++) {
//		for (int j = y; j < 10; j++) {
//			if (!visited[i][j] && map[i][j] == 1)
//				return { i,j };
//		}
//	}
//}
//
//void dfs(int x,int y,int paper) {
//
//	if (k==v.size()) 
//	{ 
//		answer = min(answer, paper);
//		return; 
//	}
//	for (int i = 0; i < 5; i++) {
//		if (chk(x,y,i)) { //한 변 길이 i인 색종이 들어갈 수 있는지(범위 & 다 1인지) && cnt체크(5이하)
//			cnt[i]++;
//			pair<int, int> p = findNext(x, y);
//			dfs(p.first,p.second, paper+1);
//			cnt[i]--;
//			
//		}
//	}
//
//}
//
//int main() {
//	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 1)v.push_back({ i,j });
//		}
//	}
//
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (!visited[i][j] && map[i][j] == 1) {
//				memset(cnt, 0, sizeof(cnt));
//				dfs(i,j, 0);
//			}
//		}
//	}
//
//	if (answer == 30)cout << -1;
//	else cout << answer;
//	return 0;
//}
int papernum = 0;
int answer = 987654321;
int papercount[6] = { 0,5,5,5,5,5 };

bool isZero() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) return false;
		}
	}
	return true;
}

bool chk(int x,int y,int len) {
	if (x + len > 10 || y + len > 10)return false; //>=10 아니고 >10 !!!!
	if (papercount[len] == 0)return false;
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (map[i][j] == 0)return false;
		}
	}
	
	return true;
}

pair<int, int> findNext() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1)
				return { i,j };
		}
	}
}

void put(int x, int y, int len) {
	papernum -= len * len;
	//cout << papernum << " ";
	papercount[len]--;
	for (int i = x; i < x + len; i++)
		for (int j = y; j < y + len; j++)
			map[i][j] = 0;


}

void remove(int x, int y, int len) {
	papernum += len * len;
	papercount[len]++;
	for (int i = x; i < x + len; i++)
		for (int j = y; j < y + len; j++)
			
			map[i][j] = 1;
}

void dfs(int cnt) {

	if (isZero()) { //맵 다 채웠을 때
		answer = min(answer, cnt);
		return;
	}

	pair<int, int> p = findNext();
	//cout << p.first << " ," << p.second << endl;
	int i = p.first, j = p.second;
	for (int k = 5; k >= 1; k--) {
		if (chk(i, j, k)) {
			put(i, j, k);
			dfs(cnt + 1);
			remove(i, j, k);
		}
		//continue; 필요??
	}


}

int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)papernum++;
		}
	}
	dfs(0);
	if (answer == 987654321)cout << -1;
	else cout << answer;
	return 0;
}

//https://chosh95.tistory.com/461
//https://kibbomi.tistory.com/25