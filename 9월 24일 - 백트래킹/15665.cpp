// N과 M 
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7;

int n, m;
int num[SIZE]; //수열 
int res[SIZE]; //결과 저장 수열 
//bool check[SIZE + 1]; //수 사용 체크 배열은 필요 없음 

void backtracking(int cnt) {
	int prev = -1; 

	//탈출 조건
	if (cnt == m) { 
		for (int i = 0; i < cnt; i++) cout << res[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (prev != num[i]) {
			res[cnt] = num[i]; //결과 배열 저장
			prev = num[i]; //prev update
			backtracking(cnt + 1); 
		}
	}
}
int main() {
	cin >> n >> m; //입력

	for (int i = 0; i < n; i++) cin >> num[i]; //0번 부터 채우기 

	sort(num,num+n);
	backtracking(0); 

}