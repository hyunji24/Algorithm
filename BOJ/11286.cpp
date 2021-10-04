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
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))return a > b;
		else return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	

	priority_queue<int,vector<int>,cmp> pq;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num == 0) {
			if (pq.empty())cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else pq.push(num);
		
	}

}