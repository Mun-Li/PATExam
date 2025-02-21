// 4_4 最大组合整数 25min
// https://sunnywhy.com/sfbj/4/4
//
// ==========================
#include<iostream>
#include<string>
using namespace std;

int a[10] = {0};
string ans = "";  // 也可以直接输出，而不用字符串

int main() {
  for(int i = 0; i < 10; ++i) {
    cin >> a[i];
  }
  for (int idx_a = 9; idx_a > 0;) {
    if(a[idx_a] != 0) {
      ans += ('0' + idx_a);
      a[idx_a]--;
    } else {  //
      idx_a--;
    }
  }
  if(ans == "") {
    cout << '0';
  } else {
    while(a[0]) {
      ans += "0";
      a[0]--;
    }
    cout << ans;
  }
  return 0;
}
