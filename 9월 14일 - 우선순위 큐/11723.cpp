#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n , num;
	string s; 
	bool arr[21] = { false }; 
	cin >> n;

	while (n--) {
		cin >> s;
		if (s == "add") {
			cin >> num;
			arr[num] = true;
		}
		else if (s == "remove") {
			cin >> num;
			arr[num] = false;

		}
		else if (s == "check") {
			cin >> num;
			if (arr[num]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "toggle") {
			cin >> num;
			if (arr[num]) arr[num] = false;
			else arr[num] = true;

		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++)
				arr[i] = true;
		}
		else { /*empty*/ 
			for (int i = 1; i <= 20; i++)
				arr[i] = false;
		}
	}
}