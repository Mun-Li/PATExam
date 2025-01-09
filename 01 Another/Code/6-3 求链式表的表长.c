// 这里需要注意一点
// 函数的形参为指针，为了防止改变指针的内容
// 需要在函数内部重新定义一个指针
int Length(List L) {
    PtrToLNode P = L;
    int i = 0;
    while (P) {
        ++i;
        P = P->Next;
    }
    return i;
}