// 2.7 指针
// 交换指针变量
// 
// ========================
#include<iostream>
using namespace std;

static void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a, b;
  cin >> a >> b;
  swap(&a, &b);
  cout << a << ' ' << b;
  return 0;
}
