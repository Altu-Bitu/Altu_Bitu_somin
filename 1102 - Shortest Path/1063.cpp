//
// Created by Somin on 2021/11/10.
// 1063 킹 - https://www.acmicpc.net/problem/1063
//

#include <iostream>
#include <map>

using namespace std;
typedef pair<int,int> ci;// pair<int,int> 묶기
const int SIZE = 8; //체스판 크기


map<string, int> direction = {{"L",  0},  //상
                              {"R",  1},  //하
                              {"B",  2},  //좌
                              {"T",  3},  //우
                              {"LT", 4},  //우상향
                              {"LB", 5},  //좌상향
                              {"RT", 6},  //우하향
                              {"RB", 7}}; //좌하향

string pointToString(ci point) {
    string ans;
    ans = (point.first + 'A');
    ans += (point.second + '1');
    return ans;
}

pair<ci, ci> moveKing(string move, ci point_k, ci point_r) {
    //상, 하, 좌, 우, 우상향, 좌상향, 우하향, 좌하향
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, 1, -1, 1, -1};
    int d = direction[move]; //방향 인덱스 저장

    int king_nr = point_k.first + dr[d]; //row방향으로 이동
    int king_nc = point_k.second + dc[d]; //col방향으로 이동
    if (king_nr < 0 || king_nr >= SIZE || king_nc < 0 || king_nc >= SIZE) //킹이 범위를 벗어나는 경우
        return {point_k, point_r}; //그대로 리턴

    if (king_nr != point_r.first || king_nc != point_r.second) //킹이 움직이는 방향에 돌이 없는 경우
        return {{king_nr, king_nc}, point_r}; //돌은 원래 위치 그대로 리턴

    //돌이 있다면
    int rock_nr = point_r.first + dr[d]; //row방향으로 이동
    int rock_nc = point_r.second + dc[d]; //col방향으로 이동
    if (rock_nr < 0 || rock_nr >= SIZE || rock_nc < 0 || rock_nc >= SIZE) //범위를 벗어나면
        return {point_k, point_r}; //킹과 돌 원래 위치 그대로 리턴 (건너뛰기)

    return {{king_nr, king_nc}, {rock_nr, rock_nc}}; //둘 다 범위 안에 있는 경우
}

/**
 * 체스판을 편하게 구현하기 위해 왼쪽 아래를 시계방향으로 90도 회전한 체스판으로 구현
 * [방향 바꿔서 생각]
 *  T:상 -> 우       B:하 -> 좌       L:좌->상         R:우->하
 * RT:오위 -> 오아   LT:왼위 -> 오위   RB:오아 -> 왼아   LB:왼아 -> 왼위
 *
 * => 바뀐 방향대로 입력에 따라 킹과 돌을 움직임
 * 방향 구현을 효율적으로 하기 위해 탐색 시간복잡도가 logN인 map 사용
 *
 * [경우의 수]
 * 1. 킹이 범위를 벗어나는 경우
 * 2. 킹이 움직이는 방향에 돌이 없는 경우
 * 3. 킹이 움직이는 방향에 돌이 있고, 돌이 범위를 벗어나는 경우
 * 4. 킹이 움직이는 방향에 돌이 있고, 둘 다 범위를 벗어나지 않는 경우
 *
 */

int main(){
    string king, rock, move; //king, rock 의 위치, 움직이는 방향
    int n; // 횟수

    //입력 & 연산
    cin >> king >> rock >> n;
    ci point_k = {king[0] - 'A', king[1] - '1'}; //초기 킹 위치
    ci point_r = {rock[0] - 'A', rock[1] - '1'}; //초기 돌 위치
    pair<ci, ci> point = {point_k, point_r}; //킹과 돌의 위치 묶어서 저장
    while(n--){
        cin>> move; //방향 입력 받기
        point = moveKing(move,point.first, point.second); //이동 위치 저장
    }
    //출력
    cout << pointToString(point.first) << '\n' << pointToString(point.second);

    return 0;
}

