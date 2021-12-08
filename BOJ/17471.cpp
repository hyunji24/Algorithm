#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
int people[11];
vector<int> node[11];
bool selected[11];
int ans = 987654321;
int ch[100];

bool isConnected(vector<int>& v, int flag) { //vector v���� ���Ұ� �� ����Ƴ�

	queue<int> q;
	int visited[11];
	memset(visited, false, sizeof(visited)); //memset!! ���ϴϱ� Ʋ��
	visited[v[0]] = true;
	q.push(v[0]);
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < node[x].size(); i++) {
			if (ch[node[x][i]] == flag && visited[node[x][i]] == false) {
				visited[node[x][i]] = true;
				q.push(node[x][i]);
				cnt++;
			}
		}


	}
	if (cnt == v.size())return true;
	else return false;
}
bool isOk() { //2�� ���ű� ���� ����ƴ��� Ȯ��
	vector<int> left;
	vector<int> right;
	for (int i = 1; i <= n; i++) {
		if (ch[i] == 1)left.push_back(i);
		else right.push_back(i);
	} //left: ù��° ���ű�(���� dfs�� ���� ����), right: �ι�° ���ű�(������)

	if (left.empty() || right.empty()) return false;
	if (!isConnected(left, 1) || !isConnected(right, 0))return false;
	return true;

}

void calc() {
	int leftsum = 0, rightsum = 0;
	for (int i = 1; i <= n; i++) {
		if (ch[i] == true)leftsum += people[i];
		else rightsum += people[i];
	}

	ans = min(ans, abs(leftsum - rightsum));
}

void dfs(int x) {
	if (x == n + 1) {
		if (isOk())
			calc();
	}
	else { //��ü �κ����ձ��ϴ� �ڵ忡�� else�ݵ�� ����ߵ�
		ch[x] = 1;
		dfs(x + 1);
		ch[x] = 0;
		dfs(x + 1);
	}
}

int main() {
	memset(ch, 0, sizeof(ch));
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> people[i];
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int tmp;
			cin >> tmp;
			node[i].push_back(tmp);
			node[tmp].push_back(i);
		}
	}
	dfs(1);
	if (ans != 987654321)cout << ans;
	else cout << "-1";
	return 0;
}