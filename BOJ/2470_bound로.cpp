#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 2e9+1
vector<int> answer;
bool flag = false;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	long long sum = INF;
	for (int i = 0; i < n; i++) {
		int tmpIdx = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();
		for (int j = tmpIdx; j >= tmpIdx - 1; j--) {
			if (j >= n||j<0 ||i==j)continue; //i==j 인 경우 안쓰면 틀린다...
			//i==j는 -14 15 ~ 에서 i=0이고 tmpIdx=1같은 경우?
			if (abs(v[i] + v[j]) < sum) {
				sum = abs(v[i] + v[j]);
				answer.clear();
				answer.push_back(v[i]);
				answer.push_back(v[j]);
				if (sum == 0) {
					flag = true;
					break;
				}
			}
		}
		if (flag)break;
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)cout << answer[i]<<" ";
	return 0;

}