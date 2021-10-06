//롤케이크 먹고싶다 
//틀림

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0, cnt = 0;

int roll_cake(int m, vector<int>& cake) {
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
*/

int main() {
	int n, m, temp; 
	

	//입력
	cin >> n >> m;
	vector<int> cake_1;
	vector<int> cake_0;

	while (n--) {
		cin >> temp;
		if(temp % 10 != 0) cake_1.push_back(temp); //10의 배수 아닌 length
		else { //10의 배수
			if (temp == 10) {
				ans++;
				continue;
			}
			cake_0.push_back(temp); //10의 배수 모아 놓기 	
		}
	}

	//연산 & 출력
	sort(cake_0.begin(), cake_0.end());
	sort(cake_1.begin(), cake_1.end()); 
	
	roll_cake(m, cake_0);
	if (cnt == m) {
		cout << ans;
		return 0;
	}

	cout << roll_cake(m, cake_1);
	return 0;
}