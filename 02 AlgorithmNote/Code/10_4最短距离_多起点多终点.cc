// 求解多源最短路径算法
// Floyd算法
#include <iostream>
#include <algorithm>
using namespace std;

// 采用矩阵的形式存储图
const int maxvet = 50;
const int myinf = 0x3fffffff;
int graph[maxvet][maxvet]{};
int dist[maxvet][maxvet]{};  // 每个点的最短距离更新

int main() {
  int n{}, m{};  // 顶点，边数
  cin >> n >> m;
  // 这里对于二维数组的指针需要加深理解
  fill(graph[0], graph[0] + maxvet * maxvet, myinf);  // graph[0] == &graph[0][0]
  fill(dist[0], dist[0] + maxvet * maxvet, myinf);
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w{};  // 起始顶点，终止顶点，权重
    cin >> u >> v >> w;
    graph[u][v] = w;  // 建立无向图, 邻接矩阵
    graph[v][u] = w;
    dist[u][v] = w;  // 建立无向图, 邻接矩阵
    dist[v][u] = w;
  }

  // 三重循环，Floyd算法
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (graph[i][k] != myinf && graph[k][j] != myinf) {
          // i->k->j可以连通
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            // 更新i->j的距离
            dist[i][j] = dist[i][k] + dist[k][j];  // 需不需要dist[j][i]
          }
        }
      }
    }
  }

  // 整理并输出
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        dist[i][j] = 0;
      }
      if (dist[i][j] == myinf) {  // 无法到达
        dist[i][j] = -1;
      }
      if (j != 0) {
        cout << ' ';
      }
      cout << dist[i][j];
    }
    cout << endl;
  }



  return 0;
}









