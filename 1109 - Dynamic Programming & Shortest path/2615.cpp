//
// Created by Somin on 2021/11/12.
// 2615 오목 - https://www.acmicpc.net/problem/2615
//

#include <iostream>
#include <vector>
#define SIZE 19

using namespace std;

// R D 왼쪽대각선 오른쪽대각선
int arr_r[4] = {1,0,-1,1};
int arr_c[4] = {0,1,1,1};

int checkWinner(vector<vector<int>>& board, int i, int j, int k){
    int curr_val = board[i][j];
    int row = i, col = j;

    //6개 연속인지 체크 (앞에서)
    if(row-arr_r[k]>= 0 && row-arr_r[k] <SIZE && row-arr_c[k]>= 0 && row-arr_c[k] <SIZE ){
        if(board[row-arr_r[k]][col-arr_c[k]] == curr_val) return 0;
    }
    //5개 연속인지 체크
    for(int m = 1; m<5 ;m++) {
        row = i + arr_r[k]*m;
        col = j + arr_c[k]*m;
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) return 0;
        if (board[row][col] != curr_val) return 0; //다른 바둑알이면 리턴
        //6개 연속인지 체크 (뒤에서)
        if(m == 4){
            row += arr_r[k];
            col += arr_c[k];
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) return 0;
            if (board[row][col] == curr_val) return 0; //같으면 0 리턴
        }
    }
    return curr_val;
}
int calWinner(vector<vector<int>>& board){
    int flag = 0;
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if(board[i][j]){
                for(int k = 0; k<4; k++){
                    flag = checkWinner(board,i,j,k);
                    if(flag){
                        cout << flag << '\n';
                        cout << i+1 << ' ' << j+1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0<<'\n';
}

/**
 *검정색이 이겼을 때 -> 1 흰색 ->2 무승부 ->0
 */

int main(){
    int ans = 0;
    //board
    vector<vector<int>> board(SIZE,vector<int>(SIZE,0));

    //입력
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            cin>>board[i][j];
        }
    }

    //연산 && 출력
    calWinner(board);

    return 0;
}

