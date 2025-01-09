
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum { false, true } bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        if (Insert(L, X, 0) == false)
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &P);
        if (Delete(L, P) == false)
            printf(" Deletion Error.\n");
        if (Insert(L, 0, P) == false)
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List MakeEmpty() {
    List New = (List)malloc(sizeof(struct LNode));
    New->Last = -1;
    return New;
}

Position Find(List L, ElementType X) {
    Position i = 0;
    while ((i <= L->Last) &&
           (X != L->Data[i])) {
        ++i;
    }
    if (i <= L->Last) {
        return i;
    } else {
        return ERROR;
    }
}

bool Insert(List L, ElementType X, Position P) {
    int i = 0;
    if ( L->Last == MAXSIZE - 1) {
        printf("FULL");
        return false;
    }
    if ((P < 0) || 
        (P > L->Last + 1)) {
        printf("ILLEGAL POSITION");
        return false;
    }
    // 调整元素的位置
    for(i = L->Last; i >= P; --i) {
        L->Data[i+1] = L->Data[i];
    }
    L->Data[P] = X;
    ++(L->Last);
    return true;
}

bool Delete(List L, Position P) {
    int i = 0;
    if ((P < 0) || 
        (P > L->Last)) {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    for (i = P; i < L->Last; ++i) {
        L->Data[i] = L->Data[i+1];
    }
    --(L->Last);
    return true;
}