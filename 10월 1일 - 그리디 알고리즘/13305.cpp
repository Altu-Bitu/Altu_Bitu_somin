//주유소
#include <iostream>
#include <vector>

using namespace std;
vector<int> cities, road;

long long min_cost(int n) {
	long long min_cost = cities[0]; //initialize
	long long cost = 0; //비용
	for (int i = 0; i < n-1; i++) {
		if (cities[i] < min_cost) min_cost = cities[i];
		cost += min_cost * road[i];
	}
	return cost;
}

int main() {
	int n; //도시의 수
	
	//입력
	cin >> n;
	
	cities.assign(n, 0);
	road.assign(n - 1, 0);

	for (int i = 0; i < n-1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cities[i];
	}

	//연산 & 출력
	cout << min_cost(n) <<'\n';

}