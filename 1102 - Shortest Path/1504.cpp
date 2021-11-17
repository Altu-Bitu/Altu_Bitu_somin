//
// Created by Somin on 2021/11/12.
// 1504 특정한 최단 경로 - https://www.acmicpc.net/problem/1504
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

vector<int> dijkstra(int vertex, int start, vector<vector<ci>> &graph) {
    vector<int> dist(vertex + 1, INF); //최종 거리 저장 배열
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점

    //시작 위치 초기화
    dist[start] = 0; //시작 위치 저장
    pq.push({0, start}); //큐에 입력

    while (!pq.empty()) {
        int weight = pq.top().first; //edge길이 저장
        int node = pq.top().second; //노드 저장
        pq.pop(); // 현재 맨앞 pop

        if (weight > dist[node]) //이미 확인했던 정점
            continue; //넘어감

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리

            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight; //짧은 노드로 업데이트
                pq.push({next_weight, next_node}); //큐에 push
            }
        }
    }
    return dist; //최단 거리 저장 배열 리턴
}

/**
 * 가능한 경로
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 *
 * !주의!
 * 1. 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 * 2. 출력에서 (ans == 3*INF)을 하지 않고 INF을 3*INF 값으로 초기화 하는 이유
 *    조건에 의하면 E의 값이 0일 수도 있음. 이 경우에선 1->1->N->N의 값이 INF이라 경로가 없음에도 3*INF 조건에 걸리지 않음.
 *    INF을 3*INF으로 초기화하면 해결 가능
 */

int main() {
    int n, e, a, b, c, v1, v2; //정점 개수, 간선 개수, a b c 정점 1, 2

    //입력
    cin >> n >> e;

    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //그래프 배열
    vector<vector<int>> dist(3, vector<int>(n + 1, 0)); // 거리 저장 배열

    while (e--) { //무방향 그래프
        cin >> a >> b >> c; //입력
        graph[a].emplace_back(b, c); //a노드에 노드/거리 저장
        graph[b].emplace_back(a, c); //b노드에 노드/거리 저장
    }
    cin >> v1 >> v2; //꼭 지나야 할 정점 저장

    //연산
    vector<int> start_nodes = {1, v1, v2}; //시작 노드
    for (int i = 0; i < 3; i++) //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(n, start_nodes[i], graph);

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans); //출력
}

