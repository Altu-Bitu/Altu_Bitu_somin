//
// Created by somin on 10/31/2021.
// 회전 초밥 - https://www.acmicpc.net/problem/2531
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

 int calcMax(vector<int> arr, int d, int k, int c){
     int cnt, s = 0, e = k - 1, max = 0; //s-> start, e -> end
     vector<int> sushi_arr;
     sushi_arr.assign(d,0);

     while(true){
         cnt = 0; //cnt 초기화

         //sushi arr 초기화
         for(int i = 0; i<arr.size();i++){
             sushi_arr[arr[i]]++;
             if(sushi_arr[arr[i]] > 1) sushi_arr[arr[i]] = 1;
         }

         for(int i = 0; i<k; i++){
             if(arr[s+i] != c && sushi_arr[arr[s+i]] == 1) {
                 cnt++;
                 sushi_arr[arr[s + i]]--;
             }
         }

         cnt++;
         if (cnt > max) max = cnt; //max update

         s = (s + 1) % arr.size();
         e = (e + 1) % arr.size();

         if (s == 0 && e == k-1) break; //탈출조건
     }
     return max;
 }

/*
 *  시간초과
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
    cout << calcMax(arr, d, k, c) << '\n';

    return 0;
}



