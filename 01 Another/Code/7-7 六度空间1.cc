#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int Max_N = 1002;
const int MY_INF = 0x7FFFFFFF;

struct Node {
  int v;
  int w;
  Node(int _v, int _w) : v(_v), w(_w){};
};  // 顶点方式

int N{}, M{};
vector<Node> Graph[Max_N]{};
int dist[Max_N]{};
bool flag[Max_N]{};
double sum_num{};

void Dijkstra(int start) {
  dist[start] = 0;  // 起始顶点的距离为0

  // 每个顶点都要被访问到
  for (int i = 1; i <= N; ++i) {
    // step1：找到最短距离，但未被访问的
    int u = -1, max_value = MY_INF;
    for (int j = 1; j <= N; ++j) {
      if (dist[j] < max_value && !flag[j]) {
        u = j;
        max_value = dist[j];
      }
    }
    if (u == -1) {  // 其余顶点都不连通
      return;
    }

    // step2：从该顶点开始更新最短距离
    for (int j = 0; j < Graph[u].size(); ++j) {
      if (dist[u] + Graph[u][j].w < dist[Graph[u][j].v]) {  // 更新最短权重
        dist[Graph[u][j].v] = Graph[u][j].w + dist[u];
      }
    }
    flag[u] = true;
  }
}

int main() {
  // 输入每个结点之间的关系，矩阵图表示
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u{}, v{};
    cin >> u >> v;
    Graph[u].push_back(Node(v, 1));
    Graph[v].push_back(Node(u, 1));
  }

  for (int i = 1; i <= N; ++i) {
    // step1: 其余顶点的距离先假设都为无穷大
    fill(dist + 1, dist + 1 + N, MY_INF);
    fill(flag + 1, flag + 1 + N, false);
    sum_num = 0;

    // step2: 计算从每一个顶点出发到图中其余顶点的最短距离
    Dijkstra(i);

    // step3：统计之间的距离小于6的数量
    for (int j = 1; j <= N; ++j) {
      if (dist[j] <= 6) {
        ++sum_num;
      }
    }
    cout << i << ": ";
    printf("%.2f", (sum_num / N) * 100);
    cout << '%' << endl;
  }

  return 0;
}
