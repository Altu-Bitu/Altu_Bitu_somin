#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, M, cnt = 0; 
	string input;
	set<string> arr, result;

	// input && calculate
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.insert(input);
	}

	for (int i = 0; i < M; i++) {
		cin >> input;
		if (arr.count(input)) {
			result.insert(input);
			cnt++;
		}
	}
	
	cout << cnt << '\n';

	// traverse
	for (auto iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << '\n';
	}
	
}