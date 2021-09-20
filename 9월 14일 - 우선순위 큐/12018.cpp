#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n, total_m;
	priority_queue<int, vector<int>, greater<>> pq; 
	
	cin >> n >> total_m;

	int stud_num, max, per_m;
	while (n--) {
		vector<int> arr;
		cin >> stud_num >> max;
		while (stud_num--) {
			cin >> per_m;
			arr.push_back(per_m);
		}
		sort(arr.begin(), arr.end(), greater<>());
		if (arr.size() < max) pq.push(1);
		else pq.push(arr[max - 1]);
	}

	int sum = 0, cnt = 0;
	int length = pq.size();
	for (int i = 0; i < length; i++) {
		sum += pq.top();
		if (sum <= total_m) cnt++;
		pq.pop();
		
	}

	cout << cnt;
}