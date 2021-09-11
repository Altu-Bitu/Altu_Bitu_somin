#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
int main() {
	int N, n;
	string name, type; 
	cin >> N;

	while (N--) {
		cin >> n;
		map<string, int> arr; // key: string value: int  
		for (int i = 0; i < n; i++) {
			cin >> name >> type;
			arr[type]++;
		}
		int cnt = 1;
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			cnt *= (iter->second + 1);
		}
		cnt -= 1;
		cout << cnt << '\n';
	}
}