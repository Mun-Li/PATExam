#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    for (P = L; P; P = P->Next) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(List L, ElementType X) {
    List NewL = L;
    while ((NewL != NULL) &&
           (X != NewL->Data)) {  // 注意判断条件的顺序
        NewL = NewL->Next;
    }
    return NewL;
}

List Insert(List L, ElementType X, Position P) {
    List NewL = L;
    List New = (List)malloc(sizeof(struct LNode));
    New->Data = X;
    New->Next = P;
    if (L == P)  return New;
    while ((NewL != NULL) &&
           (NewL->Next != P)) {  // 找到该节点的前一个节点
        NewL = NewL->Next;
    }
    if (NewL != NULL) {
        NewL->Next = New;
        return L;
    }
    else {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
}

List Delete(List L, Position P) {
    List NewL = L;
    if ((L != NULL) && 
        (L == P)) {  // 这里要注意空链表的问题
        NewL = L->Next;
        free(P);
        return NewL;
    }
    while ((NewL != NULL) &&
           (NewL->Next != P)) {  // 先找到P的上一个节点
        NewL = NewL->Next;
    }
    if (NewL != NULL && P) {
        NewL->Next = P->Next;
        free(P);
        return L;
    }
    else {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
}
