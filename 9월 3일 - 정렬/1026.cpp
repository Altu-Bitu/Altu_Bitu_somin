#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int sum = 0;
	vector<int> a, b;

	cin >> N;
	// initialize 
	a.assign(N, 0);
	b.assign(N, 0);
	
	for (int i = 0; i < N; i++) cin >> a[i]; // a array 
	for (int i = 0; i < N; i++) cin >> b[i]; // b array
		
	sort(a.begin(), a.end()); // sorting a smallest -> largest
	sort(b.begin(), b.end(), greater<int>()); // sorting largest -> smallest

	for (int i = 0; i < N; i++) {
		sum += a[i] * b[i];
	}
	
	cout << sum << "\n";
}