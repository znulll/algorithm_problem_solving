#include <stdio.h>

int GCD(int m, int n);

// 작성해야 할 함수
int GCD(int m, int n)
{
	return n ? GCD(n, m%n) : m;
}

int main(void)
{
	int m, n, r;
	
	// 입력 받는 부분
	scanf("%d %d",&m, &n);
	
	// 큰수를 변수 m에 대입
	if (m < n)
	{
		r = m; m = n; n = r;
	}
	
	r = GCD(m,n);

	printf("%d\n",r);
}