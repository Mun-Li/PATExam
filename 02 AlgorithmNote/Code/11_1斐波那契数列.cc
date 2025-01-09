#include<iostream>
using namespace std;

const int MaxF = 10002;
int Farray[MaxF] = {0};

int Fibonacci(int n) {  // 递归太多了容易栈溢出，所以需要利用循环来做
  if (n == 1 || n == 2) {
    return 1;
  } else if (n >= 3) {
    if (!Farray[n]) {
      Farray[n] = (Fibonacci(n - 1) + Fibonacci(n - 2)) % 10007;
    }
    return Farray[n];
  }
}

int main() {
  int n{};
  cin >> n;
  cout << Fibonacci(n);
  return 0;
}
