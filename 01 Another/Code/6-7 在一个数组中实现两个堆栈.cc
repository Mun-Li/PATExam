Stack CreateStack(int MaxSize) {
  // 深刻的体会了动态数组的建立
  Stack newstack = (Stack)malloc(sizeof(struct SNode));
  newstack->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  newstack->Top1 = -1;
  newstack->Top2 = MaxSize;
  newstack->MaxSize = MaxSize;
  return newstack;
}
// 入栈操作
bool Push(Stack S, ElementType X, int Tag) {
  // 判断栈空间是否已满？
  if (S->Top1 == S->Top2 - 1) {  // 栈空间已满
    printf("Stack Full\n");
    return false;
  }
  if (Tag == 1) {
    S->Data[S->Top1 + 1] = X;
    ++S->Top1;
  } else if (Tag == 2) {
    S->Data[S->Top2 - 1] = X;
    --S->Top2;
  }
  return true;
}
// 弹出操作
ElementType Pop(Stack S, int Tag) {
  // 先判断堆栈是否为空
  if (Tag == 1) {
    if (S->Top1 > -1) {
      --S->Top1;
      return S->Data[S->Top1 + 1];
    } else {
      printf("Stack %d Empty\n", Tag);
      return ERROR;
    }
  } else if (Tag == 2) {
    if (S->Top2 < S->MaxSize) {
      ++S->Top2;
      return S->Data[S->Top2 - 1];
    } else {
      printf("Stack %d Empty\n", Tag);
      return ERROR;
    }
  }
}