#include <iostream>
#include <vector>

using namespace std;

/* 어디가 틀린지 모르겠어요 ㅠㅠ */

int main() {
	string A, B;
	cin >> A >> B;

	vector<int> a_arr, b_arr, result;
	int max_size = max(A.size(), B.size());

	/*input -> 1의자리부터 */
	for (int i = 0; i < max_size; i++) {
		if (i < A.size()) a_arr.push_back(A[A.size() - 1 - i] - '0');
		else a_arr.push_back(0);
		
	}
	for (int i = 0; i < max_size; i++) {
		if (i < B.size()) b_arr.push_back(B[B.size() - 1 - i] - '0');
		else b_arr.push_back(0);
	}

	/*calculate*/
	int size = 0;
	result.assign(max(a_arr.size(), b_arr.size()) + 1, 0);

	while (size < max(a_arr.size(),b_arr.size())){
		result[size] += (a_arr[size] + b_arr[size]) % 10;
		if ((a_arr[size] + b_arr[size]) / 10 > 0)
			result[size+1]++;
		size++;
	}
	if (result[size] == 0) size--; 

	/* 거꾸로 출력 */
	for (int i = size; i >= 0; i--)
		cout << result[i];

}