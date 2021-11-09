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
char alph[16];
char arr[16];
bool visited[16];
//Bruteforce : 모든 경우 해보고 체크

void dfs(int index, int depth) {

	if (depth == l) {
		int ja = 0, mo = 0;
		for (int i = 0; i < l; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')mo++;
			else ja++;
		}
		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < l; i++)cout << arr[i];
			cout << '\n';
		}
		return;
	}

	for (int i = index; i < c; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = alph[i];
			dfs(i + 1, depth + 1);
			visited[i] = false;
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> l >> c;
	for (int i = 0; i < c; i++)cin >> alph[i];

	sort(alph, alph + c);
	

	//조합으로 l개 알파벳 고르기
	dfs(0,0);

	return 0;
}