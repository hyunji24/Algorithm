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
	int order,num;
};

bool cmp(Info& a, Info& b) {
	return a.num < b.num;
}



vector<Info> info;
vector<Info> frame;
int recommend[101]; //��õȽ��


int main() {

	int n;
	cin >> n;
	frame.resize(n);
	int m;
	cin >> m;

	
	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		info.push_back({ i,num });
	}

	
	for (int i = 0; i < m; i++) {
		bool replace = true;
		for (int j = 0; j < n; j++) { //�Ȱ����� ���� ��
			if (frame[j].num == info[i].num) {
				recommend[info[i].num]++;
				replace = false;
				break;
			}
		}
		if (!replace)continue;

		for (int j = 0; j < n; j++) { //Ʋ ���������
			if (frame[j].num == 0) {
				frame[j] = info[i];
				recommend[info[i].num]++;
				replace = false;
				break;
			}
		}
		if (!replace)continue;


		//��ü�ؾߵɶ�
		int target = 0; // ��ü�ؾ� �� ������ �ε���
		for (int j = 0; j < n; j++) {
			if (recommend[frame[j].num] < recommend[frame[target].num])
				target = j;
			else if (recommend[frame[j].num] == recommend[frame[target].num]) 
			{
				if (frame[j].order < frame[target].order)
					target = j;
			}
		}
		recommend[frame[target].num] = 0;
		frame[target] = info[i];
		recommend[info[i].num]++;

	}

	sort(frame.begin(), frame.end(), cmp);
	for (int i = 0; i < frame.size(); i++)cout << frame[i].num << " ";
	return 0;
}