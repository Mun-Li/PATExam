// 基本思路：由于图的所有边权之和为一定值，
// 为了保证删掉的最大边权和之后的连通性
// 也就是保留的为最小生成树，
// 即求出最小生成树之后，便可以得到最大删边权之和

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int Max_N = 100;
struct Node {
  int v;  // 下一个节点
  int w;  // 权值
  Node(int x, int y) : v(x), w(y) {}
};
vector<Node> Graph[Max_N];
int n{}, m{};
bool flag[Max_N]{false};

// 最小生成树
int PrimeMinSpanTree(int start_i) {
  int dist[Max_N]{};
  int sum_min_tree{};
  fill(dist, dist + n, 0x7FFFFFFF);
  dist[start_i] = 0;  // 从顶点i开始访问

  // 所有点都要访问到
  for (int i = 0; i < n; ++i) {
    // 先找到最近的那个点
    int u = -1, min_u = 0x7FFFFFFF;
    for (int j = 0; j < n; ++j) {
      if (dist[j] < min_u && !flag[j]) {
        u = j;
        min_u = dist[j];
      }
    }
    if (u == -1) {  // 此时图是不连通的
      return -1;
    }
    // 从u开始访问，如果对应边的顶点不在
    flag[u] = true;
    sum_min_tree += min_u;
    for (int j = 0; j < Graph[u].size(); ++j) {
      int v = Graph[u][j].v;
      if (Graph[u][j].w < dist[v] && !flag[v]) {
        dist[v] = Graph[u][j].w;
      }
    }
  }
  return sum_min_tree;
}

int main() {
  int sum_w{}, min_sum_w{};

  fill(flag, flag + Max_N, 0);  // 顶点未访问的标志

  // 先输入这个无向图
  // 邻接矩阵的形式
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int t1{}, t2{}, w{};
    cin >> t1 >> t2 >> w;
    Graph[t1].push_back(Node(t2, w));
    Graph[t2].push_back(Node(t1, w));
    sum_w += w;  // 计算所有边权之和
  }

  min_sum_w = PrimeMinSpanTree(0);
  if (min_sum_w == -1) {  // 无向图不连通
    cout << -1;
  } else {  // 输出最大的可删边权
    cout << sum_w - min_sum_w;
  }

  return 0;
}
