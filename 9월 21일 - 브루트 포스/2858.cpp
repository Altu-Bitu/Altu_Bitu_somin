// 기숙사 바닥 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int r, b; // 8 ≤ R ≤ 5000, 1 ≤ B ≤ 2,000,000
	cin >> r >> b;

	int l, w;
	for (int i = 1; i <= sqrt(b); i++) {
		if (b % i == 0) {
			int temp = b / i;
			if (2 * (temp + i) + 4 == r) {
				if (i >= temp) {
					l = i + 2;
					w = temp + 2;
				}
				w = i + 2;
				l = temp + 2;
				cout << l << ' ' << w ;
				return 0;
			}
		}
	}
	return 0;
}