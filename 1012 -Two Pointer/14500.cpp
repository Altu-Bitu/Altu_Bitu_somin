#include <iostream>
#include <vector>

using namespace std;

int ans, n, m; //answer, 행: n 열: m
vector<vector<int>> board; //board 전역변수
int dr[4] = {-1, 1, 0, 0}; //상 하
int dc[4] = {0, 0, -1, 1}; //좌 우

//board[row][col]을 가운데로 하는 +모양 만들기
int horn(int row, int col) {
    int cnt = 0, min_block = 1001, sum = board[row][col]; //블럭 개수, 제일 value적은 블록, 합 저장 변수 선언

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i]; //행 기준 이동
        int nc = col + dc[i]; //열 기준 이동

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue; //다음 순서로 넘어감
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc]; //sum값 업데이트
        cnt++; //블럭 개수 증가
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0;
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum;
    //+
    return sum - min_block; //sum에서 가장자리 블럭 중 가장 값이 작은 애 뺀 값 return 
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { // 기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum); //max 값으로 갱신
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i]; //행 기준 방향
        int nc = col + dc[i]; //열 기준 방향

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue; //다음 순서로 넘어감
        int save = board[nr][nc]; //값 save에 임의로 저장
        board[nr][nc] = 0; //0으로 설정 (백트래킹)
        backtracking(nr, nc, cnt + 1, sum + save); //백트래킹 재귀
        board[nr][nc] = save; //백트래킹에서 복귀 후 원상복귀
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */

int main() {
    //입력
    cin >> n >> m; //행/열 입력받기
    board.assign(n, vector<int>(m, 0)); //보드 initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j]; //보드 initialize
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j]; //값 save에 임의로 저장

            board[i][j] = 0; //0으로 설정 (백트래킹)
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save; //백트래킹에서 복귀 후 값 원상복귀
        }
    }

    //출력
    cout << ans; //정답 출력
}