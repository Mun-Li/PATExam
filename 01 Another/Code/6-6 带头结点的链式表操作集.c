#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
// 带头结点的链式表
List MakeEmpty() {
    List New = (List)malloc(sizeof(struct LNode));
    New->Next = NULL;
    return New;
}

Position Find(List L, ElementType X) {
    List NewL = L->Next;
    while (NewL != NULL && 
           NewL->Data != X) {
        NewL = NewL->Next;
    }
    if (NewL)  return NewL;
    return ERROR;
}

bool Insert(List L, ElementType X, Position P) {
    List NewL = L->Next;
    List New = (List)malloc(sizeof(struct LNode));
    New->Data = X;
    New->Next = P;
    if (NewL == P) {
        L->Next = New;
        return true;
    }
    while (NewL != NULL && 
           NewL->Next != P) {
        NewL = NewL->Next;
    }
    if (NewL) {
        NewL->Next = New;
        return true;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete(List L, Position P) {
    List NewL = L->Next;
    if (NewL && 
        NewL == P) { 
        L->Next = P->Next;
        free(P);
        return true;
    }
    while (NewL != NULL && 
           NewL->Next != P) {
        NewL = NewL->Next;
    }
    if (NewL && P) {
        NewL->Next = P->Next;
        free(P);
        return true;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}
