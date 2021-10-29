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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int> > info(n);
	vector<int>grade(n, 1);

	for (int i = 0; i < n; i++) 
		cin >> info[i].first >> info[i].second;
	

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (info[i].first > info[j].first && info[i].second > info[j].second)grade[j]++;
			else if (info[i].first < info[j].first && info[i].second < info[j].second)grade[i]++;
			else continue;

		}
	}

	for (int i = 0; i < n; i++)cout << grade[i] << " ";
	return 0;

}