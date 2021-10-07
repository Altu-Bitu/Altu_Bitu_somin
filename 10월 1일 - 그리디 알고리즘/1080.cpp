//행렬
#include <iostream>
#include <vector>

using namespace std;

void flip(vector<vector<char>>& a, vector<vector<char>>& b,int col, int row ) {
	for (int i = col; i < col + 3; i++) {
		for (int j = row; j < row + 3; j++) {
			if (a[i][j] == '0') a[i][j] = '1';
			else a[i][j] = '0';
		}
	}
}

int cal_min(vector<vector<char>>& a, vector<vector<char>>& b) {
	int ans = 0;
	int col = a.size();
	int row = a[0].size();

	for (int i = 0; i <= col - 3; i++) {
		for (int j = 0; j <= row - 3; j++) {
			if (a[i][j] != b[i][j]) {
				ans++;
				flip(a, b, i, j);
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