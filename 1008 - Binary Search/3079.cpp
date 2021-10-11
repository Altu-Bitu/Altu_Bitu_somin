//
// Created by somin on 10/11/2021.
// 입국 심사
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long n, m, cnt, ans = 0; //n과 m도 longlong 이여야함!

long long minTime(long long max, vector<int> arr){
    long long left = 0, right = max; //초기화 (0, 제일 오래 걸릴때 시간)
    ans = max; //ans 초기화

    while(left <= right){
        cnt = 0;
        long long mid = (left + right)/2;
        if(mid == 0) break;

        for(long long i = 0; i<arr.size(); i++){
            cnt += mid / arr[i];
        }
        if(cnt >= m){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}

int main(){
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin >> n>> m;
    vector<int> arr(n,0); //한 심사대당 걸리는 시간 배열
    for(long long i = 0; i<n ; i++)
        cin >> arr[i];

    //연산
    sort(arr.begin(),arr.end()); //정렬 (오름차순)
    long long max = arr.back() * m; //제일 오래 걸릴 때 시간

    //출력
    cout << minTime(max, arr);

    return 0;
}
