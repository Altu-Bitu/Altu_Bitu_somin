//
// Created by Somin on 04/11/2021.
// 겹치는 건 싫어 - https://www.acmicpc.net/problem/20922
//

#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

int calcMax(vector<int> & arr, int k){
    int s = 0, e = 0, cnt = 0, res = 0; //시작, 끝, cnt(최대길이 update), res (제일 큰 범위 저장 변수)
    vector<int> total_arr(MAX + 1, 0); //각 원소 등장 횟수

    //start는 항상 end의 왼쪽 또는 같은 위치에 있어야 함
    while(s <= e && e < arr.size()){
        if(total_arr[arr[e]] + 1 <= k){
            //현재 끝점이 가르키는 원소를 포함해도 전체 제한 이하이면
            total_arr[arr[e]]++; //원소 포함 증가 시키기
            res = max(res,e-s+1); // 최대 길이 저장
            e++; // 끝 범위 1 증가
        }
        else{ //현재 start가 가리키는 원소를 포함하면 등장 횟수가 k번을 초과
            total_arr[arr[s]]--; //start가 가르키던 값 감소
            s++; //start값 증가 (1씩 전진)
        }
    }
    return res; //최댓값 return
}

/**
 * 1. 최장 연속 부분 수열의 '길이'를 구해야 함 -> 구간 내의 모든 원소를 고려하기 때문에 한쪽에서 시작하는 투 포인터
 * 2. 각 원소의 최댓값이 100,000이기 때문에 배열로 등장 횟수 체크하기
 * 3. right를 옮기고 바로 원소를 추가했던 기존 방법과 달리, 일단 포인터만 옮겨놓고 원소를 추가해도 되는지 확인
 */

int main(){
    int n, k; //수열의 수

    //입력
    cin >> n >> k; //입력 받기
    vector<int> arr (n,0); //arr에 입력받기
    for(int i = 0; i<n; i++){
        cin >> arr[i]; //arr에 값 insert
    }

    //연산 && 출력
    cout << calcMax(arr, k);

    return 0;
}

