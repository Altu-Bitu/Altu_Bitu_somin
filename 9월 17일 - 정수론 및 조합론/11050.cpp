#include <iostream>

using namespace std;

int fact(int n) {
	if (n == 0) return 1; // 0 이면 1 (반복문 탈출 조건) 
	return n * fact(n - 1); // 재귀 조건 
}

int main() {
	int n, k, res; // 입력을 위한 변수 & 결과를 저장하기 위한 변수 
	cin >> n >> k; // 입력 받기

	res = fact(n) / (fact(k) * fact(n - k)); // 연산 -> n! / k! * (n-k)! 
	cout << res<< '\n'; // 결과 출력 
}