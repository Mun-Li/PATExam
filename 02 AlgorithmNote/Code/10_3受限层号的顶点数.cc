#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> Graph[100];  // 存储图
queue<int> q;            // 队列，存储顶点
int n{}, m{}, s{}, k{};  // 图的顶点数，边数，起始顶点编号，受限的层数
bool flag[100]{false};   // 顶点访问标志
int dist[100]{};         // 距起始顶点的距离
int distan{};            // 当前层数
int cntk{};              // 层数不超过k的个数

// 创建图，有向图
void Create() {
  cin >> n >> m >> s >> k;
  for (int i = 0; i < m; ++i) {
    int u{}, v{};  // 两个端点的编号
    cin >> u >> v;
    Graph[u].push_back(v);
  }
}

// 广度搜索算法
void BFS(int sv) {
  q.push(sv);
  flag[sv] = true;
  while (!q.empty()) {
    int cnt = q.size();  // 该层的个数
    for (int j = 0; j < cnt; ++j) {
      int tv = q.front();  // 取队列的首个
      q.pop();
      dist[tv] = distan;
      for (int i = 0; i < Graph[tv].size(); ++i) {
        if (flag[Graph[tv][i]] == false) {  // 未入队的才能入队
          q.push(Graph[tv][i]);
          flag[Graph[tv][i]] = true;  // 入队标志
        }
      }
    }
    ++distan;  // 该层结束，层数加一
  }
}

int main() {
  // 创建有向图
  Create();
  // 从s点开始
  BFS(s);

  for (int i = 0; i < n; ++i) {
    if (dist[i] <= k && flag[i] == true) {  // 这里需要注意有向图从该顶点开始时，不一定连通
      ++cntk;
    }
  }
  cout << cntk;
  return 0;
}
