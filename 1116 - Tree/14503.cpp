//
// Created by Somin on 2021/11/23.
// 14503 로봇청소기 - https://www.acmicpc.net/problem/14503
//

#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    int dr[4] = {-1, 0, 1, 0}; //row방향 상 우 하 좌
    int dc[4] = {0, 1, 0, -1}; //col방향 상 우 하 좌

    int step = 0, ans = 0; //step, ans 초기화
    while (true) {
        if (board[r][c] == 0) { //빈칸이라면
            board[r][c] = 2; //청소한 공간 표기
            ans++; //ans 증가
        }

        if (step == 4) { //제자리로 돌아왔을 경우
            if (board[r - dr[d]][c - dc[d]] == 1) return ans; //벽이라면, 정답 리턴
            r -= dr[d]; //방향 바꿔서 row 업데이트
            c -= dc[d]; //방향 바꿔서 col 업데이트
            step = 0; //step 다시 0으로 초기화
        } else {
            d = (d + 3) % 4; //방향 계산
            if (board[r + dr[d]][c + dc[d]]) { //빈칸이 아니라면
                step++; //step 증가
                continue; //건너띄기
            }
            r += dr[d]; //방향 바꿔서 row 업데이트
            c += dc[d]; //방향 바꾸어서 col 업데이트
            step = 0; //step 초기화
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d; //세로, 가로, 좌표, 방향

    //입력
    cin >> n >> m >> r >> c >> d; //입력
    vector<vector<int>> board(n, vector<int>(m, 0)); //보드 할당

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; //보드 입력받기
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);

    return 0;
}