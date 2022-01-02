//
// Created by Somin on 2021/11/31.
// 1713 후보 추천하기 - https://www.acmicpc.net/problem/1713
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calStud(int n, vector<int>& arr){
    int m = arr.size()
    vector<pair<bool,int>> check(m); //체크 배열
    vector<int> photo(n,0); //사진 배열

    //처음 n개 배치
    for(int i = 0; i<n ; i++){
        photo[i] = arr[i];
        check[arr[i]].first = true;
        check[arr[i]].second++;
    }
    //그다음 순서 부터
    for(int i = n; i<m; i++){
        int curr = arr[i];
        idx %= m; //idx = idx % m
        //이미 배열에 존재하는 경우
        if(check[curr].first){
            check[curr].second++;
        }
        else{ //배열에 존재하지 않음
            int cnt = 0;
            for(int i = 1; i<n; i++){
                if(photo[i] == photo[i-1]) cnt++;
            }
            if(cnt == n-1){ //다 같은 값 가진 경우
                check[photo[idx]].first = false;
                check[photo[idx]].second = 0;
                photo[idx] = curr;
                idx++;
            }
        }
    }

}
/**
 * 후보를 저장하는 컨테이너로 무엇을 사용하면 좋을까요?
 * 후보를 바로 찾아서 연산할 수 있는 컨테이너면 좋겠네요.
 * 후보가 모두 꽉 찼을 경우와 게시 시간을 다루는 부분을 잘 고려해야 해요. 그리고 비어있는 사진틀이 있을 수도 있어요.
 */

int main(){
    int n, m;
    vector<int> arr; //학생 배열
    //입력
    cin >> n;
    cin >> m;

    arr.assign(m,0);
    for(int i = 0; i<m; i++)
        cin >> arr[i];

    //연산
    calStud(n,arr);

    //출력
    return 0;
}

