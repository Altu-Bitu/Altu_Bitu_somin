//
// Created by Somin on 2021/11/20.
// 2011 암호코드 - https://www.acmicpc.net/problem/2011
//

#include <iostream>
#include <vector>

using namespace std;

int calNum(vector<int> num_arr){
    vector<int> ans(num_arr.size(),0);
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i<num_arr.size();i++){
        if(num_arr[i] >= 1 && num_arr[i] < 10){
            ans[i] += ans[i-1];
        }
        if(num_arr[i-1]* 10 + num_arr[i] <= 26 && num_arr[i-1]* 10 + num_arr[i] >= 10) {
            ans[i] += ans[i-2];
        }
        ans[i] %= 1000000;
    }
    return ans[num_arr.size()-1];
}

/**
 * HINT) 우선 경우의 수를 하나씩 찾는 풀이를 생각하셨다면 입력 범위를 다시 보기
 * 이전에 구한 경우의 수의 해답을 활용해야 함.
 * 또한 숫자를 검사할 때 항상 1 ~ 26사이인지와 알파벳으로 만들 수 있는 수인지 확인하는 것이 중요함
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    vector<int> num_arr;

    //입력
    cin >> n;
    num_arr.assign(n.size()+1,0);

    for(int i = 1; i <= n.size() ;i++){
        num_arr[i] = n[i-1] -'0';
        if(num_arr[i] == 0){
            if(num_arr[i-1] == 1) continue;
            else{
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    //연산 && 출력
    cout << calNum(num_arr) << '\n';
    return 0;
}

