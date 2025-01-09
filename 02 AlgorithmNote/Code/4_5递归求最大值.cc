// 序列求最大值
// 递归实现 
// 
// ===================================
#include<iostream>
using namespace std;

const int maxn = 100;
int n = 0;
int array_n[maxn+1] = {0};

static int FindMax(int idx_n) {
  if (idx_n == 1) {
    return array_n[idx_n];
  } else {
    int temp = FindMax(idx_n - 1);
    return array_n[idx_n] > temp ? array_n[idx_n] : temp;
  }
}

int main () {
  // step1: 输入n个正整数
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> array_n[i];
  }
  cout << FindMax(n);

  return 0;
}
