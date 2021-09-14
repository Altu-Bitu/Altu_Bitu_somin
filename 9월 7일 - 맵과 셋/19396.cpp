#include <iostream>
#include <cmath>

using namespace std;

/* 백준에서 틀렸다는데 왜 틀렸는지 잘 모르겠어요 ㅠㅠ */

int main() {
	int w, daily, T; // 다이어트 전 체중, 섭취량/대사량 , 기초대사량 변화 역치
	int days, e_input, e_output; // 다이어트 기간, 에너지 섭취량, 활동 대사량

	cin >> w >> daily >> T;
	cin >> days >> e_input >> e_output;

	int daily2 = daily; //  기초대사량 
	int total_output = daily + e_output; // 하루 E 총 소비량 

	/* case 1 */
	int w1 = w + days * (e_input - total_output); // case1 weight 
	if (w1 <= 0) cout << "Danger Diet\n";
	else
		cout << w1 << " " << daily << '\n';

	/* case 2 */
	int w2 = w; // case 2 weight
	
	for (int i = 0; i < days; i++) {
		total_output = daily2 + e_output;
		w2 += e_input - total_output;
		if (abs(e_input - total_output) > T)
			daily2 += floor((e_input - total_output) / 2.0);
	}
	
	if (w2 <= 0 || daily2 <= 0) cout << "Danger Diet\n";
	else {
		cout << w2 << ' ' << daily2 << ' ';
		if (daily - daily2 > 0) cout << "YOYO";
		else cout << "NO";
	}

}