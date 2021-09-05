#include <iostream>

using namespace std;
int main() {
	int N;
	string str;

	cin >> N;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cin >> str;
		int arr[26] = { 0, };
		int flag = 0;
		for (int j = 0; j < str.length(); j++) {
			arr[(int)str[j] - 97]++; // 'a' in ASCII code -> 97

			if (arr[(int)str[j] - 97] > 1 && str[j] != str[j - 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) cnt++;
	}
	cout << cnt;

}