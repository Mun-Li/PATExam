// 最小生成树_Kruskal
// 要求无向图连通，找到一颗树能够连接所有的顶点，
// 这颗树上的权值之和要是最小的，该树的结构不唯一，
// 但最小权值是唯一的。
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
  int u;  // 顶点编号
  int v;  // 顶点编号
  int w;  // 该边的权值
};

const int Inf = 0x3FFFFFFF;  // 自定义无穷大
const int MaxVet = 100000;   // 最多边数
int n{}, m{};                // 顶点，边数
Edge Graph[MaxVet];          // 无向图
int FatherSet[MaxVet]{};       // 被访问的顶点集合

// 构造无向图
void CreateGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    // 这里数组越界都不报错的吗？
    cin >> Graph[i].u >> Graph[i].v >> Graph[i].w;  // 起始顶点，终止顶点，边权
  }
}

// 给sort函数的比较排序的
bool CompareEdge(Edge e1, Edge e2) {
  return e1.w < e2.w;
}

int FindSet(int n) {
  int a = n;
  // 寻找父节点
  while (a != FatherSet[a]) {
    a = FatherSet[a];
  }
  // 压缩路径
  // 把经过的所有节点的父节点都换为根节点
  int b = n;
  while (b != FatherSet[b]) {
    int c = FatherSet[b];
    FatherSet[b] = a;
    b = c;
  }
  return a;
}

// Kruskal算法
// 如果无向图连通，则返回最小生成树的权值
// 如果无向图不连通，则返回-1
int KruskalTree(int s) {
  int SumTree{};                        // 最小生成树的权值之和
  int NumEdge{};                        // 最小生成树的边的个数
  sort(Graph, Graph + m, CompareEdge);  // 对边权进行排序
  for (int i = 0; i < n; ++i) {         // 初始化
    FatherSet[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    int Fu = FindSet(Graph[i].u);
    int Fv = FindSet(Graph[i].v);
    if (Fu != Fv) {      // 如果u和v不在同一个连通集合，所以可以加入到最小生成树中
      FatherSet[Fu] = Fv;  // 合并两个集合
      SumTree += Graph[i].w;
      ++NumEdge;
      if (NumEdge == n- 1) {  // 最小生成树只有n-1条边
        return SumTree;
      }
    }
  }
  return -1;  // 否则该无向图不连通，无最小生成树
}

int main() {
  CreateGraph();  // 创建无向图
  cout << KruskalTree(0);  // 搜索最小生成树的权值之和, 假设从原点0开始出发
  return 0;
}
