//
// Created by Somin on 2021/11/09.
// 15685 드래곤 커브 - https://www.acmicpc.net/problem/15685
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> ci;
const int MAX = 101;

// 우 -> 상 -> 좌 -> 하 ( 시계 방향으로 90도 씩 이동)
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

//크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것이 개수 구하기
int cntSquare(vector<vector<bool>> &board) {
    int ans = 0; //정답 (사각형 수) 저장
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) //사각형 꼭짓점 모두 포함된다면
                ans++; // 1증가
        }
    }
    return ans; //정답 리턴
}

ci dragonCurve(vector<vector<bool>> &board, vector<int> &direc, ci point) {
    int size = direc.size(); //그 전 세대까지의 방향 정보
    for (int i = size - 1; i >= 0; i--) {
        int new_direc = (direc[i] + 1) % 4; //현재 시작 점의 방향
        point = {point.first + dy[new_direc], point.second + dx[new_direc]}; //현재 끝 점
        board[point.first][point.second] = true; //보드 업데이트
        direc.push_back(new_direc); //방향 업데이트
    }
    return point; //마지막 위치 리턴
}

int main(){
    int n, x, y, d, g; // 개수, 위치 (x,y), 시작방향, 세대
    vector<vector<bool>> board; //board 선언
    board.assign(MAX, vector<bool>(MAX, 0)); //100x100 보드 생성

    //입력 & 연산
    cin >> n; //총 연산 회수 입력
    while(n--){
        cin >> x >> y >> d >> g; // 위치, 시작방향, 세대 입력
        vector<int> direction; //세대의 방향 정보 저장
        ci end_point = {y+ dy[d], x+dx[d]}; //0세대 끝점 업데이트
        board[y][x] = board[end_point.first][end_point.second] = true; //0세대 시작점, 초기화
        direction.push_back(d); //방향 삽입
        while(g--){ //각 세대마다 드래곤 커브 만들기
            end_point = dragonCurve(board, direction ,end_point);
        }
    }
    //출력
    cout << cntSquare(board) << '\n';
    return 0;
}

