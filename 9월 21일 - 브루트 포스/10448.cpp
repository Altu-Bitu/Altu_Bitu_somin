// 유레카 이론 
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(1002, 0);

bool is_it_three(int num) {
	for (int i = 1; i <= 51; i++) {
		for (int j = i; j <= 51; j++) {
			for (int k = j; k <= 51; k++) {
				if (arr[i] + arr[j] + arr[k] == num) return true;

			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num; 
	cin >> n;

	for (int i = 1; i <= 1000; i++) arr[i] = (i * (i + 1)) / 2;

	while (n--) {
		cin >> num;
		cout << is_it_three(num) << '\n';
	}	
}