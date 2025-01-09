// 最小生成树_Prime算法，类似与Dijkstra算法
// 要求无向图连通，找到一颗树能够连接所有的顶点，
// 这颗树上的权值之和要是最小的，该树的结构不唯一，
// 但最小权值是唯一的。
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
  int v;  // 下个顶点编号
  int w;  // 该边的权值
  // 构造函数
  Edge(int vv, int ww) : v(vv), w(ww) {}
};

const int Inf = 0x3FFFFFFF;  // 自定义无穷大
const int MaxVet = 100;      // 最多顶点数
int n{}, m{};                // 顶点，边数
vector<Edge> Graph[MaxVet];  // 无向图
bool flag[MaxVet]{};         // 顶点访问标志

// 构造无向图
void CreateGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w{};  // 起始顶点，终止顶点，边权
    cin >> u >> v >> w;
    Graph[u].push_back(Edge(v, w));
    Graph[v].push_back(Edge(u, w));  // 由于是无向图
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
  for (int aa = 0; aa < n-1; ++aa) {
    // 从未被访问的顶点中找到与s相连的最小的做为下一个顶点
    // 下一个顶点只有n-1个
    int jj{-1}, m{Inf};
    for (int i = 0; i < n; ++i) {
      if (flag[i]) {
        for (int j = 0; j < Graph[i].size(); ++j) {
          int v = Graph[i][j].v;
          int w = Graph[i][j].w;
          if (!flag[v] && w < m) {
            m = w;
            jj = v;
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
  CreateGraph();  // 创建无向图
  cout << PrimeTree(0);  // 搜索最小生成树的权值之和, 假设从原点0开始出发
  return 0;
}
