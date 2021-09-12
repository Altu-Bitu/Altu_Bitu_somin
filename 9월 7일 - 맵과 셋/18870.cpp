#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, num;
	cin >> N;
	vector<pair<int,int>> arr;
	arr.assign(N, {});

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[i].first = num;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end());
	vector<int> result;
	result.assign(N, 0);

	result[arr[0].second] = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i - 1].first == arr[i].first)
			result[arr[i].second] = result[arr[i - 1].second];
		else
			result[arr[i].second] = result[arr[i - 1].second] + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}
	

}