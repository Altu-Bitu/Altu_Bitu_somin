/*�׷� �ܾ� üĿ */

#include <iostream>
using namespace std;

bool arr[26] = { 0, }; // alphabet array
int cnt = 0;

void wordChecker(string str) {
	fill_n(arr, 26, 0); // arr initialize 

	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			arr[(int)str[i] - 'a'] = true; // arr�� index�� �ݿ�
			continue;
		} 
		if (arr[(int)str[i] - 'a'] == true && str[i] != str[i - 1]) return;

		arr[(int)str[i] - 'a'] = true;  
	}
	cnt++;
}

int main() {
	int N; // �� �ܾ��� �� 
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		wordChecker(str);
	}

	cout << cnt << "\n";
}