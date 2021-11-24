//
// Created by Somin on 2021/11/21.
// 5639 이진검색 - https://www.acmicpc.net/problem/5639
//

#include <iostream>
#include <vector>
#define SIZE 10000

using namespace std;
vector<int> num(SIZE,0);

void preToPost(int s, int e){
    if(s == e) return; //마지막 노드
    int next = s + 1;

    //경계찾기(Left&Right)
    while(num[next] < num[s] && next < e) next++;

    //leftSubTree
    preToPost(s+1, next);
    //rightSubTree
    preToPost(next,e);
    //Root 출력
    cout << num[s] << '\n';
    return;
}

/**
 * 전위순회: V->L->R
 * 후위순회: L->R->V
 */

int main(){
    int input, n = 0;

    //입력
    while(cin >> input){
        num[n++] = input;
    }
    //연산 && 출력
    preToPost(0, n);

    return 0;
}

