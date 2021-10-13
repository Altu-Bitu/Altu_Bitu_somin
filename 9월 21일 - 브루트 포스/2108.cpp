// 통계학 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int num, sum = 0;
	int arr2[8001] = { 0, };
	int temp;
	vector<int> arr;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> temp;
		sum += temp;
		arr.push_back(temp);
		arr2[temp + 4000]++;
	}

	sort(arr.begin(), arr.end());

	// 산술평균 출력 - 소수점 이하 첫째 자리에서 반올림 
	cout << round((float)sum / num) << "\n";

	// 중앙값 출력
	temp = num / 2;
	cout << arr[temp] << "\n";

	// 최빈값 출력
	int max = 0, index;
	bool flag = false;

	for (int i = 0; i < 8001; i++) {
		if (arr2[i] > max) {
			flag = false;
			max = arr2[i];
			index = i;
		}
		else if (arr2[i] == max) {
			flag = true;
		}
	}

	int idx = 0;
	if (flag == false) { cout << index - 4000 << "\n"; }
	else {
		for (int i = 0; i < 8001; i++) {
			if (arr2[i] == max) {
				idx++;
			}
			if (idx == 2) {
				index = i;
				break;
			}
		}
		cout << index - 4000 << "\n";
	}

	// 범위 출력 (max-min)
	temp = arr.back() - arr.front(); //첫번째 - 두번째
	cout << temp << "\n";


}