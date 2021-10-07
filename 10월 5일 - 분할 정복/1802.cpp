//종이접기
#include <iostream>

using namespace std;
string s;

string orgami(int size) {
	if(size == 1) return "YES"; //기저 조건

	int mid = size / 2;
	for (int i = 1; i <= mid; i++) {
		if (s[mid - i] == s[mid + i]) return "NO";
	}
	return orgami(mid);
}

int main() {
	int t;

	//입력 
	cin >> t;

	//연산 & 출력
	while (t--) {
		cin >> s;
		int size = s.size();
		cout << orgami(size)<<'\n';
	}

	return 0;
}