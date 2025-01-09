// 最短路径——多边权2，顶点权值，边权，需要输出路径序号
// 采用Dijkstra算法
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
  const int MaxVet = 100;  // 最大顶点数
  const int Inf = 0x3FFFFFFF;
  int Graph[MaxVet][MaxVet]{};
  int n{}, m{}, s{}, t{};  // 顶点数，边数，起点编号，终点编号
  int w1[MaxVet]{};        // 城市的堵车指数
  bool flag[MaxVet]{};     // 顶点访问标志
  int dist[MaxVet]{};      // 最远距离
  float sumw1[MaxVet]{};   // 到达当前顶点的堵车指数之和
  float avw1[MaxVet]{};    // 到达当前顶点的堵车指数的平均值
  int preu[MaxVet]{};      // 前一顶点序号
  int flooru[MaxVet]{};    // 每一顶点层数
  stack<int> PrintTrack;   // 用来输出路径值

  // 输入城市的基本数据
  cin >> n >> m >> s >> t;
  for (int i = 0; i < n; ++i) {
    cin >> w1[i];
  }
  // 输入城市图之间的数据
  fill(&Graph[0][0], &Graph[0][0] + MaxVet * MaxVet, Inf);  // 初始化
  for (int i = 0; i < m; ++i) {
    int u{}, v{}, w2{};
    cin >> u >> v >> w2;
    Graph[u][v] = w2;
    Graph[v][u] = w2;
  } 

  // Dijkstra算法
  fill(dist, dist + MaxVet, Inf);
  fill(flag, flag + MaxVet, false);
  dist[s] = 0;
  flooru[s] = 1;     // 起始顶点的层数为1
  sumw1[s] = w1[s];  // 起始顶点的总堵车指数
  avw1[s] = w1[s];   // 起始顶点的平均堵车指数
  for (int i = 0; i < n; ++i) {
    // 先找到距离最近的顶点u
    int u = -1;
    int m = Inf;
    for (int j = 0; j < n; ++j) {
      if (dist[j] < m && flag[j] == false) {
        m = dist[j];
        u = j;    // 记录此顶点
      }
    }
    if (u == -1) { // 未找到最近的距离，说明剩下的顶点和s起点不连通
      break;
    }
    flag[u] = true;     // 此顶点正在被访问
    
    // 访问从u可到达的顶点，并更新最短距离
    for (int v = 0; v < n; ++v) {
      if (flag[v] == false &&    // v顶点没有被访问
          Graph[u][v] < Inf &&   // 此顶点是连通的
          dist[u] + Graph[u][v] <= dist[v]) {
        int floor = flooru[u] + 1;   // 更新此时的访问层数
        float s = sumw1[u] + w1[v];  // 求得当前顶点的总堵车指数 
        float avs = s / floor;       // 求得当前顶点的堵车的平均指数
        if (dist[u] + Graph[u][v] < dist[v]) {
          dist[v] = dist[u] + Graph[u][v];
          sumw1[v] = s;
          flooru[v] = floor;
          avw1[v] = avs;
          preu[v] = u;
        }
        if (dist[u] + Graph[u][v] == dist[v] && 
            avs < avw1[v]) {
          sumw1[v] = s;
          flooru[v] = floor;
          avw1[v] = avs;
          preu[v] = u;
        }
      }
    }
  }

  // 输出最短路径值(并且是最小权值的)
  for (int i = t; i != s; i = preu[i]) {
    PrintTrack.push(i);
  }
  PrintTrack.push(s);
  cout << dist[t] << ' ';
  while (!PrintTrack.empty()) {
    cout << PrintTrack.top();
    if (PrintTrack.top() != t) {
      cout << "->";
    }
    PrintTrack.pop();
  }

  return 0;
}
