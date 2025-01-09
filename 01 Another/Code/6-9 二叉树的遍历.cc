void InorderTraversal(BinTree BT) {  // 中序遍历
  if (!BT) {
    return;
  }
  InorderTraversal(BT->Left);
  printf(" %c", BT->Data);
  InorderTraversal(BT->Right);
}

void PreorderTraversal(BinTree BT) {  // 先序遍历
  if (!BT) {
    return;
  }
  printf(" %c", BT->Data);
  PreorderTraversal(BT->Left);
  PreorderTraversal(BT->Right);
}

void PostorderTraversal(BinTree BT) {  // 后序遍历
  if (!BT) {
    return;
  }
  PostorderTraversal(BT->Left);
  PostorderTraversal(BT->Right);
  printf(" %c", BT->Data);
}

void LevelorderTraversal(BinTree BT) {
  int front = 0, rear = 0;
  BinTree queue[100];
  if (!BT) {
    return;
  }
  queue[rear++] = BT;

  while (front != rear) {
    BT = queue[front++];
    printf(" %c", BT->Data);
    if (BT->Left) {
      queue[rear++] = BT->Left;
    }
    if (BT->Right) {
      queue[rear++] = BT->Right;
    }
  }
}
