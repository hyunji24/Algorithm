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
bool visited[1000000];
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int k;
		cin >> k;
		priority_queue <pair<int, int>> max_pq;
		priority_queue < pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> min_pq;
		for (int j = 0; j < k; j++) {
			char ch;
			int num;
			cin >> ch >> num;
			if (ch == 'I') {
				max_pq.push({ num,j });
				min_pq.push({ num,j });
				visited[j] = true;

			}
			else {
				if (num == 1)
				{
					while (!max_pq.empty() && !visited[max_pq.top().second]) {
						max_pq.pop();
					}
					if (!max_pq.empty()) {
						visited[max_pq.top().second] = false;
						max_pq.pop();
					}
				}
				else if (num == -1) 
				{
					while (!min_pq.empty() && !visited[min_pq.top().second]) {
						min_pq.pop();
					}
					if (!min_pq.empty()) {
						visited[min_pq.top().second] = false;
						min_pq.pop();
					}
				}
			}
		}

		while (!max_pq.empty() && visited[max_pq.top().second] == false)max_pq.pop();
		while (!min_pq.empty() && visited[min_pq.top().second] == false)min_pq.pop();
		if (max_pq.empty() && min_pq.empty())cout << "EMPTY" << endl;
		else cout << max_pq.top().first << " " << min_pq.top().first << endl;
	}
}