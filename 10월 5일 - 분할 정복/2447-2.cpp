//별찍기
#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> arr; //별찍기 저장할 벡터

//재귀함수 이용해 별 저장하기 
//9등분 한 후 가운데는 건너띄기 
void draw_star(int i, int j, int n) {
	//빈칸일 조건 
	if (n == 1) arr[i][j] = '*';
	else {
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				if (a == 1 && b == 1) continue; //가운데 빈곳은 건너띄기
				else draw_star(i + (a * (n / 3)), j + (b * (n / 3)), n / 3); 
			}
		}
	}
}

/*
* < 재귀적 방법 >
* 별찍기의 상태를 저장할 벡터를 만들고, 
* 재귀함수를 한 번돌며 벡터에 별을 채우기 
*/

int main() {
	int n;

	//입력
	cin >> n;
	arr.assign(n, vector<char>(n, ' '));

	//연산
	draw_star(0,0,n);

	//출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}