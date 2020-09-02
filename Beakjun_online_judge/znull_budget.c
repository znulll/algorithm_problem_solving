#include <stdio.h>
#define MAXN ((int) 10001)

int N = 0;						// 3 < N < 10,000
int BUDGET[MAXN] = { 0, };	// 1 < BUDGET[i] < 10,000
int M = 0;						// N < M < 1,000,000,000

void INPUT() {
	int i;
	scanf_s("%d", &N);
	for (i = 0; i < N; i++) {
		scanf_s("%d", &BUDGET[i]);
	}
	scanf_s("%d", &M);
}

int CHECK(int bound) {
	int i, temp_budget = M;

	for (i = 0; i < N; i++) {
		if (BUDGET[i] <= bound) {
			temp_budget -= BUDGET[i];
		}
		else {
			temp_budget -= bound;
		}

		if (temp_budget < 0) {
			return 0;
		}
	}
	
	return 1;
}

int SOLVE() {
	int i, bound, sol = 0, start = 0, end = 0;

	for (i = 0; i < N; i++) {
		if (end < BUDGET[i]) {
			end = BUDGET[i];
		}
	}

	while (start <= end) {
		bound = (start + end) / 2;
		
		if (CHECK(bound) == 1) {
			sol = bound;
			start = bound + 1;
		}
		else{
			end = bound - 1;
		}
	}

	return sol;
}

int main(void) {
	int ans;
	INPUT();
	ans = SOLVE();
	printf("%d", ans);

	return 0;
}

