// 퇴사
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> day(n + 1, 0);
	vector<int> cost(n + 1, 0);
	vector<int> result(n + 1, 0);
	
	// 입력 
	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> cost[i];
	}

	// 연산 
	for (int i = 0; i < n; i++) {
		if (i + day[i] > n) continue;

		if (result[i] + cost[i] > result[i + day[i]]) {
			result[i + day[i]] = result[i] + cost[i];

			for (int j = i + day[i]; j <= n; j++) {
				if (result[j] < result[i + day[i]]) {
					result[j] = result[i + day[i]];
				}
			}
		}
	}
	cout << result[n];

}