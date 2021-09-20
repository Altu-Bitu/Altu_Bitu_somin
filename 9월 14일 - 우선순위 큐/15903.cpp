#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	long long num, sum = 0; /* int: no! 문제 조건 잘보기 */
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<>> pq;

	for(int i = 0; i<n; i++) {
		cin >> num;
		pq.push(num);
	}
	while (m--) {
		long long num1 = pq.top();
		pq.pop();
		long long num2 = pq.top();
		pq.pop();
		num1 += num2;
		pq.push(num1);
		pq.push(num1);
	}
	while(n--) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << '\n';
}

