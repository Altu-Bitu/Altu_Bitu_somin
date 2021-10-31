//
// Created by somin on 10/27/2021.
// 비슷한 단어 - https://www.acmicpc.net/problem/2607
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int total = 0; //전체 개수 저장 변수

void calcSimilarity(vector<int>& arr1, vector<int>& arr2) {
    int flag = 0;
    for (int i = 0; i < 26; i++) {
        if (arr1[i] != arr2[i]) { //다른 구성
            if (abs(arr1[i] - arr2[i]) == 1) flag++;
            else return; //차이가 2이상 나는 경우
        }
    }
    if (flag <= 2) total++;
}

/*
 * 1. 총 문자 길이가 1이하로 차이나야 함
 * 2. 서로다른 문자가 2개 이하여야함
 */

int main() {
    int n, length = 0;

    string s1, s2;
    vector<int> arr1, arr2;
    arr1.assign(26, 0); //alphabet arr for 기준 단어


    //입력 && 연산
    cin >> n;
    cin >> s1; //기준이 되는 단어 입력
    for (int i = 0; i < s1.length(); i++) { //기준 단어 ALPHABET ARR initialize
        arr1[s1[i] - 'A']++;
    }

    for (int i = 1; i < n; i++) {
        cin >> s2;
        arr2.assign(26, 0);
        for (int i = 0; i < s2.length(); i++) arr2[s2[i] - 'A']++; //입력 단어 ALPHABET ARR

        //SIMILARITY 계산
        int length = s1.size() - s2.size(); //문자 총 길이 비교
        length = abs(length);
        if(length >= 2) continue; //문자열의 길이가 2 이상 차이날 경우 -> continue
        calcSimilarity(arr1, arr2);
    }

    //출력
    cout << total << '\n';
}
