//야구
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; //이닝 정보 저장 벡터 배열 
vector<int> order(10, 0); //타순
vector<bool> check(10, false); //백트래킹시 이용 배열 
int n, ans; //전체 수, 정답 

//현재 배치의 점수 계산하기 
int calcScore() {
	int score = 0; //총 점수
	int idx = 1; // 타순 지정된 order 인덱스 번호
	for (int i = 0; i < n; i++) {//i: 이닝
		vector<bool> baseman(4, 0); // 각 루마다 선수가 있는지
		int out = 0; //아웃 선수 카운트 
		while (out < 3) {
			int state = innings[i][order[idx++]];//현재 선수의 공격 상태
			if (idx == 10) idx = 1; //아닝이 끝나지 않았을때 처음 1번부터 다시 시작
			switch (state) { //state값에 따라 다른 case 
			case 0: //아웃의 경우 
				out++; //out 수증가 
				break; //case 빠져나오기 
			case 1: //안타, 1루씩 진루
				score += baseman[3]; //3루에 있는 선수있다면 홈 도착
				for (int i = 3; i > 0; i--)
					baseman[i] = baseman[i - 1]; //1루씩 진루 
				baseman[1] = 1; //새로운 선수 1루에 도착
				break; //case 빠져나오기 
			case 2: //2루타, 2루씩 진루
				score += baseman[3] + baseman[2]; //3루, 2루에 선수 있다면 홈 도착
				baseman[3] = baseman[1]; //1루 -> 3루 이동
				baseman[2] = 1; //새로운 선수 2루에 도착
				baseman[1] = 0; //초기화
				break; //case 빠져나오기 
			case 3: //3루타, 3루씩 진루
				for (int i = 3; i > 0; i--) {
					score += baseman[i]; //3루, 2루, 1루에 선수 있다면 홈 도착
					baseman[i] = 0; //빈자리로 업데이트 
				}
				baseman[3] = 1; //새로운 선수 3루에 도착
				break; //case 빠져나오기 
			case 4: //홈런
				for (int i = 3; i > 0; i--) {
					score += baseman[i];
					baseman[i] = 0;
				}
				score++; //새로운 선수도 홈 바로 도착
				break; //case 빠져나오기 
			}
		}
	}

	return score;  //점수 넘겨주기 
}

void array_check(int cnt) {//cnt : 타자 순서 
	if (cnt == 4) {
		array_check(cnt + 1); // 4번 타자는 정해져 있으므로 
		return; //종료 
	}
	if (cnt == 10) {//9번 타자까지 정해짐 (기저 조건)
		int score = calcScore(); //점수 계산
		ans = max(ans, score); // ans 최대 점수로 설정
		return; //종료
	}
	for (int i = 2; i <= 9; i++) {
		if (!check[i]) {
			order[cnt] = i; //타자: i번 선수 
			check[i] = true; //i번 선수 순서 정해짐
			array_check(cnt + 1); //다음 타자
			check[i] = false; //원상복귀 시켜주기 
		}
	}

}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */


int main() {
	//입력
	cin >> n; //입력 
	innings.assign(n, vector<int>(10, 0)); //이닝 배열 초기화 
	for (int i = 0; i < n; i++){
		for (int j = 1; j < 9; j++) {
			cin >> innings[i][j]; //입력받기 
		}
	}

	//연산
	order[4] = 1; //4번 타자는 1번 선수
	check[1] = true; //1번 선수 순서 정해짐
	array_check(1); //함수 호출 

	//출력
	cout << ans << '\n'; //정답 출력 

	return 0;

}