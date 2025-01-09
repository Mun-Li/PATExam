#include<iostream>
#include<queue>
using namespace std;

const int MaxVet = 100;       // 最大的顶点数
int n{}, m{};  // 顶点数，边数
int Graph[MaxVet][MaxVet]{};  // 无向图
int NumInputV[MaxVet]{};  // 每个顶点的入度
int Flag{};  // 已输出顶点的数量
priority_queue<int, vector<int>, greater<int>>Input0;  // 入度为0的优先队列，小的顶点排在前面

void CreatGraph() {
  int u{}, v{};  // 顶点编号
  cin >> n >> m;  // 图的顶点数，边数
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    ++NumInputV[v];  // 入度加一
    Graph[u][v] = 1;
  }
}

int main() {
  CreatGraph();  // 创造有向图，并统计每个顶点的入度信息
  for (int i = 0; i < n; ++i) {
    if (!NumInputV[i]) {  // 入度为0的顶点进入优先队列
      Input0.push(i);
    }
  }

  while (!Input0.empty()) {  // 只要优先队列不为空
    int u = Input0.top();
    Input0.pop();
    if (Flag) {  // 如果不是第一个顶点号，前面都输出空格
      cout << ' ';
    }
    cout << u;
    ++Flag;
    for (int i = 0; i < n; ++i) {
      if (Graph[u][i]) {
        --NumInputV[i];
        if (!NumInputV[i]) {
          Input0.push(i);
        }
      }
    
    }
  }
  if (Flag < n) {
    cout << "不是有向无环图";
  }
  return 0;
}
