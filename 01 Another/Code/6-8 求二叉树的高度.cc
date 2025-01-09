//int GetHeight(BinTree BT) {
//  int height_left = 0, height_right = 0;
//  if (BT) {
//    if (BT->Left) {
//      height_left = GetHeight(BT->Left) + 1;
//    } else {
//      height_left = 1;  // height is one
//    }
//
//    if (BT->Right) {
//      height_right = GetHeight(BT->Right) + 1;
//    } else {
//      height_right = 1;  // height is one
//    }
//    return (height_left > height_right) ? height_left : height_right;
//  } else {
//    return 0;
//  }
//}


// 上面的代码太复杂了，太冗余了
int GetHeight(BinTree BT) {
  int height_left = 0, height_right = 0;
  if (BT) {
    height_left = GetHeight(BT->Left) + 1;
    height_right = GetHeight(BT->Right) + 1;
    return (height_left > height_right) ? height_left : height_right;
  } else {
    return 0;
  }
}
