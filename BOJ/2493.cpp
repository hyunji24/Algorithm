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
int tower[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<pair<int, int> > st;
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;

		while (!st.empty()) {
			if (st.top().second > height) {
				cout << st.top().first << " ";
				st.push({ i,height });
				break;
			}
			st.pop();
		}

		if (st.empty()) {
			cout << 0 << " ";
			st.push({ i,height });
			
		}
	}


		
	
	return 0;
}