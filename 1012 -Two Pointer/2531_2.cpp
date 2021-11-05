//
// Created by Somin on 04/11/2021.
// 회전 초밥 - https://www.acmicpc.net/problem/2531
//

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0); //전체 스시 배열

    //쿠폰으로 먹은 초밥
    int section_sushi = 1; //한 섹션에 스시의 수 증가 (쿠폰 스시)
    sushi[c]++; //스시 배열 증가 (쿠폰)

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        sushi[belt[i]]++; //belt에서 입력된 스시 정보 업데이트
        if (sushi[belt[i]] == 1)
            section_sushi++; //섹션의 값 ++
    }

    int ans = section_sushi; //처음 섹션의 스시의 최대의 수 저장
    int left = 0, right = k - 1; //포인터 지정
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--;// 한칸 옮기기 때문에 이전의 left값 다시 바꿈
        if (!sushi[belt[left]]) // 스시의 section 값 업데이트 (윈도우 한칸 옮김)
            section_sushi--;

        //윈도우의 양 끝 이동
        left = (left + 1) % n; //맨 앞 이동
        right = (right + 1) % n; //맨 뒤 이동

        sushi[belt[right]]++; //맨 뒤의 값 업데이트
        if (sushi[belt[right]] == 1) //스시가 존재한다면 업데이트
            section_sushi++;

        ans = max(ans, section_sushi); //최대 값 업데이트
    } while (left); //left가 0 이되면 종료

    return ans; //max값 리턴
}

/**
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 보석 쇼핑 문제처럼 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    int n, d, k, c; //접시의 수, 초밥의 가지수, 연속 횟수, 쿠폰번호

    //입력
    cin >> n >> d >> k >> c; //입력
    vector<int> belt(n, 0); // belt arr 생성 (
    for (int i = 0; i < n; i++)
        cin >> belt[i]; //belt arr 입력

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c); //연산 && 출력
}

