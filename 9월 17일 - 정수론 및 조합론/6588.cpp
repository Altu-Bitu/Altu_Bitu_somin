#include <iostream>
#include <vector>
#define SIZE 1000000

using namespace std; 

// 에라토스테네스의 채를 이용해 미리 SIZE까지의 소수 판별 
vector<bool> isPrime() {
	vector<bool> is_prime(SIZE + 1, true); //소수 판단 여부 저장

	is_prime[0] = is_prime[1] = false; // 0과 1 소수 아님 
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (is_prime[i]) { //i가 소수라면
			for (int j = i * i; j <= SIZE; j += i)
				is_prime[j] = false; //i의 배수 제거
		}
	}

	return is_prime;
}

//골드바흐의 추측 판단 함수
int checkGoldbach(int n, vector<bool>& is_prime) {
	for (int i = 3; i <= n / 2; i += 2) { //홀수만 검사, n/2 이상의 값은 어차피 n-i를 통해 검사되므로 n/2까지 검사
		if (is_prime[i] && is_prime[n - i]) { //두 홀수 모두 소수라면 (골드바흐의 추측이 맞은 경우)
			return i; //두 홀수 소수 중 작은 값 리턴
		}
	}
	return 0; //골드바흐의 추측이 틀린 경우
}

int main() {
	// 입출력속도 향상 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	int n; // 입력 받을 숫자 선언 
	vector<bool> is_prime = isPrime(); // 소수 판단 여부 저장


	while (true) {
		cin >> n; // 입력받기 
		if (n == 0) return; // 0이면 조건 탈출

		int prime = checkGoldbach(n, is_prime); //골드바흐 추측 맞는지 확인
		if(prime)  cout << n << " = " << prime << " + " << n - prime << '\n'; // 두 홀수 소수 중 작은 값 리턴받은 경우 
		else cout << "Goldbach's conjecture is wrong.\n"; // 0 (틀린 경우)

	}

	return 0; 
}