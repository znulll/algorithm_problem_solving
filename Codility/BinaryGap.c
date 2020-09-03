// https://app.codility.com/demo/results/trainingY24M7H-XF2/

int IN;
int BIN[40] = {0, };
int LENGTH = 0;

// void INPUT(){
//     scanf("%d", &IN);
// }

void dec2bin(int N){
    int pointer = 0;
    while(N != 0){
        if(N%2 == 0) BIN[pointer] = 0;
        else if(N%2 == 1) BIN[pointer] = 1;
        pointer += 1;
        LENGTH += 1;
        N = N/2;
    }
}

int getMaxGap(){
    int max = 0;
    int flag = 0;
    int i;
    int temp = 0;
    
    for(i=0; i<LENGTH; i++){
        if(BIN[i] == 1){
            if (flag == 0) {
                flag = 1;
                temp = i;
            }
            else if (flag == 1) {
                temp = i - temp - 1;
                if(temp > max) {max = temp;}
                temp = i;
            }
        }
    }
    
    return max;
}

int solution(int N) {
    dec2bin(N);
    int gap = getMaxGap();
    
    return gap;
}