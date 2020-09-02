#include <stdio.h>

int getDamage(int* landmine, int position, int size);
int getMaxDamageIndex(int* landmine, int size);
void afterDamage(int* landmine, int MaxDamageIndex, int size);
int isThatClear(int* landmine, int size);
void printLandmine(int* landmine, int size);

int main(void){
    int i;
    int size;
    scanf("%d", &size);
    printf("size : %d\n", size);
    
    int landmine[size];

    for(i=0; i<size; i++){
        scanf("%d\n", &landmine[i]);
        // printLandmine(landmine, size);
    }

    while(isThatClear(landmine, size) != 0){
        printf("%d\n", getMaxDamageIndex(landmine, size));
        afterDamage(landmine, getMaxDamageIndex(landmine, size), size);        
        // printLandmine(landmine, size);
    }

    return 0;
}

int getDamage(int* landmine, int position, int size){
    // int size = sizeof(landmine)/sizeof(int);
    int damage = 0;
    int i = 0;
    int j = 0;

    // position 자신이 터진 데미지
    damage += landmine[position];
    // position 기준 좌측 지뢰에 입힌 데미지
    while(position-i > 0){
        if(landmine[position-(i+1)] < landmine[position-i]){
            damage += landmine[position-(i+1)];
        }
        else{
            break;
        }
        i++;
    }
    // position 기준 우측 지뢰에 입힌 데미지
    while(position+j < size){
        if(landmine[position+(j+1)] < landmine[position+j]){
            damage += landmine[position+(j+1)];
        }
        else{
            break;
        }
        j++;
    }

    return damage;
}

int getMaxDamageIndex(int* landmine, int size){
    // int size = sizeof(landmine)/sizeof(int);
    int damage[size];
    int i;
    int max = 0;
    int maxIndex = 0;
    for(i=0; i<size; i++){
        damage[i] = getDamage(landmine, i, size);
        if(damage[i] > max){
            max = damage[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

void afterDamage(int* landmine, int MaxDamageIndex, int size){
    int s;
    int i=0;
    int j=0;
    int position = MaxDamageIndex;
    int damage = getDamage(landmine, position, size);
    
    // position 자신이 터진 데미지
    landmine[position] = 0;
    // position 기준 좌측 지뢰에 입힌 데미지
    while(position-i > 0){
        if(landmine[position-(i+1)] < landmine[position-i]){
            landmine[position-(i+1)] = 0;
        }
        else{
            break;
        }
        i++;
    }
    // position 기준 우측 지뢰에 입힌 데미지
    while(position+j < size){
        if(landmine[position+(j+1)] < landmine[position+j]){
            landmine[position+(j+1)] = 0;    
        }
        else{
            break;
        }
        j++;
    }
}

int isThatClear(int* landmine, int size){
    int Sum = 0;
    // int size = sizeof(landmine)/sizeof(int);
    int i;
    for(i=0; i<size; i++){
        Sum += landmine[i];
    }
    return Sum;
}

void printLandmine(int* landmine, int size){
    // int size = sizeof(landmine)/sizeof(int);
    int i;
    
    printf("Landmine : [");
    for(i = 0; i < size; i++){
        printf("%d ", landmine[i]);
    }
    printf("]\n");
}