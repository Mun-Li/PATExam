// Author: MMM
// Time :2023-02-08
// https://pintia.cn/problem-sets/15/exam/problems/724
// 单链表的逆转

// 利用循环的方法
List Reverse(List L)
{
    List pre = NULL;
    List nex;
    while (L)
    {
        nex = L->Next;
        L->Next = pre;
        pre = L;
        L = nex;
    }
    return pre;
}
