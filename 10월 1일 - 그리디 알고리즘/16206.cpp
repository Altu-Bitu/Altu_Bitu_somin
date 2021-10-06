//롤케이크 먹고싶다 
//틀림

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cake;
int ans = 0;

int roll_cake(int m, int cnt) {
	for (int i = 0; i < cake.size(); i++) {
		while (cake[i] >= 10) {
			if (cake[i] == 10) { // 길이가 10이라면
				ans++;
				break;
			}
			if (cnt == m) return ans;

			cnt++; // 증가 
			cake[i] -= 10;
			ans++;
		}
	}
	return ans;
}

int pre_roll(int num, int m, int cnt) {
	while (num >= 10) {
		if (num == 10) {
			ans++;
			break;
		}
		if (cnt == m) return cnt;

		cnt++;
		num -= 10;
		ans++;
	}
	return cnt;
}

int main() {
	int n, m; 
	int cnt = 0; // 자른 횟수 count 

	//입력
	cin >> n >> m;
	cake.assign(n, 0);

	while (n--) {
		int temp; 
		cin >> temp;
		if(temp % 10 != 0) cake.push_back(temp); //10의 배수 아니면 push
		else {
			if (temp == 10) ans++;
			else { //10이 아닌 10의 배수 일 경우
				cnt = pre_roll(temp, m, cnt);
				if (cnt == m) {
					cout << ans;
					return 0;
				}
			}
		}
	}
	//연산 & 출력
	sort(cake.begin(), cake.end()); 
	cout << roll_cake(m, cnt);

	return 0;
}