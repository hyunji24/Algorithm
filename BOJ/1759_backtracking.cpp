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
int l, c;
vector<char> v;
//backtracking 적용해보기

void backtracking(string str, int ja, int mo, int cur) {

	int len = str.length();
	if (len == l && ja >= 2 && mo >= 1) {
		cout << str << '\n';
		return;
	}

	for (int i = cur; i < c; i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			backtracking(str + v[i], ja, mo + 1, i + 1);
		}
		else backtracking(str + v[i], ja + 1, mo, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> c;
	v.resize(c);
	for (int i = 0; i < c; i++)cin >> v[i];

	sort(v.begin(), v.end());

	backtracking("", 0, 0, 0);

}