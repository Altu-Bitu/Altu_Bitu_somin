#include <iostream>
using namespace std;

char mat[400][400];

void draw_star(int n, int idx) {
	if (n == 0) return;
	for (int i = 0; i < (4 * (n - 1) + 1); i++) {
		for (int j = 0; j < (4 * (n - 1) + 1); j++) {
			if (i == 0 || i == 4 * (n - 1)) {
				mat[idx + i][idx + j] = '*';
			}
			else {
				if (j == 0 || j == 4 * (n - 1)) {
					mat[idx + i][idx + j] = '*';
					continue;
				}
				mat[idx + i][idx + j] = ' ';
			}
		}
	}
	draw_star(n - 1, idx + 2);
}

int main() {
	int N;
	cin >> N;

	draw_star(N,0);

	for (int i = 0; i < (4 * (N - 1) + 1); i++) {
		for (int j = 0; j < (4 * (N - 1) + 1); j++) {
			cout << mat[i][j];
		}
		cout << "\n";
	}

}