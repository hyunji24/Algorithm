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
int answer = 0; 
stack<int> st[7]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n >> p;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		int num, fret;
		cin >> num >> fret;
		
		if (st[num].empty()) {
			st[num].push(fret);
			answer++;
		}
		else {
			while (!st[num].empty() && st[num].top() > fret)
			{
				st[num].pop();
				answer++;
			}
			if (st[num].empty() || st[num].top() != fret) {
				st[num].push(fret);
				answer++;
			}
			
		}

	}

	cout << answer;
	return 0;

	

}