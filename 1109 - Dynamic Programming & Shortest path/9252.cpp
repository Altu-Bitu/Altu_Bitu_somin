//
// Created by Somin on 2021/11/15.
// 9252 LCS2 - https://www.acmicpc.net/problem/9252
//

#include <iostream>
#include <vector>
#include <string>
#define SIZE 1000

using namespace std;
vector<vector<int>> dp;

string back(string s1, string s2){
    string path;
    int n = s1.size(), m = s2.size();
    while(dp[n][m] != 0){
        if(dp[n][m] == dp[n-1][m]) n--;
        else if(dp[n][m] == dp[n][m-1]) m--;
        else{
            n--;
            m--;
            path.push_back(s1[n]);
        }
    }
    return path;
}


int LCS(string s1, string s2){
    int n = s1.size(), m = s2.size();
    dp.assign(n+1,vector<int>(m+1,0));

    for(int i = 1; i< n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    int ans = 0;
    string s1, s2;
    //입력
    cin >> s1 >> s2;
    //연산
    ans = LCS(s1,s2);
    string path = back(s1,s2);

    //출력
    cout << ans << '\n';
    for(int i = path.length()-1; i>=0; i--){
        cout << path[i];
    }
}

