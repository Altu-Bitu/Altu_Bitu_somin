//삼각형 만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int make_triangle(vector<int>& straws) {
	int ans = 0;
	for (int i = straws.size() - 1; i >= 2; i--) {
		if (straws[i] < (straws[i - 1] + straws[i - 2])) return straws[i] + straws[i - 1] + straws[i - 2];
	}
	return -1;
}
int main() {
	int n;
	vector<int> straws;

	//입력
	cin >> n;
	straws.assign(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> straws[i];
	
	//연산
	sort(straws.begin(), straws.end());
	cout << make_triangle(straws);
}