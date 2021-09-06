/*그룹 단어 체커 */

#include <iostream>
using namespace std;

bool arr[26] = { 0, }; // alphabet array
int cnt = 0;

void wordChecker(string str) {
	fill_n(arr, 26, 0); // arr initialize 

	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			arr[(int)str[i] - 'a'] = true; // arr의 index에 반영
			continue;
		} 
		if (arr[(int)str[i] - 'a'] == true && str[i] != str[i - 1]) return;

		arr[(int)str[i] - 'a'] = true;  
	}
	cnt++;
}

int main() {
	int N; // 총 단어의 수 
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		wordChecker(str);
	}

	cout << cnt << "\n";
}