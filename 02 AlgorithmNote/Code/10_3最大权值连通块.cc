#include<iostream>
#include<vector>
using namespace std;

int Weight[100]{0};        // 顶点的权值
int MaxWeightSubGraph{};   // 记录连通块的最大权值
int WeightSubGraph{};      // 临时的权值记录变量
int Vist[100]{0};          // 顶点访问记录
vector<int> Graph[100]{};  // 图

void DFS(int Nv) {
  Vist[Nv] = 1;
  WeightSubGraph += Weight[Nv];  // 记录连通图的权值
  for (int i = 0; i < Graph[Nv].size(); ++i) {
    int temp = Graph[Nv][i];
    if (Vist[temp] == 0) {
      DFS(temp);
    }
  }
}

void VistGraph(int n) { 
  for (int i = 0; i < n; ++i) {
    if (Vist[i] == 0) {
      DFS(i);  // 这里就是一个连通图
      if (WeightSubGraph > MaxWeightSubGraph) {
        // 更新连通图的最大权值
        MaxWeightSubGraph = WeightSubGraph;
      }
      WeightSubGraph = 0;  // 这里需要重置一下权值的记录
    }
  }
}

int main() {
  int n{}, m{};
  cin >> n >> m;                 // 图的顶点数和边数
  for (int i = 0; i < n; ++i) {  // 输入对应顶点的权值
    cin >> Weight[i];
  }
  for (int i = 0; i < m; ++i) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    Graph[temp1].push_back(temp2);  // 无向图
    Graph[temp2].push_back(temp1);
  }
  // 访问连通图
  VistGraph(n);
  // 输出最大连通图的权值
  cout << MaxWeightSubGraph << endl;
  return 0;
}