#include <iostream>
using namespace std;

int main() {
  int n{}, m{}, flag{};
  int grap[100][100]{};  // 使用邻接矩阵的存储形式
  // n个顶点，m条边
  cin >> n >> m;
  // 输入图的连接方式
  for (int i = 0; i < m; i++) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    grap[temp1][temp2] = 1;
    grap[temp2][temp1] = 1;
  }

  for (int i = 0; i < n; i++) {
    flag = 0;
    for (int j = 0; j < n; j++) {
      if (flag) {
        cout << ' ';
      }
      flag = 1;
      cout << grap[i][j];
    }
    cout << endl;
  }
  return 0;
}