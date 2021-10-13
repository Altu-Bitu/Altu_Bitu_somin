#include <iostream>
#include <cmath>

using namespace std;


int calcGCD(int x, int y) { // 항상 x >= y 이므로 대소관계를 체크하지 않음
	int tmp; // gcd 저장 위해 
	while (y != 0) {
		tmp = x % y; 
		x = y;
		y = tmp;
	}
	return x;
}

int main() {
	int gcd, lcm; // 최대공약수, 최소공약수 
	cin >> gcd >> lcm; // 입력 

	//연산
	int ab = lcm / gcd;
	int a = -1, b = -1;
	//a, b의 차이가 가장 작을 제곱근부터 체크
	for (int i = sqrt(ab); i > 0; i--) {
		if (ab % i != 0) continue;
		//i가 ab의 약수라면
		int tmp_a = i, tmp_b = ab / i;
		//두 수가 서로소인지 체크 -> 만약 두 수가 서로소가 아니라면 두 수의 최대공약수가 gcd가 될 수 없음
		if (calcGCD(tmp_b, tmp_a) == 1) {
			a = tmp_a;
			b = tmp_b;
			break;
	}
		
		cout << a * gcd << ' ' << b * gcd; //출력
}