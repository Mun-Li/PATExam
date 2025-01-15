// 2.7 指针
// 引用
// 
// ========================
#include<iostream>
using namespace std;

static void increase(int &x){
  x += 1;
}

int main() {
  int n;
  cin >> n;
  increase(n);
  cout << n;
  return 0;
}
