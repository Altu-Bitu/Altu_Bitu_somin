//뱀 
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>


using namespace std;
typedef pair<int, int> ci; 

ci dir[4] = { {0,1}, {-1,0},{0,-1},{1,0} }; // right up left down  (방향 변환 위해)

// 게임 진행
int snakeGo(int n, vector<vector<int>>& board, map<int, char>& cmd) {
	//뱀 initialize
	deque<ci> snake; //뱀의 머리,꼬리 위치 저장 위해 deque 선언
	snake.push_front(ci(0, 0));  // 초기 정보 -> 머리,꼬리 0번에 위치
	board[0][0] = 1;  //보드상에서의 위치 저장

	int t = 0, head = 0; // 시간, 뱀의 머리 방향
	while (true) {
		t++; // 시간 증가(1초) 
		//뱀의 머리가 위치하게될 칸
		int n_row = snake.front().first + dir[head].first; //머리 이동 위치 (row)
		int n_col = snake.front().second + dir[head].second; //머리 이동 위치 (col)

		//게임 종료 조건 : 벽에 부딪히거나 자기자신과 부딪힘
		if (n_row < 0 || n_row >= n || n_col < 0 || n_col >= n || board[n_row][n_col] == 1) break;

		if (board[n_row][n_col] != 2) {
			//이동할 칸에 사과가 없다면 몸길이 줄여서 꼬리가 위치한 칸 비워두기 
			board[snake.back().first][snake.back().second] = 0; //board 꼬리칸 없애기 
			snake.pop_back(); //뱀 tail 에서도 update 
		}
		//뱀은 몸길이 늘려 다음칸에 위치
		snake.push_front(ci(n_row, n_col)); //snake head update
		board[n_row][n_col] = 1; //board도 update

		//방향 변환하는지 확인
		if (cmd[t] == 'L') head = (head + 1) % 4; //왼쪽 회전 
		if (cmd[t] == 'D') head = (head + 3) % 4; //오른쪽 회전

	}

	return t; // 시간 return
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0, 0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
 * -> 덱의 front : 머리, 덱의 back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */


int main() {
	int n, k, row, col, l, x; //보드 칸 길이, 사과 수, row, col,방향 전환 시간
	char c; //방향 정보 

	//입력 
	cin >> n >> k; // 입력 받기 
	vector<vector<int >> board(n, vector<int>(n)); //n*n 보드칸 생성 
	for (int i = 0; i < k; i++) {
		cin >> row >> col; //사과가 존재하는 위치 입력받기 
		board[row - 1][col - 1] = 2; // 사과 표시 
	}

	cin >> l; //방향 전환 수 입력받기 
	map<int, char> cmd; //이동방향 저장 map생성 -> 왜 맵 썼지???
	for (int i = 0; i < l; i++) {
		//방향 정보 
		cin >> x >> c;  // 전환 시간, 수 입력
		cmd[x] = c; // map에 정보 저장
	}

	//연산 & 출력
	cout << snakeGo(n, board, cmd); //연산과 출력 
	return 0; //종료
}