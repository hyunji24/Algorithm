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
int k;
bool visited[10];
vector<char> v;
string min_ans, max_ans;
void dfs(int cnt,string str) {

	if (cnt == k + 1) {
		if (min_ans == "")min_ans = str;
		else max_ans = str;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			if (cnt > 0) {
				if (v[cnt - 1] == '<' && (str[cnt - 1]-'0') > i)continue;
				else if (v[cnt - 1] ==  '>' && (str[cnt - 1]-'0') < i)continue;
			}
			visited[i] = true;
			dfs(cnt + 1, str + to_string(i));
			visited[i] = false;

		}
	}
}


int main() {
	cin >> k;
	v.resize(k);
	for (int i = 0; i < k; i++)cin >> v[i];

	dfs(0,"");
	cout << max_ans << '\n' << min_ans;
	return 0;
}