//스위치 켜고 끄기 
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr; //스위치 배열

void boySwitch(int m) {
	for (int i = m; i < arr.size(); i += m) {
		if (arr[i] == 0) arr[i] = 1;
		else arr[i] = 0;
	}
}

void girlSwitch(int m) {
	int i = 0; 
	while ((arr[m - i] == arr[m + i]) && (m + i < arr.size()) && (m - i >= 1)) {
		if (arr[m - i] == 0) {
			arr[m - i] = 1;
			arr[m + i] = 1;
		}
		else {
			arr[m - i] = 0;
			arr[m + i] = 0;
		}
		i++;
	}
}

void flipSwitch(vector<pair<int,int>>& stud_arr) {
	for (int i = 0; i < stud_arr.size(); i++) {
		if (stud_arr[i].first == 1) { //남자
			boySwitch(stud_arr[i].second);
		}
		else {//여자
			girlSwitch(stud_arr[i].second);
		}
	}
}

/*
* 출력 형식 주의하기 
*/

int main() {
	int n, stud_num;
	vector<pair<int, int>> stud_arr;

	//입력
	cin >> n;
	arr.assign(n+1, 0); //1부터 시작
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	cin >> stud_num;
	stud_arr.assign(stud_num, { 0,0 });
	for (int i = 0; i < stud_num; i++) {
		cin >> stud_arr[i].first >> stud_arr[i].second;
	}

	//연산
	flipSwitch(stud_arr);

	//출력 
	for (int i = 1; i <= n; i++) {
		if (i % 20 == 0) cout << arr[i] << '\n';
		else cout << arr[i] << ' ';
	}

	return 0;
}