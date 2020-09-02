#include <stdio.h>

int N;               // 제품의 개수
int ID[10000 + 10];  // 아이디
int S[10000 + 10];   // 판매수량
int R[10000 + 10];   // 조회회수

// 두 위치의 값을 교환하는 함수
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


	// 입력 읽기
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &ID[i], &S[i], &R[i]);
	}

	// 선호도 순으로 정렬
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

	// 결과 출력
	for (i = 0; i < N; i++) {
		printf("%d ", ID[i]);
	}

	return 0;
}