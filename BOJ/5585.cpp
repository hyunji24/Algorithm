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
int arr[6] = { 500,100,50,10,5,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input;
	cin >> input;
	
	int money = 1000 - input;


	int idx=0;
	
	int answer=0;
	for (int i = 0; i < 6; i++) {
		if (money / arr[i] > 0) {
			int num = money / arr[i];
			answer += num;
			money -= num * arr[i];
			
		}
	}
	
	cout << answer;
	return 0;
}