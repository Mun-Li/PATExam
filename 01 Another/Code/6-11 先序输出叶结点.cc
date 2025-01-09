//void PreorderPrintLeaves(BinTree BT) {
//  int temp_left_flag = 0, temp_right_flag = 0;
//  if (BT) {  // 如果还有结点
//    if (BT->Left) {
//      PreorderPrintLeaves(BT->Left);
//      temp_left_flag = 1;
//    }
//
//    if (BT->Right) {
//      PreorderPrintLeaves(BT->Right);
//      temp_right_flag = 1;
//    }
//
//    if (!(temp_left_flag || temp_right_flag)) {  // 都没有子结点了
//      printf(" %c", BT->Data);
//    }
//  }
//  return;
//}


// 又写的太冗余了。。。
// 看看别人写的多简洁？？
void PreorderPrintLeaves(BinTree BT) {
  if (BT == NULL) {
    return;
  }

  if (BT->Left == NULL && BT->Right == NULL) {
    printf(" %c", BT->Data);
  }

  PreorderPrintLeaves(BT->Left);
  PreorderPrintLeaves(BT->Right);
}
