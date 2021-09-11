#include <iostream>
#include <vector>

using namespace std;

// ing
int main() {
	string a, b;
	vector<int> a_arr, b_arr, result;

	// 입력
	cin >> a >> b;
	a_arr.assign(a.length(), 0);
	b_arr.assign(b.length(), 0);
	result.assign(max(a.length(), b.length()) + 1,0); // result size -> + 1

	for (int i = 0; i < a.length(); i++) 
		a_arr[i] = a[a.length()- 1- i] - '0'; 
	for (int i = 0; i < b.length(); i++) 
		b_arr[i] = b[b.length() - 1 - i] - '0';  
	
	int a_length = a.length() , b_length = b.length();
	int i = 0; // iterative purpose

	// 연산 
	while (a_length > 0 && b_length > 0) {
		result[i] += (a_arr[i] + b_arr[i]) % 10;
		if ((a_arr[i] + b_arr[i]) / 10 > 0) result[i+1]++;
		a_length--; b_length--;
		i++;
	}
	// 남은 경우
	while (a_length > 0) {
		result[i] += a_arr[i];
		if (a_arr[i] / 10 > 0) result[i+1]++;
		a_length--; i++;
	}
	while (b_length > 0) {
		result[i] += b_arr[i];
		if (b_arr[i] / 10 > 0) result[i+1]++;
		b_length--; i++;
	}

	// i 처리 해주기 
	if (result[i] == 0) i--;

	// 출력
	for (int j = i; j >=0; j--) {
		cout << result[j];
	}
}