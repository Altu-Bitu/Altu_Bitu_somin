// 링크와 스타트 
#include <iostream>

using namespace std;

const int SIZE = 20;
int team[SIZE + 1][SIZE + 1];
bool check[SIZE + 1];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> team[i][j];
		}
	}
}