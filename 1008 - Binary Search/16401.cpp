//
// Created by somin on 10/11/2021.
// 과자 나눠주기
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int m, n, cnt, ans;

bool find_true(int mid) {
    //mid = 자르는 길이
    cnt = 0;
    //연산
    for (int i = 0; i < n; i++) cnt += arr[i] / mid;
    //결과 표현
    if (cnt >= m) return true;
    return false;
}

int find_mid(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid == 0) break;  // mid가 0이 될 수 있음 기억해야 함!

        if (find_true(mid)) {
            ans = mid; //answer 업데이트 해주기
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    //입력
    cin >> m >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //길이 정렬 (오름차순)
    sort(arr.begin(), arr.end());

    //출력 && 연산
    cout << find_mid(0, arr.back());

    return 0;
}
