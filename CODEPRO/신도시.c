#include <stdio.h>

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보
int check[20][20]={0,};
int DRT[12][4]={0,};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void make_Direction(int r, int c){
	switch(map[r][c]){
		case 0:
			break;
		case 1:
			{
			DRT[map[r][c]][0] = 0;
			DRT[map[r][c]][1] = 0;
			DRT[map[r][c]][2] = 1;
			DRT[map[r][c]][3] = 1;
			}
			break;
		case 2:
			{
			DRT[map[r][c]][0] = 1;
			DRT[map[r][c]][1] = 1;
			DRT[map[r][c]][2] = 0;
			DRT[map[r][c]][3] = 0;
			}
			break;
		case 3:
			{
			DRT[map[r][c]][0] = 0;
			DRT[map[r][c]][1] = 1;
			DRT[map[r][c]][2] = 0;
			DRT[map[r][c]][3] = 1;
			}
			break;
		case 4:
			{
			DRT[map[r][c]][0] = 0;
			DRT[map[r][c]][1] = 1;
			DRT[map[r][c]][2] = 1;
			DRT[map[r][c]][3] = 0;
			}
			break;
		case 5:
			{
			DRT[map[r][c]][0] = 1;
			DRT[map[r][c]][1] = 0;
			DRT[map[r][c]][2] = 1;
			DRT[map[r][c]][3] = 0;
			}
			break;
		case 6:
			{
			DRT[map[r][c]][0] = 1;
			DRT[map[r][c]][1] = 0;
			DRT[map[r][c]][2] = 0;
			DRT[map[r][c]][3] = 1;
			}
			break;
		case 7:
			{
			DRT[map[r][c]][0] = 1;
			DRT[map[r][c]][1] = 1;
			DRT[map[r][c]][2] = 0;
			DRT[map[r][c]][3] = 1;
			}
			break;
		case 8:
			{
			DRT[map[r][c]][0] = 0;
			DRT[map[r][c]][1] = 1;
			DRT[map[r][c]][2] = 1;
			DRT[map[r][c]][3] = 1;
			}
			break;
		case 9:
			{
			DRT[map[r][c]][0] = 1;
			DRT[map[r][c]][1] = 1;
			DRT[map[r][c]][2] = 1;
			DRT[map[r][c]][3] = 0;
			}
			break;
		case 10:
			{
			DRT[map[r][c]][0] = 1;
			DRT[map[r][c]][1] = 0;
			DRT[map[r][c]][2] = 1;
			DRT[map[r][c]][3] = 1;
			}
			break;
		case 11:
			{
			DRT[map[r][c]][0] = 1;
			DRT[map[r][c]][1] = 1;
			DRT[map[r][c]][2] = 1;
			DRT[map[r][c]][3] = 1;
			}
			break;
	}
	return;
}

void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			scanf("%1x", &map[i][j]);
			make_Direction(i, j);
		}
	}
}

void DFS(int r_to, int c_to, int r_from, int c_from){
	int i;
	int r_gap, c_gap;
	int to_dir;
	
	if(r_to <0 || r_to >=N || c_to <0 || c_to >=N) return;
	if(map[r_to][c_to] == 0) return;

	if(r_to == r_from && c_to == c_from ){
        //printf("init \n");
    }
	else{
		r_gap = r_to - r_from;
		c_gap = c_to - c_from;
        //printf("r_gap : %d, c_gap : %d\n", r_gap, c_gap);
		if(r_gap == 1 && c_gap == 0) to_dir = 0;
		else if(r_gap == -1 && c_gap == 0) to_dir = 1;
		else if(r_gap == 0 && c_gap == -1) to_dir = 3;
		else if(r_gap == 0 && c_gap == 1) to_dir = 2;
		
		if(DRT[map[r_to][c_to]][to_dir] == 0) return;
	}
	
	if(	check[r_to][c_to] == 1) return;
    //printf("r_to : %d, c_to : %d ... r_from : %d c_from : %d\n", r_to, c_to, r_from, c_from);
	
	check[r_to][c_to] = 1;
	
	for(i=0; i<4; i++){
		if(DRT[map[r_to][c_to]][i] == 0) continue;
		int new_r = r_to + dr[i];
		int new_c = c_to + dc[i];

		DFS(new_r, new_c, r_to, c_to);
	}
	
	return;
}

int sum_Check(){
	int sum = 0;
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			sum += check[i][j];
			if(map[i][j] == 0) sum++;
		}
	}
	return sum;
}

int main(void){
	int ans = -1;
	int water;
	Input_Data();		//	입력 함수
	
	DFS(X, Y, X, Y);
	
	water = sum_Check();
	ans = N*N - water;
	
	printf("%d\n", ans);		//	정답 출력
	return 0;
}
