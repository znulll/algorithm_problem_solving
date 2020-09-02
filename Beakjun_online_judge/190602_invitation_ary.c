/* 190602 백준-트리-이장님초대 문제 */

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
void quick_sort(int* array, int start, int end);
int get_max(int* array);

int main (void) {
    
    int invitation;
    int n;
    int num_node;
    scanf("%d", &num_node);
    int tree[num_node];

    for(n=0; n<num_node; n++){
        scanf("%d", &tree[n]);
    }

    quick_sort(tree, 0, num_node-1);
    
    for(n=num_node-1; n >= 0; n--){
        tree[n] += (num_node-n);
        printf("%d\n", tree[n]);
    }

    invitation = get_max(tree) + 1;
    printf("answer : %d\n", invitation);

    return 0;
}

void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
 
void quick_sort(int* array, int start, int end){
 
    if(start>=end) return;
 
    int mid=(start+end)/2;
    int pivot=array[mid];
 
    swap(&array[start],&array[mid]);
 
    int p=start+1,q=end;
 
    while(1){
        while(array[p]<=pivot){ p++; }
        while(array[q]>pivot){ q--; }
 
        if(p>q) break; 
        swap(&array[p],&array[q]);
    }
 
    swap(&array[start],&array[q]);
    quick_sort(array,start,q-1);
    quick_sort(array,q+1,end);
}

int get_max(int* array){
    int i;
    int max = 0;
    int size = sizeof(array)/sizeof(int);
    for(i=0; i<size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    return max;
}