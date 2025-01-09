// Dijkstra算法
// 局限性：1.只能针对单源的最小路径； 2. 图的权值只能为正数
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
  int next;                                   // 下一个顶点号
  int weight;                                 // 两个顶点之间的权值
  Node(int v, int w) : next(v), weight(w) {}  // 构造函数，用来初始化
};
struct ImportantCity {
  int CityNum;
  int CitySum;
};

const int Maxv = 100;        // 最大顶点数
const int inf = 0x3FFFFFFF;  // 定义一个无穷大
vector<Node> Graph[Maxv];    // 无向图，邻接表表示
int n{}, m{}, k{};           // 顶点数，边数，起始顶点编号，终点编号
bool flag[Maxv]{false};      // 顶点访问标志
int MinDist[Maxv]{};         // 当前的起始顶点到各个顶点的最短距离
int Start[Maxv]{};           // 备选的城市号
ImportantCity City[Maxv];    // 备选城市的信息

// 创建无向图
void create() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w{};
    cin >> u >> v >> w;  // 输入顶点，边及权值
    Graph[u].push_back(Node(v, w));
    Graph[v].push_back(Node(u, w));  // 由于是无向图
  }
  for (int i = 0; i < k; ++i) {
    cin >> Start[i];  // 输入备选城市号
  }
}

// 最短路径的搜索算法
void Dijkstra(int start) {
  // 初始化距离
  fill(MinDist, MinDist + n, 0x3FFFFFFF);
  fill(flag, flag + n, false);
  MinDist[start] = 0;  // 起始顶点到自身的距离设为0
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
      int v = Graph[u][j].next;    // 可以访问的顶点编号
      int w = Graph[u][j].weight;  // u-->v的权值
      if (flag[v] == false && MinDist[u] + w < MinDist[v]) {
        MinDist[v] = MinDist[u] + w;  // 更新最短距离
      }
    }
  }
}

// 城市之间的比较
bool CityCompare(ImportantCity C1, ImportantCity C2) {
  if (C1.CitySum != C2.CitySum) {
    return C1.CitySum < C2.CitySum;
  } else {
    return C1.CityNum < C2.CityNum;
  }
}

//int main() {
//  create();     // 创建无向图
//  for (int i = 0; i < k; ++i) {
//    int sum = 0;
//    Dijkstra(Start[i]);  // 找到此城市到所有城市之间的最短路径
//    for (int j = 0; j < n; ++j) {
//      sum += MinDist[j];
//    }
//    City[i].CityNum = Start[i];
//    City[i].CitySum = sum;
//  }
//  sort(City, City + k, &CityCompare);
//  // 输出交通枢纽城市
//  cout << City[0].CityNum << ' ' << City[0].CitySum;
//  return 0;
//}

// 比较算法的另一种写法
int main() {
  create();                      // 创建无向图
  int CitySum = inf, CityNum{};  // 这是对比的值
  for (int i = 0; i < k; ++i) {
    int sum = 0;
    Dijkstra(Start[i]);  // 找到此城市到所有城市之间的最短路径
    for (int j = 0; j < n; ++j) {
      sum += MinDist[j];
    }
    if (sum < CitySum) {
      CitySum = sum;
      CityNum = Start[i];
    } else if (sum == CitySum) {
      if (Start[i] < CityNum) {
        CityNum = Start[i];
      }
    }
  }
  // 输出交通枢纽城市
  cout << CityNum << ' ' << CitySum;
  return 0;
 }