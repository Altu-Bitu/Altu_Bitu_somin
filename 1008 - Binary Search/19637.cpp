//
// Created by somin on 10/11/2021.
// IF문 좀 대신 써줘
//
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    map<int,string> rank_arr; //key: int val: string

    //입력
    cin >> n >> m;
    while(n--){
        int key;
        string val;
        cin >> val >> key;
        if(rank_arr.find(key) != rank_arr.end()) continue; //겹치는 원소가 있으면 continue
        rank_arr[key] = val;
    }

    //연산 && 출력
    while(m--){
        int num;
        cin >> num;
        auto iter = rank_arr.lower_bound(num); //lower_bound 내장함수 사용
        cout << iter->second << '\n';
    }
    return 0;
}

