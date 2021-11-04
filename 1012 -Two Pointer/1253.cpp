//
// Created by Somin on 04/11/2021.
// 좋다 - https://www.acmicpc.net/problem/1253
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calcNum(vector<int>& arr){
    int s, e, res = 0;

    for(int i = 0; i < arr.size() ; i++){
        s = 0;
        e = arr.size()-1;
        while(s < e){
            if(s == i) {
                s++;
                continue;
            }
            if(e == i){
                e--;
                continue;
            }
            if(arr[s] + arr[e] == arr[i]) {
                res++;
                break;
            }
            if(arr[s] + arr[e] < arr[i]) s++;
            else e--;
        }
    }
    return res;
}

int main(){
    int n;

    //입력
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }
    //정렬
    sort(arr.begin(),arr.end());

    //연산 && 출력
    cout << calcNum(arr);

    return 0;
}