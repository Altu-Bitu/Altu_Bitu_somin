#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, M;
	string str;
	set<string> arr;

	cin >> N >> M;
	while(N--) {
		cin >> str;
		arr.insert(str);
	}
	int cnt = 0;
	while (M--) {
		cin >> str;
		if (arr.count(str)) cnt++;
	}
	cout << cnt << '\n';
	
}