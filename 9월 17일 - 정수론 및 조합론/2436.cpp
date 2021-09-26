#include <iostream>
#include <cmath>

using namespace std;


int calcGCD(int x, int y) { // �׻� x >= y �̹Ƿ� ��Ұ��踦 üũ���� ����
	int tmp; // gcd ���� ���� 
	while (y != 0) {
		tmp = x % y; 
		x = y;
		y = tmp;
	}
	return x;
}

int main() {
	int gcd, lcm; // �ִ�����, �ּҰ���� 
	cin >> gcd >> lcm; // �Է� 

	//����
	int ab = lcm / gcd;
	int a = -1, b = -1;
	//a, b�� ���̰� ���� ���� �����ٺ��� üũ
	for (int i = sqrt(ab); i > 0; i--) {
		if (ab % i != 0) continue;
		//i�� ab�� ������
		int tmp_a = i, tmp_b = ab / i;
		//�� ���� ���μ����� üũ -> ���� �� ���� ���μҰ� �ƴ϶�� �� ���� �ִ������� gcd�� �� �� ����
		if (calcGCD(tmp_b, tmp_a) == 1) {
			a = tmp_a;
			b = tmp_b;
			break;
	}
		
		cout << a * gcd << ' ' << b * gcd; //���
}