/* 190505 백준-스택-쇠막대기 문제 */

#include <stdio.h>

// 함수 선언
char* getLaser(char* INPUT, int inputLength);
char* getBar(char* INPUT, int inputLength);
int getBarCount(char* Laser, char* Bar, int inputLength);

int main(void){
    
    // 배열 개수를 어떻게 알지?
    int c;
    int inputLength;    
    char INPUT[100000];
    int barCount;
    
    scanf("%c", INPUT);
    for(c=0; c<10000; c++){
        if(INPUT[c] != ")" || INPUT[c] != "("){
            inputLength++;
        }
        else{
            INPUT[c] = ".";    
        }    
    }

    for(c=0; c<inputLength; c++){
        Laser[c] = INPUT[c];
        Bar[c] = INPUT[c];
    }    
    char Laser[inputLength] = getLaser(INPUT, inputLength);
    char Bar[inputLength] = getBar(INPUT, inputLength);
    
    barCount = getBarCount(Laser, Bar, inputLength);
    printf("Total Bar Count : %d", barCount);
    
    return 0;
}

char* getLaser(char* INPUT, int inputLength){
    int i;
    for(i=0; i<inputLength; i++){
        if(i<0 && INPUT[i-1]== '(' && INPUT[i]== ')'){
            INPUT[i-1] = 'L';
            // INPUT[i] = 'L';
        }
    }
    return INPUT;
}

char* getBar(char* INPUT, int inputLength){
    int i;
    char character = 'a';
    while(1){
        int count = 0;
        int check = 0;
        for(i=0; i<inputLength; i++){
            if(count == 0){
                if(i<0 && INPUT[i-1]=="(" && INPUT[i]==")"){
                    INPUT[i-1] = character;
                    INPUT[i] = character;
                }
            }
            if(INPUT[i+1] == (char)((int)character - 1)){
                INPUT[i] = character;
            }
            if( (INPUT[i] == (char)((int)character - 1)) && INPUT[i+1] != (char)((int)character - 1)) ){
                INPUT[i+1] = character;
            }
        }
        // 변화가 있는지 체크
        for(i=0; i<inputLength; i++){
            if(INPUT[i] == character){
                check++;
            }
        }
        // 종료 조건
        if(check == 0){
            break;
        }

        int int_character = (int)character + 1;
        character = (char)int_character;
        count++;
    }
    return INPUT;    
}

int getBarCount(char* Laser, char* Bar, int inputLength){
    int i;
    int BarCount;
    char character = 'a';
        while(1){
            char checkChar = 'a';
            int check = 0;
            for(i=0; i<inputLength; i++){
                if(Bar[i] == character){
                    if(Laser[i] == 'L'){
                        BarCount++;
                    }
                }
                else if(Bar[i-1] == character && Bar[i] != character)
                {
                    BarCount++;                  
                }
            }
            // 변화가 있는지 체크
            for(i=0; i<inputLength; i++){
                if(Bar[i] == checkChar){
                    check++;
                }
            }
            // 종료 조건
            if(check == 0){
                break;
            }
            
            check = 0;
            int int_character = (int)character + 1;
            character = (char)int_character;
            checkChar = character;         
            count++;
        }

    return BarCount;
}
