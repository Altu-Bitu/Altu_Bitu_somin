//
// Created by Somin on 2021/11/23.
// 1967 트리의 지름 - https://www.acmicpc.net/problem/1967
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>> &graph) {
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i].first; //다음 노드
        if (next_node == parent) continue; //리프 노드가 아니라면 넘어감

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.first > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.first; //길이 업데이트
            pos = dfs_search.second; //위치 업데이트
        }
    }
    return {len, pos}; //지름과 다른 하나의 노드(지름 이루는) 리턴
}

/**
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */

int main() {
    int n, p, c, w; //노드의 개수, 노드1, 노드2, Weight

    //입력
    cin >> n; //노드의 개수 입력
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //그래프 할당
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w; //노드1 노드2 weight
        graph[p].emplace_back(c, w); //무방향 -> 노드1 기준 그래프 저장
        graph[c].emplace_back(p, w); //무방향 -> 노드2 기준 그래프 저장
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.second, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력
    cout << second_node.first; //지름의 길이 출력
}