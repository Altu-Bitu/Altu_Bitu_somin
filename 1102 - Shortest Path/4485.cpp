//
// Created by Somin on 2021/11/12.
// 4485 녹색옷을 입은 애가 젤다지? - https://www.acmicpc.net/problem/4485
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨

int dijkstra(int n, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0}; //좌 우 하 상
    int dc[4] = {0, 0, -1, 1}; //좌 우 하 상

    int ans = 0; // 정답 저장 변수
    vector<vector<int>> dist(n, vector<int>(n, INF)); // 거리 저장 배열
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq; //큐 선언

    //시작 위치 초기화
    dist[0][0] = board[0][0]; //시작위치 배열[0.0]로 설정
    pq.push(make_pair(dist[0][0], make_pair(0, 0))); // 큐에 삽입

    while (!pq.empty()) {
        int weight = pq.top().first; //edge 저장
        int row = pq.top().second.first; //row 값 가져오기
        int col = pq.top().second.second; //col 값 가져오기
        pq.pop(); //priority queue에서 pop

        if (row == n - 1 && col == n - 1) { //제일 오른쪽 아래 칸 도착
            ans = weight; //정답 업데이트
            break; // 반복문 나가기 (탈출 조건)
        }

        if(weight > dist[row][col]) //이미 확인했던 좌표
            continue; //넘어감

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i]; //row값 업데이트
            int nc = col + dc[i]; //col값 업데이트
            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) //범위를 벗어난다면
                continue; //넘어감

            int next_weight = weight + board[nr][nc]; //시작점으로부터 연결된 좌표까지의 거리
            if (dist[nr][nc] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[nr][nc] = next_weight; // 짧은 경로로 업데이트
                pq.push({next_weight, {nr, nc}}); //큐에 집어넣기
            }
        }
    }

    return ans; //정답 리턴
}

/**
 * 상하좌우로 이동 가능 -> 연결됐다는 것
 * 시작 지점이 (0, 0)인 다익스트라
 */

int main() {
    int n, num = 1; //동굴의 크기 (nxn), 실행 횟수

    while (true) {
        //입력
        cin >> n;
        if (n == 0) break; //탈출 조건

        vector<vector<int>> board(n, vector<int>(n, 0)); //보드 선언
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> board[i][j]; //입력
        }

        //연산 & 출력
        cout << "Problem " << num++ << ": " << dijkstra(n, board) << '\n'; 
    }
}