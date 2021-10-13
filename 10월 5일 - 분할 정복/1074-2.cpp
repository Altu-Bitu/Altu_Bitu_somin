//z그리기
#include <iostream>

using namespace std;
int result = 0;

void draw_z(int n, int r, int c) {
	int length = 1 << n-1; // 2^(n-1) 길이 (현재 절반 길이)
	
	int y = length; // y축
	int x = length;  // x축
	
	if (n == 0) return; //탈출조건

	if (r < x && c < y ) {
		return draw_z(n-1, r, c);
	}
	else if (r < x && c >= y) {
		result += length * length;
		return draw_z(n-1, r, c-length);
	}
	else if (r >= x && c < y) {
		result += length * length * 2;
		return draw_z(n-1, r - length, c);
	}
	else {
		result += length * length * 3;
		return draw_z(n-1, r - length, c - length);
	}


}

int main() {
	int n, r, c;
	
	//입력
	cin >> n >> r >> c;

	//연산
	draw_z(n, r, c);

	//출력
	cout << result << '\n';

	return 0;
}