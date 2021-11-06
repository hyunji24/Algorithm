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
struct Info {
	int start, end;
};

bool cmp(Info& a, Info& b) {
	return a.end < b.end;
}

vector<Info > v;
int main() {
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].start >> v[i].end;
	}
	sort(v.begin(), v.end(), cmp);

	

	int nowend = v[0].end;
	int answer = 1;


	for (int i = 1; i < n; i++) {
		if (v[i].start >= nowend) {
			answer++;
			cout << "(" << v[i].start << "." << v[i].end << ")" << endl;
			nowend = v[i].end;
		}
	}

	cout << answer;
	return 0;
}