#include <iostream>
#include <vector>

using namespace std;

struct info{ // 내구도와 로봇 존재 여부 
	int power; // 내구도  
	bool is_on; // 로봇 존재 유무   
};

vector<info> belt; // 컨베이너 벨트 정보(내구도, 로봇여부)
int zero_power; // 내구도가 0인 벨트 칸의 개수 

// 인덱스 감소 싵키기 (방향-> 오른쪽) 
int minusPosition(int n, int pos) { 
	if (--pos >= 0) return pos; // 감소시킨 인덱스가 0이상인 경우 그대로
	return n * 2 - 1; // 0보다 작아지면 다시 맨 끝 (n*2-1) 인덱스로 
}

// 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
void second(int n, int start, int end) {
	int cur = end; // 내리는 위치 -1 부터 검사 시작 
	while (cur != start) { //end - 1 부터 start 까지 검사
		cur = minusPosition(n, cur); // cur 위치 인덱스 감소 시키기 
		int next = (cur + 1) % (n * 2); //다음 위치
		if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
			belt[cur].is_on = false; // 현재 위치에서 지우기 (다음칸으로 옮김)
			belt[next].power--; // 다음칸 내구도 감소시키기 
			if (next != end) // 내리는 위치 아닐 경우만
				belt[next].is_on = true; //로봇 옮기기
			if (belt[next].power == 0) //옮긴 위치 내구도가 0이면 
				zero_power++; //내구도가 0인 칸의 개수 증가시키기 
		}
	}
}

// 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
void third(int start) {
	if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
		belt[start].is_on = true; // 올리는 위치에 로봇 올리기 
		belt[start].power--; // 내구도 감소 시키기 
		if (belt[start].power == 0) // 내구도가 0이면
			zero_power++; // 내구도가 0인 칸의 개수 증가시키기 
	}
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 */

int main() {
	ios_base::sync_with_stdio(false); // 입출력 속도 향상 
	cin.tie(NULL); // 입출력 속도 향상

	int n, k; // n: 칸 수 k: 내구도가 0인 칸의 마지노선 개수 

	// 입력
	cin >> n >> k; // 입력 
	belt.assign(n * 2, { 0,false }); // 컨베이어 벨트 정보 초기화 
	for (int i = 0; i < n * 2; i++) cin >> belt[i].power; // 벨트 내구도 정보 담기 

	// 연산
	int start = 0;    //올리는 위치
	int end = n - 1;  //내리는 위치
	int step = 0;     //단계 수

	while (true) {
		start = minusPosition(n, start); // 올리는 위치 인덱스 감소시키기  
		end = minusPosition(n, end); // 내리는 위치 인덱스 감소시키기 
		
		if (belt[end].is_on) belt[end].is_on = false; //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
		second(n, start,  end); //  로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
		third(start); //올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
		step++; // 단계수 증가 시키기 
		if (zero_power >= k) break; // 내구도가 0인 칸이  마지노선 개수 (k)와 같다면 반복문 종료 

	}

	//출력
	cout << step << '\n'; //  출력

	return 0; 
}