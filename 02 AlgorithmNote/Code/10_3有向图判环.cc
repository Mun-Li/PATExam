#include<iostream>
#include<vector>
using namespace std;

vector<int> Graph[100];
int State[100]{0};  // 顶点有三个状态 { 0 1 2 }
bool flag{false};

// 深度优先遍历
void DFS(int Nv) {
  if (State[Nv] == 1) {  // 有环
    flag = true;
    return;  // 判断有环直接返回，不能在访问这个顶点了。
  }
  State[Nv] = 1;  // 正在访问该顶点
  for (int i = 0; i < Graph[Nv].size(); i++) {
    if (State[Graph[Nv][i]] != 2) {  // 访问没有被访问完的顶点
      DFS(Graph[Nv][i]);
    }
  }
  State[Nv] = 2;  // 该顶点访问完毕
}

void VistGraph(int n) {
  for (int i = 0; i < n; i++) {
    if (State[i] != 2) {  // 访问没有被访问完的顶点
      DFS(i);
    }
  }
}

int main() {
  int n{}, m{};

  // 输入图的顶点和边的数量
  cin >> n >> m;

  // 建立有向图
  for (int i = 0; i < m; ++i) {
    int temp1{}, temp2{};
    cin >> temp1 >> temp2;
    Graph[temp1].push_back(temp2);
  }
  VistGraph(n);  // 深度遍历图Graph
  if (flag) {    // 有向图中有循环图，否则无
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
} 
