//행렬
#include <iostream>
#include <vector>

using namespace std;

int cal_min(vector<vector<char>>& a, vector<vector<char>>& b) {
	int ans = 0;
	int col = a.size();
	int row = a[0].size();

	for (int i = 0; i <= col - 3; i++) {
		for (int j = 0; j <= row - 3; j++) {
			if (a[i][j] != b[i][j]) {
				ans++;
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						if (a[k][l] == '0') a[k][l] = '1';
						else a[k][l] ='0';
					}
				}
			}
		}
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (a[i][j] != b[i][j]) {
				return -1;
			}
		}
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat_a(n, vector<char>(m, 0));
	vector<vector<char>> mat_b(n, vector<char>(m, 0));

	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat_a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat_b[i][j];
		}
	}

	//연산 & 출력
	cout << cal_min(mat_a, mat_b);
}