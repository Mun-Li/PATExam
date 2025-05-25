#include<iostream>
#include<vector>
using namespace std;

const int MAX_NV = 1001;  // 最多的图顶点
const int MAX_K = 100;    // 最多测试点
const int MAX_DIST = 0x7FFFFFFF;

struct Node {
  int v;
  int w;
  Node(int _v, int _w) : v(_v), w(_w){};
};
vector<Node> G[MAX_NV];       // 图
vector<int> list_seq[MAX_K];  // 测试路径
int Nv = 0, Ne = 0;           // 图的顶点和边数量

bool IsDijkstraSequence(int i) {
  int start = list_seq[i][0];
  int dist[MAX_NV] = {0};       // 当前最短距离
  bool vist[MAX_NV] = {false};  // 访问标志

  fill(dist + 1, dist + Nv + 1, MAX_DIST);  // 置所有点距离start点为最大距离
  dist[start] = 0;

  // 找到所有点距离start点的最短距离
  // 即遍历完图的所有顶点
  int list_u = 0;
  for (int j = 0; j < Nv; ++j) {
    list_u = list_seq[i][j];

    int u = -1;
    int max_dist = MAX_DIST;
    // step1：找到距离start点目前最近且未被访问过的一个点
    for (int i = 1; i <= Nv; ++i) {
      if (dist[i] < max_dist && !vist[i]) {
        u = i;
        max_dist = dist[i];
      }
    }
    if (dist[list_u] != max_dist) {
      return false;
    }

    if (u == -1) {  // 图的所有顶点已经访问完了，或者此时没有连接点
      continue;
    }
    vist[u] = true;  // 标记被访问了

    for (int k = 0; k < G[u].size(); ++k) {
      int v = G[u][k].v;
      int w = G[u][k].w;
      if (dist[u] + w <= dist[v] && !vist[v]) {
        dist[v] = dist[u] + w;  // 更新最短距离
      }
    }
  }
  return true;
}

int main() {

  // 输入图
  scanf_s("%d %d", &Nv, &Ne);
  for (int i = 0; i < Ne; ++i) {
    int temp_u = 0, temp_v = 0, temp_w = 0;
    scanf_s("%d %d %d", &temp_u, &temp_v, &temp_w);
    G[temp_u].push_back(Node(temp_v, temp_w));  // 假设为无向图
    G[temp_v].push_back(Node(temp_u, temp_w));
  }

  // 输入测试案例
  int example = 0;
  scanf_s("%d", &example);
  for (int i = 0; i < example; ++i) {
    int temp;
    for (int j = 0; j < Nv; ++j) {  // 全部顶点
      scanf_s("%d", &temp);
      list_seq[i].push_back(temp);
    }
  }
  
  // 开始判断是否是dijkstra sequence
  for (int i = 0; i < example; ++i) {
    if (IsDijkstraSequence(i)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
