#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;	
	return a.second < b.second;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> arr;
	arr.assign(N, {}); // initialize

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(),cmp);
	
	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << '\n';
	}
}