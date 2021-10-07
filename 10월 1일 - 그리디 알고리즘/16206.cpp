//롤케이크 먹고싶다 

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int ans = 0;

int roll_cake(deque<int>& cake, int m) {
	int cnt = 0;
	for (int i = 0; i < cake.size(); i++) {
		while (cake[i] >= 10) {
			if (cake[i] == 10) { // 길이가 10이라면
				ans++;
				break;
			}
			if (cnt == m) return ans;

			cnt++; // 증가 
			cake[i] -= 10;
			ans++;
		}
	}
	return ans;
}

/* 
* 10의 배수가 들어올 때 -> 10의 배수끼리도 정렬 해줘야 함! ( 10 , 20, 30, 40 예시) 
* 10의 배수가 아닐 때 -> 굳이 정렬할 필요 없음 (ex 12 23) -> 함수 하나로 컨테이너 활용 
* 
* 10으로 자르는 부분 -> 수학적으로 한번에 해결 가능
*/

int main() {
	int n, m, temp, cnt = 0; 
	
	//입력
	cin >> n >> m;
	deque<int> cake;
	//cake.assign(n, 0);

	while (n--) {
		cin >> temp;
		if (temp % 10 == 0) {
			cake.push_front(temp);
			cnt++;
		}
		else 
			cake.push_back(temp);
		
	}

	//연산 & 출력
	sort(cake.begin(), cake.begin()+cnt);
	cout << roll_cake(cake, m);

	return 0;
}