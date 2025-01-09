BinTree Insert(BinTree BST, ElementType X) {
  // 二叉搜索树的插入操作
  if (BST == NULL) {
    BST = (BinTree)malloc(sizeof(struct TNode));
    BST->Data = X;
    // 注意一定要把左右子树赋为NULL
    BST->Left = NULL;
    BST->Right = NULL;
  }
  if (BST->Data < X) {  // 插入到右子树中
    BST->Right = Insert(BST->Right, X);
  } else if (BST->Data > X) {  // 插入到左子树中
    BST->Left = Insert(BST->Left, X);
  }
  return BST;
}

BinTree Delete(BinTree BST, ElementType X) {
  // 二叉搜索树的删除操作
  BinTree temp;
  if (BST == NULL) {
    printf("Not Found\n");
  } else {
    if (BST->Data < X) {
      BST->Right = Delete(BST->Right, X);
    } else if (BST->Data > X) {
      BST->Left = Delete(BST->Left, X);
    } else {  // 找到需要删除的结点
      if (BST->Left && BST->Right) {
        temp = FindMax(BST->Left);
        BST->Data = temp->Data;
        BST->Left = Delete(BST->Left, BST->Data);
      } else {
        temp = BST;
        if (BST->Left == NULL) {
          BST = BST->Right;
        } else {
          BST = BST->Left;
        }
        free(temp);
      }
    }
  }
  return BST;
}

Position Find(BinTree BST, ElementType X) {
  // 二叉搜索树的查找
  if (BST == NULL) {
    return NULL;
  } else {
    if (BST->Data < X) {
      return Find(BST->Right, X);
    } else if (BST->Data > X) {
      return Find(BST->Left, X);
    } else {  // 找到了
      return BST;
    }
  }
}

Position FindMin(BinTree BST) {
  // 二叉搜索树查找最小元素
  // 注意需要考虑空树的情况
  if (BST == NULL) {
    return NULL;
  }
  if (BST->Left == NULL) {
    return BST;
  } else {
    return FindMin(BST->Left);
  }
}

Position FindMax(BinTree BST) {
  // 查找二叉搜索树的最大元素
  // 注意需要考虑空树的情况
  if (BST == NULL) {
    return NULL;
  }
  if (BST->Right == NULL) {
    return BST;
  } else {
    return FindMax(BST->Right);
  }
}
