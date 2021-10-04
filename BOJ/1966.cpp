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

bool cmp(int a,int b) {
	return a > b;
}


int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int> > q;
		vector<int> imp;

		for (int i = 0; i < n; i++) {
			int doc; cin >> doc;
			imp.push_back(doc);
			q.push({ i,doc });

		}
		int answer = 0;
		sort(imp.begin(), imp.end(), cmp); //중요도 큰 순서대로 들어있음
		
		int idx = 0;

		while (!q.empty()) {

			while (q.front().second != imp[idx]) {
			int order = q.front().first;
			int score = q.front().second;
				q.pop();
				q.push({ order,score });
			}
			
			idx++;
			answer++;
			if (q.front().first == m)break;
			q.pop();
			
		}
		cout << answer << endl;

	}
}