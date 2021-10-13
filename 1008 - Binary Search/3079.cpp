//
// Created by somin on 10/11/2021.
// 입국 심사
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
long long cnt, ans = 0;

long long minTime(long long left, long long max, vector<long long> arr) {
    long long right = max; //초기화 (제일 오래 걸릴때 시간)
    ans = max; //ans 초기화

    while (left <= right) {
        cnt = 0;
        long long mid = (left + right) / 2;
        if (mid == 0) break;

        for (int i = 0; i < arr.size(); i++) {
            cnt += mid / arr[i];
        }
        if (cnt >= m) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

/*
 *  long long인 mid와 int인 arr[i]를 나누면 오버플로우가 발생할 수 있음
 *   -> arr를 long long으로 수정해줘야!
 */

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin >> n >> m;
    vector<long long> arr(n, 0); //한 심사대당 걸리는 시간 배열
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    sort(arr.begin(), arr.end()); //정렬 (오름차순)

    long long left = arr.front(); //제일 최소로 걸리는 시간
    long long max = arr.back() * m; //제일 오래 걸릴 때 시간

    //출력
    cout << minTime(left ,max, arr);

    return 0;
}
