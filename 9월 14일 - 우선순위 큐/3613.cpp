#include <iostream>
#include <string>
#include <queue>

using namespace std;
/* 틀림 ㅠㅠ */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, result; // input string
	cin >> s;

	bool java = false, cpp = false, flag = false;
	
	/* 예외처리 */
	/* 첫번째 문자 대문자 or 마지막 _ 일 떄 */
	if (isupper(s[0]) || s[s.length()-1] == '_') {
		cout << "Error!" << '\n'; 
		return 0;
	}
	/* __ 연속으로 나올 경우 */
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == '_') {
			cpp = true;
			if (s[i] == s[i + 1]) {
				cout << "Error!" << '\n';
				return 0;
			}
		}
		if (isupper(s[i])) java = true;
	}
	/* 다 소문자 */
	if (java == false && cpp == false) {
		cout << s << '\n';
		return 0;
	}
	/* cpp랑 java 동시에 포함되면 */
	if (cpp && java) {
		cout << "Error!" << '\n';
		return 0;
	}

	/* c++   ex) java_is_so_cool*/
	if (cpp) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '_') {
				result.push_back(toupper(s[i + 1]));
				i++;
			}
			else result.push_back(s[i]);
		}
	} /* java ex) javaIsSoCool*/
	else if (java) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] <= 'Z') {
				result.push_back('_');
				result.push_back(tolower(s[i]));
			}
			else result.push_back(s[i]);
		}
	}

	cout << result << '\n';
	
}