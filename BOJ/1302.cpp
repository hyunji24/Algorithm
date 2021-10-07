#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string> 
#include <stack>
#include<map>
using namespace std;
int max_num = 0;
vector<string>answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	map<string, int> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		m[str]++;
	}

	for (auto p : m) {
		if (p.second > max_num) max_num = p.second;
	}
	for (auto p : m) {
		if (p.second == max_num)answer.push_back(p.first);
	}

	sort(answer.begin(), answer.end());
	cout << answer[0];
	return 0;


}