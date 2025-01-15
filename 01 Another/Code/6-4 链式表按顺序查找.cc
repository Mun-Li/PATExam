// 如果i一直不等于K的话
// 程序将会一直将指针往后移动，直到指向了空指针
// （其实这里还可以在提高一下程序的效率）
// 详细的讨论见方法二
ElementType FindKth(List L, int K) {
    List P = L;
    int i = 1;
    while ((i != K) &&
           (P != NULL)) {
        i++;
        P = P->Next;
    }
    if (P) {
        return P->Data;
    } else {
        return ERROR;
    }
}


// 针对原来出现的问题
// 我们将最后判断的返回进行了修改
// i==K，才返回我们所需要的指针，这样就避免了K < i的时候，
// 直接就返回头指针的尴尬了
// 相比于方法一，方法二更多的体现在效率上，
// K < i的时候，直接就推出循环了，不用搜索整个链表呢
// 基于这个思想，我们还可以在前面判断一下 i和K的关系，也就提出了方法三
// 当然本质上是一样的，而这样程序的效率就更低了，也占用了更多的内存
ElementType FindKth(List L, int K) {
    List P = L;
    int i = 1;
    while ((i < K) &&
           (P != NULL)) {
        i++;
        P = P->Next;
    }
    if ((i == K) &&
        (P!= NULL)) {  // 这里无论如何都要注意一个问题P不能为NULL
                       // 也就是说上面一个循环还是有两个条件同时都不满足的时候！
        return P->Data;
    } else {
        return ERROR;
    }
}


ElementType FindKth(List L, int K) {
    List P = L;
    int i = 1;
    if ( i > K) {
        return ERROR;
    }
    while ((i < K) &&
           (P != NULL)) {
        i++;
        P = P->Next;
    }
    if (P) {
        return P->Data;
    } else {
        return ERROR;
    }
}

