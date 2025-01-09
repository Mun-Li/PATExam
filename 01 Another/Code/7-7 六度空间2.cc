#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int m_INF = 0x3FFFFFFF;
const int N_max = 1003;
vector<int> graph[N_max]{};
int N_node{}, M_edge{};

double CaculatePer(int start) {
  int layer_node[N_max]{0};
  bool flag_node[N_max]{false};
  queue<int> bfs_queue;

  // BFS graph for caculating the layer of node
  fill(layer_node + 1, layer_node + N_node + 1, m_INF);
  bfs_queue.push(start);
  flag_node[start] = true;
  layer_node[start] = 0;
  while (!bfs_queue.empty()) {  // all the nodes are accessed, no best
    int temp_u = bfs_queue.front();
    bfs_queue.pop();
    for (int i = 0; i < graph[temp_u].size(); ++i) {
      int temp_v = graph[temp_u][i];
      if (!flag_node[temp_v]) {
        bfs_queue.push(temp_v);
        flag_node[temp_v] = true;
        layer_node[temp_v] = layer_node[temp_u] + 1;
      }
    }
  }

  // caculate the layer of start node less than 6
  double sum_less6{};
  for (int i = 1; i <= N_node; ++i) {
    if (layer_node[i] <= 6) {
      sum_less6 += 1;
    }
  }
  return sum_less6 / N_node;
}

int main() {
  // input example
  cin >> N_node >> M_edge;
  for (int i = 0; i < M_edge; ++i) {
    int temp_u{}, temp_v{};
    cin >> temp_u >> temp_v;
    graph[temp_u].push_back(temp_v);
    graph[temp_v].push_back(temp_u);  // undirected graph
  }

  // caculate
  for (int i = 1; i <= N_node; ++i) {
    printf("%d: %.2f%%\n", i, 100 * CaculatePer(i));
  }
  return 0;
}
