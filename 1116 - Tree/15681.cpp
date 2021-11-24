//
// Created by Somin on 2021/11/23.
// 15681 트리와 쿼리 -  https://www.acmicpc.net/problem/15681
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt; //서브 트리 수 계산 배열

int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) //이미 탐색했던 상태
        return subtree_cnt[cur]; //리턴하기

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0; //0으로 초기화
    int node = 1; //현재 자신 포함
    for (int i = 0; i < graph[cur].size(); i++)
        node += treeDp(graph[cur][i], graph); //각 노드 루트로 하는 서브트리 정점 수 계산
    return subtree_cnt[cur] = node; //서브 트리 배열에 업데이트
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 계산
 */

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input; //정점수, 루트 번호, 쿼리 수, 노드1, 노드2, 입력

    //입력
    cin >> n >> r >> q; //정점수, 루트 번호, 쿼리 수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프 할당
    subtree_cnt.assign(n + 1, -1);  //정점 수, -1로 서브 트리 초기화

    while (--n) { //무방향 그래프
        cin >> u >> v; //노드1 노드2 입력
        graph[u].push_back(v); //무방향 그래프 입력 받기 (노드1 기준)
        graph[v].push_back(u); //무방향 그래프 입력 받기 (노드2 기준)
    }

    //연산
    treeDp(r, graph);

    //출력
    while (q--) {
        cin >> input; //노드 입력
        cout << subtree_cnt[input] << '\n'; //서브 트리 카운트 리턴
    }
}