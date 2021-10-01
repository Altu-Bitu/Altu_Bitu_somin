//부등호
#include <iostream>

using namespace std;
const int SIZE = 9;

int k;
char brackets[SIZE + 1]; //부등호 배열
bool check[SIZE + 1]; //수 사용 체크용 

void backtracking(int cnt) {

}

int main() {
	//입력
	cin >> k;
	for (int i = 0; i < k; i++) cin >> brackets[i];

	backtracking(0);
}