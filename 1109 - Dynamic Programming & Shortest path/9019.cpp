//
// Created by Somin on 2021/11/16.
// 9019 DSLR - https://www.acmicpc.net/problem/9019
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, char> ci;
const int SIZE = 10000; //최대 사이즈 (A/B)

//역추적
string back(int x, vector<ci> &path) { //x = B부터 역추적 시작
    string ans = ""; //정답 저장 string
    while (path[x].first != -1) {
        ans += path[x].second; //정답 string update
        x = path[x].first; //path이동
    }
    reverse(ans.begin(), ans.end()); //순서 재배열
    return ans; //정답 string return
}

//bfs
void bfs(int a, int b, vector<ci> &path) {
    vector<bool> visited(SIZE, false); //visited 배열 생성
    queue<int> q; //큐 (bfs에 사용) 생성

    q.push(a); //시작 노드 초기화
    visited[a] = true; //visited에 첫번쨰 노드 반영

    while (!q.empty()) {
        int cur = q.front(); //q에서 꺼내기
        q.pop(); //q에서 제거

        if (cur == b) //B를 만들었다면 즉시 탐색 종료
            break; //탐색 종료

        vector<ci> child = {{cur * 2 % SIZE,                   'D'}, //D
                            {(cur - 1 + SIZE) % SIZE,          'S'}, //S
                            {(cur * 10 % SIZE) + (cur / 1000), 'L'}, //L
                            {(cur % 10 * 1000) + (cur / 10),   'R'}}; //R

        for (int i = 0; i < 4; i++) { //4가지 경우 순회
            int next = child[i].first;
            if (!visited[next]) { //처음 방문이라면
                q.push(next); //큐에 넣기
                visited[next] = true; //방문 배열 업데이트
                path[next] = ci(cur, child[i].second); //자식 노드에 부모 노드(경로)와 명령어 저장
            }
        }
    }
}

/**
 * path: 경로와 수행한 명령어(D, S, L, R)를 저장
 *
 * 각 명령어의 수행 결과를 사칙연산으로 나타낼 수 있음 (cur: 현재 수, SIZE = 10,000)
 * D: cur * 2 % SIZE
 * S: (cur - 1 + SIZE) % SIZE (cur이 0일 경우를 처리하기 위해)
 * L: (cur * 10 % SIZE) + (cur / 1000)
 * R: (cur % 10 * 1000) + (cur / 10)
 *
 * 따라서 위의 연산을 적용한 값들을 자식노드로 하여 bfs 탐색 진행
 * 앞서 구한 path값을 따라 B인덱스부터 역추적 시작
 */

int main() {
    int t, a, b; //테스트 케이스 수, 초기값, 최종값

    //입력 & 연산 & 출력

    cin >> t; //테스트 케이스 수 입력받기
    while (t--) {
        cin >> a >> b; //a,b 입력받기
        vector<ci> path(SIZE, {-1, ' '}); //first: 경로, second: 명령어
        bfs(a, b, path); //bfs수행
        cout << back(b, path) << '\n'; //출력
    }

    return 0;
}