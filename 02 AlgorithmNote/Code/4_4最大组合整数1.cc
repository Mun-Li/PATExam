// 4_4 最大组合整数 25min
// https://sunnywhy.com/sfbj/4/4
//
// ==========================
#include<iostream>
using namespace std;

const int maxn = 10;

int a[maxn] = {0};


int main () {
  for (int i = 0; i < maxn; ++i) {
    cin >> a[i];
  }
  bool isZero = true;
  for(int idx_a = 9; idx_a > 0;) {
    if(a[idx_a]) {
      cout << idx_a;
      a[idx_a]--;
      isZero = false;
    } else {
      idx_a--;
    }
  }
  if(isZero) {
    cout << '0';
  } else {
    while(a[0]) {
      cout << '0';
      a[0]--;
    }
  }

  return 0;
}