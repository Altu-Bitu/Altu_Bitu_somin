//퇴사2 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // n일 시간 이익
	cin >> n;

	vector<pair<int, int>> arr(n + 1, {0,0}); // t p 저장 arr
	vector<int> dp(n+2, 0);

	for (int i = 1; i <= n; i++) 
		cin >> arr[i].first >> arr[i].second;
	
	// dp 연산 
	for (int i = 1; i <= n; i++) {
		if (i + arr[i].first <= n + 1) { // 당일에 일하기 
			dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]); // 일 안하기 
	}

	// 출력 
	cout << dp[n + 1] << "\n";

}