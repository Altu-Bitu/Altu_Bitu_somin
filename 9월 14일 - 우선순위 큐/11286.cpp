#include <iostream>
#include <queue>

using namespace std;

/* 내림차순 cmp */
struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) != abs(n2)) return abs(n1) > abs(n2);
		return n1 > n2;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num, min;
	priority_queue<int, vector<int>,cmp> q;
	cin >> n;

	while (n--) {
		cin >> num;
		if (num == 0) {
			if (q.empty()) min = 0;
			else {
				min = q.top();
				q.pop();
			}
			cout << min << '\n';
		}
		else q.push(num);
	}
}