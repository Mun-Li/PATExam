#include <iostream>
#include <vector>
using namespace std;

const int max_n = 100;  // 最大顶点数
vector<int> Vgraph[max_n];
int n{}, m{};       // 顶点数和边数
bool vis[max_n]{};  // 顶点访问标记

// 建图
void BuildGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    Vgraph[temp1].push_back(temp2);
    Vgraph[temp2].push_back(temp1);
  }
}

// 深度优先搜索
void DFS(int n) {
  vis[n] = true;
  for (int i = 0; i < Vgraph[n].size(); ++i) {
    if (vis[Vgraph[n][i]] == false) {
      DFS(Vgraph[n][i]);
    }
  }
}

// 计算连通图的数量
void CountSubGraph() {
  int num{};
  for (int i = 0; i < n; ++i) {
    if (vis[i] == false) {
      ++num;  // 记录连通图的数量
      DFS(i);
    }
  }
  if (num == 1) {  // 只有一个连通块，即整个图连通
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  // 根据输入建立图
  BuildGraph();
  // 利用深度优先搜索算法来判断是否为连通图
  CountSubGraph();
  return 0;
}