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
int cols[15]; //cols[i]=k : i��° �� : k��° ĭ�� ����
int answer = 0;

bool isPossible(int x) { 
	for (int i = 0; i < x; i++) {
		if (cols[i] == cols[x])return false;
		if (abs(x - i) == abs(cols[x] - cols[i]))return false;
	}
	return true;
}

void nqueen(int x) {

	if (x == n) {
		answer++;
		return;
	}
	for (int i = 0; i < n; i++) { //i��° �ٿ� ���� ��
		cols[x] = i;
		if (isPossible(x))nqueen(x + 1);

	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	nqueen(0);
	cout << answer;
	return 0;

}