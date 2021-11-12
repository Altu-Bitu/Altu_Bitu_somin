//
// Created by Somin on 2021/11/11.
// 13549 숨박꼭질 3 - https://www.acmicpc.net/problem/13549
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 100001;

int calMin(int n, int k){
    int ans = 0;

    vector<int> arr(SIZE,0);
    vector<int> sub_case(2,0);
    deque<int> dq;

    arr[n] = 1;
    dq.push_back(n);

    while(!dq.empty()) {
        int x = dq.front();
        dq.pop_front();

        if (x == k) {
            ans = arr[x] - 1;
            return ans;
        }

        int y = x * 2;
        if (y < SIZE && arr[y] == 0) {
            arr[y] = arr[x];
            dq.push_front(y);
        }

        sub_case = {x - 1, x + 1};
        for (int i = 0; i < 2; i++) {
            if ((sub_case[i] >= 0 && sub_case[i] < SIZE) && arr[sub_case[i]] == 0) {
                arr[sub_case[i]] = arr[x] + 1;
                dq.push_back(sub_case[i]);
            }
        }
    }
}

/*
 * 순간이동 먼저 고려하기!! -> queue 대신 deque 활용
 */

int main(){
    int n, k;

    //입력
    cin>> n >> k;

    //연산 & 출력
    cout << calMin(n,k) << '\n';

}

