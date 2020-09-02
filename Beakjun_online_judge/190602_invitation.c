/* 190602 백준-트리-이장님초대 문제 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tagSBTNode {
    int Data;
    struct tagSBTNode* Left;
    struct tagSBTNode* Right;
} SBTNode;

// function declaration
SBTNode*  SBT_CreateNode( int NewData );
void      SBT_DestroyNode( SBTNode* Node );
void      SBT_DestroyTree( SBTNode* Root );
void      SBT_PreorderPrintTree( SBTNode* Node );
void      SBT_InorderPrintTree( SBTNode* Node );
void      SBT_PostorderPrintTree( SBTNode* Node );

// main function
int main (void) {
    
    int n;
    int num_node;
    scanf("%d", &num_node);
    
    for(n=0; n<num_node; n++){
        int temp;
        scanf("%d", &temp);
        SBT_Create(temp);
    }
    
    return 0;
}

// function definition
SBTNode* SBT_CreateNode( int NewData )
{
    SBTNode* NewNode = (SBTNode*)malloc( sizeof(SBTNode) );
    NewNode->Left    = NULL;
    NewNode->Right   = NULL;
    NewNode->Data    = NewData;

    return NewNode;
}

void SBT_DestroyNode( SBTNode* Node )
{
    free(Node);
}

void SBT_DestroyTree( SBTNode* Node )
{
    if ( Node == NULL )
        return;

    SBT_DestroyTree( Node->Left );
    SBT_DestroyTree( Node->Right );
    SBT_DestroyNode( Node );
}

void SBT_PreorderPrintTree( SBTNode* Node )
{
    if ( Node == NULL )
        return;

    printf( " %c", Node->Data );
    SBT_PreorderPrintTree( Node->Left );
    SBT_PreorderPrintTree( Node->Right );
}

void SBT_InorderPrintTree( SBTNode* Node )
{
    if ( Node == NULL )
        return;
    
    SBT_InorderPrintTree( Node->Left );
    printf( " %c", Node->Data );
    SBT_InorderPrintTree( Node->Right );
}

void SBT_PostorderPrintTree( SBTNode* Node )
{
    if ( Node == NULL )
        return;
    
    SBT_PostorderPrintTree( Node->Left );
    SBT_PostorderPrintTree( Node->Right );
    printf( " %c", Node->Data );
}