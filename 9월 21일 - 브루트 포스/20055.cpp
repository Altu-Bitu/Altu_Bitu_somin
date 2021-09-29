// 컨베이어 벨트 위의 로봇 
// 잘 모르겠어요 ㅠㅠㅠㅠㅠㅠㅠㅠㅠ

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void rotation(deque<int>& duration, deque<bool>& robot_present, int n) {
	// duration rotate 
	duration.push_front(duration.back());
	duration.pop_back();

	// robot present rotate 
	robot_present.push_front(robot_present.back());
	robot_present.pop_back();
}

int check_duration(deque<int>& duration , int n) {
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (duration[i] == 0) cnt++;
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, num , ans = 0;
	cin >> n >> k;

	deque<int> duration;
	deque<bool> robot_present;

	for (int i = 0; i < 2 * n; i++) {
		cin >> num;
		robot_present.push_back(false);
		duration.push_back(num);
	}

	while (true) {
		if (check_duration(duration, n) == k) {
			cout << ans << '\n';
			return;
		}
		ans++;

	}

	return 0;
}