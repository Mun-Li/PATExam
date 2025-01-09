// Dijkstra算法
// 局限性：1.只能针对单源的最小路径； 2. 图的权值只能为正数
#include <iostream>
#include <vector>
using namespace std;

const int Maxv = 100;        // 最大顶点数
const int inf = 0x3FFFFFFF;  // 定义一个无穷大
struct Node {
  int next;                                                     // 下一个顶点号
  int w1;                                                       // 距离权值
  int w2;                                                       // 花费权值
  Node(int v, int ww1, int ww2) : next(v), w1(ww1), w2(ww2) {}  // 构造函数，用来初始化
};
vector<Node> Graph[Maxv];  // 无向图，邻接表表示
int n{}, m{}, s{}, t{};    // 顶点数，边数，起始顶点编号，终点
bool flag[Maxv]{false};    // 顶点访问标志
int MinDist[Maxv]{};       // 当前的起始顶点到各个顶点的最短距离
int MinCost[Maxv]{};       // 当前的起始顶点到各个顶点的最少花费

// 创建无向图
void create() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w1{}, w2{};
    cin >> u >> v >> w1 >> w2;  // 输入顶点，边及权值
    Graph[u].push_back(Node(v, w1, w2));
    Graph[v].push_back(Node(u, w1, w2));  // 由于是无向图
  }
}

// 最短路径的搜索算法
void DijkstraDistCost(int start) {
  fill(MinDist, MinDist + n, 0x3FFFFFFF);  // 初始化距离
  fill(MinCost, MinCost + n, 0x3FFFFFFF);  // 初始化花费
  MinDist[start] = 0;                      // 起始顶点到自身的距离设为0
  MinCost[start] = 0;                      // 起始顶点到自身的花费设为0
  for (int i = 0; i < n; ++i) {
    int u = -1, mind = inf;
    // 找到距离最短的未访问顶点
    for (int j = 0; j < n; ++j) {
      if (MinDist[j] < mind && flag[j] == false) {
        mind = MinDist[j];
        u = j;  // 距离最短的未访问顶点编号
      }
    }
    if (u == -1) {
      return;  // 顶点都没有连接直接返回
    }
    flag[u] = true;  // 标志此顶点已访问

    // 从u顶点开始出发访问
    for (int j = 0; j < Graph[u].size(); ++j) {
      int v = Graph[u][j].next;  // 可以访问的顶点编号
      int w1 = Graph[u][j].w1;   // u-->v的距离权值
      int w2 = Graph[u][j].w2;   // u-->v的花费权值
      if (MinDist[u] + w1 <= MinDist[v]) {
        if (MinDist[u] + w1 == MinDist[v]) {  // 对于花费权值，如果距离相等取最小
          if (MinCost[u] + w2 < MinCost[v]) {
            MinCost[v] = MinCost[u] + w2;
          }
        } else {
          MinCost[v] = MinCost[u] + w2;
        }
        MinDist[v] = MinDist[u] + w1;  // 更新最短距离
      }
    }
  }
}


int main() {
  create();             // 创建无向图
  DijkstraDistCost(s);  // 从s开始搜索到各个顶点的最短路径
  cout << MinDist[t] << ' ' << MinCost[t];
  return 0;
}
