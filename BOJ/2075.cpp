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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			pq.push(num);
			if (pq.size() > n)
				pq.pop();

			
		}
	
	
	}

	cout << pq.top();
	return 0;
}