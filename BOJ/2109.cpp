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
	int p;
	int d;
	bool operator<(const Info& b)const{
		return p < b.p;
	}
};
bool chk[10001];
int answer = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	priority_queue <Info> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		pq.push({ p,d });
	}

	while (!pq.empty()) {
		int p = pq.top().p;
		int d = pq.top().d;
		pq.pop();
		while (chk[d] != false)d--;
		if (d > 0) {
			chk[d] = true;
			answer += p;
		}
		
	}

	cout << answer;
	return 0;

}