//
// Created by Somin on 06/11/2021.
// 루머 - https://www.acmicpc.net/problem/19538
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> ppl; //전체 관계 저장 배열
vector<int> rumor_maker; //루머 유포자 저장 배열

vector<int> calRumorBelieve(int n){
    int curr, next,  time; //현재 사람 , 다음 사람, 믿게 된 시간
    vector<int> ans(n+1,-1); //정답 저장 배열
    vector<int> num(n+1,0); // 주변인 중에 몇명이나 믿는지 저장 배열
    queue<int> q; //bfs 실행할 queue

    for(int i = 0; i<rumor_maker.size(); i++){
        ans[rumor_maker[i]] = 0; //루머 유포자 정답배열 initialize
        q.push(rumor_maker[i]); //queue에 넣기
    }

    while(!q.empty()){ //queue가 비어있지 않을 동안
        curr = q.front(); //큐 맨앞 꺼내기 (현재 사람)
        q.pop(); // pop
        time = ans[curr]; //루머 믿은 시간

        for(int i = 0; i<ppl[curr].size();i++){
            next = ppl[curr][i]; //다음 사람
            num[next] += 1; //next의 주변에서 루머를 믿는 사람 증가

            if(ans[next] != -1) continue; //이미 루머를 믿는 다면 skip
            if((ppl[next].size() + 1)/2 <= num[next]){ //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = time+1; //ans배열에 업데이트
                q.push(next); //queue에 push
            }
        }
    }
    return ans; //정답 배열 리턴
}

/**
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요 (루머를 몇 분 후에 믿는지를 저장하는 배열로 관리)
 */

int main(){
    int n, m, input; //n명 처음 유포자 수 input(temp)

    //입력
    cin >> n; //n입력
    ppl.assign(n+1,vector<int>()); //열 크기 확정 x 주변인 배열 생성

    for(int i = 1; i < n+1; i++){
        while(true){
            cin >> input; // 주변인 입력
            if(input == 0) break; //0이면 탈출
            ppl[i].push_back(input);
        }
    }

//    // debug
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j<ppl[i].size();j++){
//            cout << ppl[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    cin >> m ; //최초 유포자 수 저장
    rumor_maker.assign(m,0); // 최초 유포자 수 배열 initialize
    while(m--){
        cin >> input; //입력 받기 (최조 유포자)
        rumor_maker.push_back(input); //배열에 넣기
    }

    //연산
    vector<int> res_arr = calRumorBelieve(n); //결과 연산

    //출력
    for(int i = 1; i < n+1 ; i++){
        cout << res_arr[i] <<' ';
    }

    return 0;
}

