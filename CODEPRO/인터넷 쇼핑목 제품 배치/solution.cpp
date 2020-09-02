#include <iostream>
using namespace std;

int N;               // ��ǰ�� ����
int ID[10000 + 10];  // ���̵�
int S[10000 + 10];   // �Ǹż���
int R[10000 + 10];   // ��ȸȸ��

// �� ��ġ�� ���� ��ȯ�ϴ� �Լ�
void swap(int x1, int x2)
{
	int temp;

	temp = ID[x1];
	ID[x1] = ID[x2];
	ID[x2] = temp;

	temp = S[x1];
	S[x1] = S[x2];
	S[x2] = temp;

	temp = R[x1];
	R[x1] = R[x2];
	R[x2] = temp;
}

int main(void)
{
	int i, j;

	// �Է� �б�
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> ID[i] >> S[i] >> R[i];
	}

	// ��ȣ�� ������ ����
	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			if (S[i] < S[j]) {
				swap(i, j);
			}
			else if (S[i] == S[j]) {
				if (R[i] < R[j]) {
					swap(i, j);
				}
				else if (R[i] == R[j]) {
					if (ID[i] < ID[j]) {
						swap(i, j);
					}
				}
			}
		}
	}

	// ��� ���
	for (i = 0; i < N; i++) {
		cout << ID[i] << " ";
	}

	return 0;
}
