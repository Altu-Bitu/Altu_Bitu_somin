//
// Created by Somin on 04/11/2021.
// 두 배열의 합 - https://www.acmicpc.net/problem/2143
//

#include <iostream>
#include <vector>

using namespace std;

//어떤 배열의 가능한 부 배열의 합 모두 구하기
vector<int> partSum(int n, vector<int> num){
    vector<int> part_sum; //부분합 모두 저장할 배열 선언
    for(int i = 0; i<n; i++){
        int sum = 0; //sum 0으로 초기화
        for(int j = i; j<n;j++){
            sum += num[j]; //모든 부분 합 계산
            part_sum.push_back(sum); //part_sum배열에 넣어주기
        }
    }
    return part_sum; //부분합 전체 배열 리턴
}

long long calculateTarget(vector<int>& sum_a, vector<int>& sum_b, int left, int right, int target){
    long long ans = 0; //정답 저장 변수 ans

    //A 배열의 부분 배열 합 중 가장 작은 값과 B배열의 부분 배열 합 중 가장 큰 값에서 시작하여 T를 만들 수 있는지 검사
    while (left < sum_a.size() && right >= 0) {
        int sum = sum_a[left] + sum_b[right]; //A 배열의 부분 배열 합 중 가장 작은 값과 B배열의 부분 배열 합 중 가장 큰 값부터 시작
        if (sum == target) { //두 부 배열 합이 T와 같은 경우
            long long cnt_a = 1, cnt_b = 1; //각 각 cnt 시작 (중복되는 값의 존재 가능성 때문에)
            while (left + 1 < sum_a.size() && sum_a[left] == sum_a[left + 1]) { //left가 sum_a size 벗어나지 않고, 값이 같을 경우
                cnt_a++; //a 카운트 증가
                left++; //left 포인터 이동
            }
            while (right - 1 >= 0 && sum_b[right] == sum_b[right - 1]) { //right가 0보다 작아지지 않고, 값이 같을 경우
                cnt_b++; //b 카운트 증가
                right--; //right 포인터 이동
            }
            //이제 값이 다른 첫 left와 right로 한칸 이동
            left++; //left증가
            right--;//right증가
            ans += cnt_a * cnt_b; //정답 업데이트
        } else if (sum < target) //T보다 작은 경우
            left++;
        else if (sum > target) //T보다 큰 경우
            right--;
    }

    return ans; //정답 리턴 
}

/**
 * 1. 부 배열은 i-j까지의 연속된 부분 배열을 의미함
 * 2. 각 A, B배열에 대한 가능한 부 배열의 합을 모두 구함
 * 3. A배열의 부 배열 합 중 가장 작은 값과 B배열의 부 배열 합 중 가장 큰 값에서 포인터를 시작하여 T를 만들 수 있는지 검사
 * 4. 이때, 포인터를 차례로 움직이는 검사를 가능하게 하기 위해선, 부 배열 합들을 미리 오름차순 정렬해 놓아야 함
 * 5. A, B의 부 배열 합이 T를 만들 수 있다면, 현재 부 배열 합과 같은 값들을 한 번에 구한 후 곱해서 더해줌 (이렇게 해야 모든 경우 탐색 가능)
 * ex. A의 부 배열 합 리스트: 1 2 2 2 4 6
 *     B의 부 배열 합 리스트: 4 6 6
 *     만약 T = 8이라면 처음 2와 6에 걸렸을 때, 2의 개수(3개)를 한 번에 구하고 6의 개수(2개)를 한 번에 구한 후 곱해야 2와 6에 대한 모든 경우의 수(6) 구할 수 있음
 *     한 번에 구하지 않고, left + 1 을 하거나, right - 1을 할 경우 그 다음 6에 대한 경우를 고려하지 못함
 *
 * !주의! 각 부 배열 합이 최대 500,500개 있으므로 모든 쌍이 T를 만든다면 500,500 * 500,500이 되어서 정답은 long long 범위여야 함
 */

int main(){
    int t, n, m; //t(최종 값) n(a배열) m(b배열)

    //입력 + 각 A, B 배열의 부 배열 합 모두 구하기
    cin >> t; //입력
    cin >> n; //입력
    vector<int> a(n,0); //a배열 생성
    for(int i = 0; i<n; i++){
        cin >> a[i]; //a배열 입력
    }
    vector<int> sum_a = partSum(n,a); //부분 a 배열의 합 전체 구하기

    cin >> m; //m 입력
    vector<int> b(m,0); //b배열 생성
    for(int i = 0; i<m; i++){
        cin >> b[i]; //b배열 입력
    }
    vector<int> sum_b = partSum(m,b); //부분 b 배열의 합 전체 구하기

    // 연산 & 출력
    sort(sum_a.begin(), sum_a.end()); //부분합  a배열 정렬
    sort(sum_b.begin(), sum_b.end()); //부분합 b배열 정렬

    cout << calculateTarget(sum_a, sum_b, 0, sum_b.size() - 1, t);

}

