//동전2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX =  99999;

int main() {
	//입출력속도
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; //동전 종류,합 
	vector<int> coin, dp;

	//입력
	cin >> n >> k;
	coin.assign(n + 1, 0);
	dp.assign(k + 1, MAX);
	for (int i = 1; i <= n; i++) cin >> coin[i];

	//연산
	sort(coin.begin(), coin.end());

	// 주어진 동전을 만들 수 있는 최소 방법은 1가지다. => 초기화
	for (int i = 1; i < coin.size(); i++) {
		dp[coin[i]] = 1;
	}

	for (int i = 1; i < coin.size(); i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	//출력
	if (dp[k] == MAX)
		cout << -1 << '\n';
	else
		cout << dp[k] << '\n';

	return 0;
}