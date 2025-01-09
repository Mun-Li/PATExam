// 递归打印n的全排列
//
// ========================
#include<iostream>
using namespace std;

const int n = 4;  // n的全排列
const int maxn = 20;

int Permutation[maxn] = {0};
bool FlagX[n+1] = {false};

static void PrintPermutation(int idx) {
  if (idx == n + 1) {  // 此时开头的全排列已经整理完了
    for(int i = 1; i <= n; ++i){
      printf("%d", Permutation[i]);
    }
    printf("\n");
  }else{
    for(int x = 1; x <= n; ++x){
      if (!FlagX[x]) {  // x还未在全排列中
        FlagX[x] = true;
        PrintPermutation(idx+1);
        FlagX[x] = false;
      }
    }
  }
}


int main() {
  fill(FlagX, FlagX+n+1, false);
  PrintPermutation(1);  // 从Permutation[1]开始
  return 0;
}
