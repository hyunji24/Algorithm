#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 2e9+1

//v[i] �� ���� ? �� ���ؼ� ���� 0 �� ������ ����� ����
//?�� ã�� ���� ���Ҹ��� index i+1 ~ ������ ���鼭 ���� ����� �� ã��.. by �̺�Ž��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> v(n);
	long long ans1=0, ans2=0;
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	long long sum = INF;

	for (int i = 0; i < n; i++) { //�� ���Ҹ���
		int start = i + 1;
		int end = n - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			long long tmp = v[i] + v[mid];
			if (abs(tmp) < sum) {
				sum = abs(tmp);
				ans1 = v[i];
				ans2 = v[mid];
			}
			if (tmp < 0)start = mid + 1;
			else end = mid - 1;
		}

	}
	cout << ans1 << " " << ans2;
	return 0;
}