// 这个问题可以抽像为最短路径问题 Dijksta?
// 大哥，直接用广度搜索算法就OKFOK
// 无向连通图，任意结点开始即可
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> Graph[100];  // 存储图
queue<int> q;            // 队列，存储顶点
int n{}, m{}, s{};       // 图的顶点数，边数，起始顶点编号
bool flag[100]{false};   // 顶点访问标志
int dist[100]{};         // 距起始顶点的距离
int distan{};          // 当前层数

// 创建图，无向图
void Create() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    int u{}, v{};  // 两个端点的编号
    cin >> u >> v;
    Graph[u].push_back(v);
    Graph[v].push_back(u);
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

int main()
{
  // 创建无向图
  Create();
  // 从s点开始
  BFS(s);

  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      cout << dist[i];
    } else {
      cout << ' ' << dist[i];
    }
  }
  return 0;
}
