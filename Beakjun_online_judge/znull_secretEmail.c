/* 190721 백준-행렬-비밀이메일 */

#include <stdio.h>

char buffer[101] = {'\0', };
char original[101][101] = {'\0', };
int SIZE = 0;
int R, C;

void INPUT();
int getR();
void PRINT();
void CODING();

int main(void){
    
    INPUT();
    R = getR();
    C = SIZE/R;
    CODING();
    PRINT();

    return 0;
}

void INPUT(){
    scanf("%[^\n]", &buffer);
    while(buffer[SIZE] != '\0'){
        SIZE++;
    }

    // printf("%d", SIZE);
}

int getR(){
    int r = 1, c = SIZE;
    int rest = 0;
    int maxR = 1;

    while(1){
        if(r > c){break;}

        c = SIZE/r;
        rest = SIZE%r;
        if(rest == 0 && maxR < r){
            maxR = r;
        }

        r++;
    }
    
    return maxR;
}

void PRINT(){
    int x, y, cnt=0;
    for(x=0; x<C; x++){
        for(y=0; y<R; y++){
            // buffer[cnt] = original[x][y];
            // cnt++;
            printf("%c", original[x][y]);
        }
    }
    // buffer[cnt] = '\0';

    // printf("%[^\n]", buffer);

    return;
}

void CODING(){
    int x, y, cnt = 0;
    for(y=0; y<R; y++){
        for(x=0; x<C; x++){
            original[x][y] = buffer[cnt];
            cnt++;
        }
    }
    return;
}