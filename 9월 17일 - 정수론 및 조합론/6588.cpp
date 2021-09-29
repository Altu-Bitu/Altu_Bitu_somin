#include <iostream>
#include <vector>
#define SIZE 1000000

using namespace std; 

// �����佺�׳׽��� ä�� �̿��� �̸� SIZE������ �Ҽ� �Ǻ� 
vector<bool> isPrime() {
	vector<bool> is_prime(SIZE + 1, true); //�Ҽ� �Ǵ� ���� ����

	is_prime[0] = is_prime[1] = false; // 0�� 1 �Ҽ� �ƴ� 
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (is_prime[i]) { //i�� �Ҽ����
			for (int j = i * i; j <= SIZE; j += i)
				is_prime[j] = false; //i�� ��� ����
		}
	}

	return is_prime;
}

//�������� ���� �Ǵ� �Լ�
int checkGoldbach(int n, vector<bool>& is_prime) {
	for (int i = 3; i <= n / 2; i += 2) { //Ȧ���� �˻�, n/2 �̻��� ���� ������ n-i�� ���� �˻�ǹǷ� n/2���� �˻�
		if (is_prime[i] && is_prime[n - i]) { //�� Ȧ�� ��� �Ҽ���� (�������� ������ ���� ���)
			return i; //�� Ȧ�� �Ҽ� �� ���� �� ����
		}
	}
	return 0; //�������� ������ Ʋ�� ���
}

int main() {
	// ����¼ӵ� ��� 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	int n; // �Է� ���� ���� ���� 
	vector<bool> is_prime = isPrime(); // �Ҽ� �Ǵ� ���� ����


	while (true) {
		cin >> n; // �Է¹ޱ� 
		if (n == 0) return; // 0�̸� ���� Ż��

		int prime = checkGoldbach(n, is_prime); //������ ���� �´��� Ȯ��
		if(prime)  cout << n << " = " << prime << " + " << n - prime << '\n'; // �� Ȧ�� �Ҽ� �� ���� �� ���Ϲ��� ��� 
		else cout << "Goldbach's conjecture is wrong.\n"; // 0 (Ʋ�� ���)

	}

	return 0; 
}