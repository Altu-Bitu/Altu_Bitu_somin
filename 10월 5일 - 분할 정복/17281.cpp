//야구
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max_score = 0;
vector<vector<int>> inning;

void baseBall() {
	
}

/*
* 문제 제대로 읽기 -> 1번선수가 4번 타자임 (4번타자가 1번 선수가 아니라!!)
* 모든 경우의 수를 다 해보기 - 입력 별로 안큼 (n <= 50) -> 백트래킹 사용..? 
*/

int main() {
	int n;
	
	//입력
	cin >> n;
	inning.assign(n, vector<int>(9, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 9; j++) {
			cin >> inning[i][j];
		}
	}

}