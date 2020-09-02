#include <stdio.h>
#define MAXN (100+1)

int X, Y;
int sx, sy, ex, ey;
char MAP[MAXN][MAXN] = { 0, };
int VISIT[MAXN][MAXN] = { 0, };

struct Q{
	int r, c, t;
};

struct Q queue[MAXN * MAXN];
int wp, rp;

void push(int r, int c, int t) {
	if (MAP[r][c] != '0') return;
	if (VISIT[r][c] == 1)  return;
	VISIT[r][c] = 1;
	queue[wp].r = r;
	queue[wp].c = c;
	queue[wp].t = t;
	wp++;
}

struct Q front(void){
	return queue[rp];
}

void pop(void) {
	rp++;
}

int size(void) {
	return wp - rp;
}

int empty(void) {
	return wp == rp;
}

void INPUT(void) {
	int i;
	scanf_s("%d %d", &X, &Y);
	scanf_s("%d %d %d %d", &sx, &sy, &ex, &ey);
	for (i = 1; i <= Y; i++) {
		scanf_s("%s", &MAP[i][1]);
	}
}

int BFS(void) {
	struct Q cur;
	int dr[] = {-1, 1,  0, 0 };
	int dc[] = { 0, 0, -1, 1 };
	int i;
	wp = rp = 0;
	push(sy, sx, 0);
	while (!empty()) {
		cur = front();
		pop();
		if ((cur.r == ey) && (cur.c == ex)) {
			return cur.t;
		}
		for (i = 0; i < 4; i++){
			push(cur.r + dr[i], cur.c+dc[i], cur.t+1);
		}
	}
	return -1;
}

int main(void) {
	int ans;
	INPUT();
	ans = BFS();
	printf("%d", ans);

	return 0;
}
