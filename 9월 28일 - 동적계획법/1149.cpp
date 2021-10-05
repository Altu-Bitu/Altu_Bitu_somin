//RGB°Å¸® 
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int result = 0;
	int dp[1001][3] = { 0, };

	for (int i = 1; i <= n; i++) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];  //r g b
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]); 
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]); 
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]); } 
	
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) <<'\n'; 

}