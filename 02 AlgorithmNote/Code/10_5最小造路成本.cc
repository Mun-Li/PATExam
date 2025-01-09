// 最小生成树_Prime算法，类似与Dijkstra算法
// 要求无向图连通，找到一颗树能够连接所有的顶点，
// 这颗树上的权值之和要是最小的，该树的结构不唯一，
// 但最小权值是唯一的。
#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 0x3FFFFFFF;  // 自定义无穷大
const int MaxVet = 100;      // 最多顶点数
int n{};                     // 顶点
int Graph[MaxVet][MaxVet];   // 无向图
bool flag[MaxVet]{};         // 顶点访问标志

// 构造无向图
void CreateGraph() {
  fill(Graph[0], Graph[0] + n * n, Inf);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int w{};
      cin >> w;
      Graph[i][j] = w;
    }
  }
}

// Prime算法
// 如果无向图连通，则返回最小生成树的权值
// 如果无向图不连通，则返回-1
int PrimeTree(int s) {
  int SumTree{};  // 最小生成树的权值之和

  // 初始化标志位和距离
  fill(flag, flag + n, false);
  flag[s] = true;

  // Prime 核心算法
  for (int aa = 0; aa < n - 1; ++aa) {  // 只需找到n-1条边
    // 从未被访问的顶点中找到与s相连的最小的做为下一个顶点
    int jj{-1}, m{Inf};
    for (int i = 0; i < n; ++i) {
      if (flag[i]) {
        for (int j = 0; j < n; ++j) {
          int w = Graph[i][j];
          if (!flag[j] && w && w < m) {  // w需要不等于0
            m = w;
            jj = j;
          }
        }
      }
    }
    // 如果存在未连通的点，直接就返回-1
    if (jj == -1) {
      return -1;
    }
    flag[jj] = true;  // 否则，标记该顶点已被访问
    SumTree += m;
  }

  return SumTree;
}

int main() {
  CreateGraph();         // 创建无向图
  cout << PrimeTree(0);  // 搜索最小生成树的权值之和, 假设从原点0开始出发
  return 0;
}
