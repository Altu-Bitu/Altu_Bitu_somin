//z그리기
#include <iostream>

using namespace std;

int draw_z(int n, int r, int c) {
	int ans = 0;

	int x = 1 << (n - 1); // x = 2^(n-1)
	int y = x;

	while (n-- > 0) {
		int temp = 1 << (n - 1); // 현재 사분면의 길이 /2 
		int skip = 1 << 2 * n; // 방문했다고 가정하는 수의 크기 

		if (r < y && c < x) {
			// 1사분면
			x -= temp;
			y -= temp;
		}
		else if (r < y && x <= c) {
			// 2사분면
			ans += skip;
			x += temp;
			y -= temp;
		}
		else if (y <= r && c < x) {
			// 3사분면 
			ans += skip * 2;
			x -= temp;
			y += temp;
		}
		else {
			// 4사분면
			ans += skip * 3;
			x += temp;
			y += temp;
		}
	}
	return ans;
}

int main() {
	int n, r, c; // 크기: 2^n row col
	
	//입력
	cin >> n >> r >> c;

	//연산 & 출력
	cout << draw_z(n, r, c);
	
	return 0;
}