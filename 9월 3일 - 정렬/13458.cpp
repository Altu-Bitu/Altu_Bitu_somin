#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, b, c;
	long long cnt = 0; // total number of supervisors 
	cin >> N; 
	
	vector<int> arr;  
	arr.assign(N, 0);  // initialize

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> b >> c; 

	for (int i = 0; i < N; i++) {
		int temp = arr[i];
		// main supervisor 
		temp -= b;
		cnt++;
		if (temp <= 0) continue;
		// sub supervisor 
		cnt += (temp / c);
		if (temp % c > 0) cnt++;
	}
	cout << cnt << "\n";
}