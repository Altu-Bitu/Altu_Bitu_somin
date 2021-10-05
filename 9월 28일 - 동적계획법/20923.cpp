//숫자 할리갈리 게임 -> 메모리 초과 

#include <iostream>
#include <queue>

using namespace std;

deque<int> player[2]; //dodo, su
deque<int> ground[2];  //ground


void update_card(int winner) {
	int loser = abs(winner - 1);
	// 상대편꺼 내꺼로 
	while (!ground[loser].empty()) {
		player[winner].push_back(ground[loser].back());
		ground[loser].pop_back();
	}
	// 내꺼
	while (!ground[winner].empty()) {
		player[winner].push_back(ground[winner].back());
		ground[winner].pop_back();
	}
}

bool check_winner() {
	// dodo wins 
	if (!ground[0].empty() && ground[0].front() == 5 || !ground[0].empty() && ground[1].front() == 5) update_card(0);
	// su wins
	if (!ground[1].empty() && !ground[1].empty() && ground[0].front() + ground[1].front() == 5) update_card(1);
}


string halli_galli(int m) {
	int idx = 0; // dodo 부터 시작
	for (int i = 0; i < m; i++) {
		ground[idx].push_front(player[idx].front()); //ground로 카드 삽입
		player[idx].pop_front(); //player card update

		//카드가 없는 경우
		if (player[idx].empty()) {
			if (idx == 1) return "do";
			else return "su";
		}
		//calculate winner
		check_winner();

		// update idx 
		idx = abs(idx - 1);
	}

	//카드 남은 경우 
	if (player[0].size() > player[1].size()) return "do";
	else if (player[0].size() < player[1].size()) return "su";
	return "dosu";

}


int main() {
	int n, m;
	int idx = 0; //누가 먼저 하는지 나타내는 idx
	int cd1, cd2; //card1 & card2 

	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cd1 >> cd2;
		player[0].push_front(cd1);
		player[1].push_front(cd2);
	}
	
	//연산
	string result = halli_galli(m);
	
	//출력
	cout << result << '\n';

}