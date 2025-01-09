// 关键路径长度
#include<iostream>
#include<queue>
using namespace std;

const int MaxVertex = 100;
const int INF = 0x3FFFFFFF;
int n{}, m{};
int Graph[MaxVertex][MaxVertex]{};
int InputDegreeNumber[MaxVertex]{};
int NumberVertex{};
queue<int> InputDegreeNumber0;

void CreatGraph() {
  int u{}, v{}, w {};
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    Graph[u][v] = w;
    ++InputDegreeNumber[v];
  }
}




int main() {
  // 创建有向图
  CreatGraph();

  // 进行拓扑排序
  for (int i = 0; i < n; ++i) {
    if (!InputDegreeNumber[i]) {
      InputDegreeNumber0.push(i);  // 将入度为0的顶点入度
    }
  }
  while (!InputDegreeNumber0.empty()) {
    int u = InputDegreeNumber0.front();
    InputDegreeNumber0.pop();
    for (int i = 0; i < n; ++i) {
      if (Graph[u][i]) {
        --InputDegreeNumber[i];
        if (!InputDegreeNumber[i]) {
          InputDegreeNumber0.push(i);
        }
      }
    }
    ++NumberVertex;
  }
  if (NumberVertex < n) {
    cout << "No";
    return 0;
  }
  cout << "Yes";



  return 0;
}
