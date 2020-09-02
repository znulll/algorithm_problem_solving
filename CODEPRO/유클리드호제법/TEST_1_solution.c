#include <stdio.h>

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
	scanf("%d %d",&m, &n);
	
	// ū���� ���� m�� ����
	if (m < n)
	{
		r = m; m = n; n = r;
	}
	
	r = GCD(m,n);

	printf("%d\n",r);
}