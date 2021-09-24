#include <iostream>
//#include <string>

using namespace std;

/*조건문이 복잡 -> 함수로 해결 
  isCpp, isJava, toCpp, toJava */

bool isCpp(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) return false; // 대문자 있으면 안됨
		if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_'))
			return false; // 첫문자, 맨 마지막 문자, 연속해서 _가 나올경우 
	}
	return true; 
}

bool isJava(string str) {
	return !isupper(str[0]) && str.find('_') == string::npos; // 첫문자가 대문자, _가있을경우 
}

string toCpp(string str) {
	string result; // 바뀐 결과물 저장할 string 
	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) result += '_'; //대문자라면 앞에 '_' 삽입
		result += tolower(str[i]); //소문자로 바꿔서 넣기
	}
	return result; // result 반환 
}

string toJava(string str) {
	string result; // 바뀐 결과물 저장할 string 
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '_') { 
			result += toupper(str[i + 1]); //'_' 라면 그 다음 글자를 대문자로 바꿔서 삽입
			i++; // i 증가시키기 (건너뛰기) 
			continue; 
		}
		result += str[i]; //'_' 가 아니라면 나머지 글자는 삽입 
	}
	return result; // result 반환 
}

  /**
   * 1. 입력으로 주어진 변수가 C++ 형식에도 맞고, JAVA 형식에도 맞을 수 있음 (ex. name)
   * 2. "Error!"인 경우 (C++)
   *    2-1. 언더바('_')로 시작하거나, 끝나는 변수
   *    2-2. 언더바('_')가 연속해서 등장하는 변수
   *    2-3. 대문자가 등장하는 변수
   * 3. "Error!"인 경우 (Java)
   *    3-1. 대문자로 시작하는 변수
   *    3-2. 언더바('_')가 등장하는 변수
   */

int main() {
	string str; // 문자열 담을 str 

	cin >> str; // 입력받기
	bool is_cpp = isCpp(str); // cpp 체크할 bool 자료형 선언
	bool is_java = isJava(str); // java 체크할 bool 자료형 선언

	if (is_cpp && is_java) cout << str;  // 두 형식에 부합하면 그냥 출력
	else if (is_cpp) cout << toJava(str); // cpp 형식이라면 java로 바꿔서 출력
	else if (is_java) cout << toCpp(str); // java형식이라면 cpp로 바꿔서 출력
	else cout << "Error!"; // 둘다 아니라면 에러 
}