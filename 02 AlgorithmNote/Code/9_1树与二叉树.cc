#include<iostream>
using namespace std;


int main() {
  int n{}, m{};
  cin >> n >> m;  // 输入顶点数和边数，判断是否为一颗树

  if (m == n - 1) {  // 树中的一些关系式确实要复习复习了
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
