//
// Created by somin on 10/31/2021.
// 회전 초밥 - https://www.acmicpc.net/problem/2531
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int calcMax(vector<int>& arr, int k, int c) {
    int cnt, s = 0, e = k - 1, max = 0; //s-> start, e -> end
    bool flag;
    set<int> set1;
    while (true) {
        cnt = 0; // cnt 초기화
        flag = false; //flag 초기화

        //한 구간 안 연산
        for (int i = 0; i < k; i++) {
            if (arr[(s + i) % arr.size()] != c) set1.insert(arr[(s + i) % arr.size()]);
        }
        cnt = set1.size() + 1;
        if (cnt > max) max = cnt; //max update

        //다음으로 넘어가기
        s = (s + 1) % arr.size();
        e = (e + 1) % arr.size();
        set1.clear(); //set 비우기

        if (s == 0 && e == k-1) break; //탈출조건
    }
    return max;
}
/*
 * set 쓰면) 시간 초과
 */

int main() {
    //입출력 속도
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c;
    vector<int> arr;

    //입력
    cin >> n >> d >> k >> c;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산 && 출력
    cout << calcMax(arr, k, c) << '\n';

    return 0;
}



