#include <iostream>
using namespace std;

int GCD(int m, int n);

// �ۼ��ؾ� �� �Լ�
int GCD(int m, int n)
{
	return n ? GCD(n, m%n) : m;
}

int main(void)
{
	int m, n, r;
	
	// �Է� �޴� �κ�
	cin >> m >> n;
	
	// ū���� ���� m�� ����
	if (m < n)
	{
		r = m; m = n; n = r;
	}

	r = GCD(m,n);

	cout << r;
}