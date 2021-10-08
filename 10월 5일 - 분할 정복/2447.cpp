//별찍기
#include <iostream>

using namespace std;

void draw_star(int i, int j, int n) {
	//빈칸일 조건 
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
		cout << " ";
	}
	else {
		if (n == 1)  cout << "*"; //별찍기 (n/3 == 0)도 가능 
		else draw_star(i, j, n / 3);
	}
}

/*
* 빈 칸일 조건 
* ex) 3*3배열 i,j -> (1,1)
* ex) 9*9배열 i,j -> (1.1) (1.4) (1.7) 
*			  i,j ->  3~ 5로 이루어진 모든 경우의수 
*			  i,j -> (7,1) (7,4) (7,5) 
*/

int main(){
	int n;
	
	//입력
	cin >> n;

	//연산 & 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			draw_star(i, j, n);
		}
		cout << "\n";
	}

	return 0;
}