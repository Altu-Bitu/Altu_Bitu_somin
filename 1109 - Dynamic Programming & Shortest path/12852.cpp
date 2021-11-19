//
// Created by Somin on 2021/11/12.
// 12582 1로 만들기 2 - https://www.acmicpc.net/problem/12852
//

#include <iostream>
#include <vector>
#include <queue>

#define SIZE 1e6

using namespace std;

vector<int> back(int n, vector<int>& path){
    vector<int> result;
    int x = 1;
    while(x != -1){
        result.push_back(x);
        x = path[x];
    }
    return result;
}

int bfs(int n, vector<int>& path){
    vector<int> arr(SIZE,-1);
    queue<int> q;
    int ans = 0; //최단 시간

    arr[n] = 1; //arr에 반영
    q.push(n);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == 1){
            ans = arr[x] -1;
            break;
        }
        // 1)x/3
        if(x%3 == 0 && x/3 >= 0 && arr[x/3] == -1){ //범위 내에 있고 첫 방문이라면
            arr[x/3] = arr[x] + 1;
            path[x/3] = x;
            q.push(x/3);
        }
        // 2)x/2
        if(x%2 == 0 && x/2 >= 0 && arr[x/2] == -1){ //범위 내에 있고 첫 방문이라면
            arr[x/2] = arr[x] + 1;
            path[x/2] = x;
            q.push(x/2);
        }
        // 3)x-1
        if(x-1 >= 0 && arr[x-1] == -1){ //범위 내에 있고 첫 방문이라면
            arr[x-1] = arr[x] + 1;
            path[x-1] = x;
            q.push(x-1);
        }
    }

    return ans;
}

int main(){
    int n, ans;
    vector<int> path(SIZE+1,-1);

    //입력
    cin >> n;

    //연산
    ans = bfs(n,path);
    vector<int> result = back(n,path);

    //출력
    cout << ans << '\n';
    for(int i = result.size()-1; i>=0; i--){
        cout << result[i] <<' ';
    }
    return 0;
}

