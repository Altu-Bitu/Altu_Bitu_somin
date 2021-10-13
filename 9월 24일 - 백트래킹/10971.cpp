//외판원
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE  = 10;

int n, idx, min_val = 1000000;
int arr[SIZE + 1][SIZE + 1]; //경로 
bool check[SIZE + 1]; //체크배열 

void backtracking(int flag, int cnt, int sum) {
	// 탈출조건
	if (cnt == n - 1) {
		int final = arr[flag][idx];
		if (final == 0) return;
		sum += final;
		min_val = min(min_val, sum);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i] && arr[flag][i]) {
			check[i] = true;
			backtracking(i, cnt + 1, sum+arr[flag][i]);
			check[i] = false;
		}
	}
}
int main() {
	//입력
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	//연산
	for (int i = 0; i < n; i++) {
		idx = i;
		check[i] = true;
		backtracking(i, 0, 0);
		check[i] = false;
	}
	//출력
	cout << min_val;
}