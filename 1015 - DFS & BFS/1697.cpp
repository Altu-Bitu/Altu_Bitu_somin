//
// Created by Somin on 05/11/2021.
// 숨바꼭질 - https://www.acmicpc.net/problem/1697
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000

using namespace std;

int calMinTime(int n, int k){
    int front_num, res = 0;
    queue<int> q;
    vector<int> num(MAX+1, 0);
    vector<int> sub_case(3,0);

    q.push(n); //queue initialzize
    while(!q.empty()){
            front_num = q.front();
            // 탈출 조건
            if(front_num == k) {
                return num[k];
            }
            q.pop();

            // 3가지 case 연산
            sub_case = {front_num-1, front_num+1, front_num*2};
            for(int i = 0; i<3; i++){
                if((sub_case[i] >= 0 && sub_case[i] <= MAX) && num[sub_case[i]] == 0){
                    num[sub_case[i]] = num[front_num] + 1;
                    q.push(sub_case[i]);
                }
            }
    }
}

/*
 * 일직선 상의 이동 -> 가장 빠른 시간 구하기 (BFS)
 */

int main(){
    int n, k;

    //입력
    cin >> n>> k;

    //연산 && 출력
    cout << calMinTime(n,k);

    return 0;
}
