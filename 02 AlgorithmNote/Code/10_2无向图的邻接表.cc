#include<iostream>
#include<vector>
using namespace std;

const int maxg = 100;
vector<int> Graph[maxg];

int main() {
  int n{}, m{};
  cin >> n >> m;

  // 输入边的情况
  for (int i = 0; i < m; i++) {
    int v1{}, v2{};
    cin >> v1 >> v2;
    Graph[v1].push_back(v2);
    Graph[v2].push_back(v1);
  }

  // 输出边的情况
  for (int i = 0; i < n; i++) {
    cout << i << '(' << Graph[i].size() << ')';
    for (int j = 0; j < Graph[i].size(); j++) {
      cout << ' ' << Graph[i][j];
    }
    cout << endl;
  }

  return 0;
}