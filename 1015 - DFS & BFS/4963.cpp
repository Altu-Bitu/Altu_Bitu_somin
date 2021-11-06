//
// Created by Somin on 06/11/2021.
// 섬의 개수 - https://www.acmicpc.net/problem/4963
//

#include <iostream>
#include <vector>

using namespace std;

// up down left right upleft대각 upright대각 downleft대각 downright대각
vector<int> row_d = {-1,1,0,0,1,1,-1,-1};
vector<int> col_d = {0,0,-1,1,-1,1,-1,1};

int w = -1, h = -1; //width, height


void dfs(int row, int col,vector<vector<int>>& map){
    int next_r, next_c;
    map[row][col] = 0;

    for(int i = 0; i<8; i++){
        next_r = row + row_d[i];
        next_c = col + col_d[i];
        if(next_r >= 0 && next_r < h && next_c >= 0 && next_c < w && map[next_r][next_c] == 1){
            dfs(next_r,next_c,map);
        }
    }
}

int calNumIslands(vector<vector<int>>& map , int w, int h){
    int res = 0;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(map[i][j]){
                res += 1;
                dfs(i,j,map);
            }
        }
    }
    return res;
}

/*
 * 가로/세로/대각선 -> 같은 섬
 * 땅: 1 바다: 0
 * dfs -> 전체탐색
 */

int main(){
    vector<vector<int>> map;

    //입력 && 연산
    while(true){
        cin >> w>> h;
        if(w == 0 && h == 0) break;
        map.assign(h,vector<int>(w,0));
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                cin>> map[i][j];
            }
        }
        //연산
        cout << calNumIslands(map,w,h) <<'\n';
    }
    return 0;
}

