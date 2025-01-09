// 拯救007_simple
//  https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=672&page=0
// 2024.05.18
// =========================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double diameter = 15;  // 小岛直径
const double edgeDist = 50;  // 边缘距离

// crocodiles vertex
struct Vertex {
  int x;
  int y;
  bool flag;  // wheather visit?
  Vertex(int _x, int _y, bool _flag = false) : x(_x), y(_y), flag(_flag){};
};

struct Graph {
  int maxStep;  // the most distance he can access
  vector<Vertex> data;
  explicit Graph(int _maxStep) : maxStep(_maxStep){};
};

Graph* BuildGraph();
bool saveJamesBond(Graph* graph0);
bool accessNext(Vertex start, Vertex dest, double maxStep);
bool DFS(Graph* graph0, Vertex start);

// build graph
Graph* BuildGraph() { 
  int NumCrocodiles{};
  int maxStep{};
  cin >> NumCrocodiles >> maxStep;

  Graph* graph0 = new Graph(maxStep);
  
  int x{}, y{};
  for (int i{}; i < NumCrocodiles; ++i) {
    cin >> x >> y;
    graph0->data.push_back(Vertex(x, y));
    //graph0->data.emplace_back(x, y);
  }
  return graph0;
}

// 
bool saveJamesBond(Graph* graph0) { 
  int maxStep = graph0->maxStep;  // James Bond max Step

  // 第一个节点位置（当然已经访问过了）
  Vertex start(0, 0, true);

  // 对于每个节点位置都需要先判断它是否能够直接跳出去
  if (maxStep + diameter / 2 >= edgeDist) {
    return true;
  }

  // 先判断第一跳，因为在小岛上，所以不太好统一
  // 开始第2跳以后，进行深度优先搜索
  for (int i = 0; i < graph0->data.size(); ++i) {
    if ((!graph0->data[i].flag) && accessNext(start, graph0->data[i], diameter/2 + maxStep)) {
      // 开始深度优先
      graph0->data[i].flag = true;
      if (DFS(graph0, graph0->data[i])) {
        return true;
      }
    }
  }
  return false;
}

// 两个节点能否到达
bool accessNext(Vertex start, Vertex dest, double maxStep) {
  return (pow(start.x - dest.x, 2) + pow(start.y - dest.y, 2)) <= pow(maxStep, 2);
}

//
bool DFS(Graph* graph0, Vertex start) {
  int maxStep = graph0->maxStep;

  // 先判断这个点start能否直接跳出去
  if ((start.x + maxStep >= edgeDist)  || 
      (start.x - maxStep <= -edgeDist) ||
      (start.y + maxStep >= edgeDist)  || 
      (start.y - maxStep <= -edgeDist)) {
    return true;
  }

  // 再深度优先搜索
  for (int i = 0; i < graph0->data.size(); ++i) {
    if ((!graph0->data[i].flag) && accessNext(start, graph0->data[i], maxStep)) {
      // 开始深度优先
      graph0->data[i].flag = true;
      if (DFS(graph0, graph0->data[i])) {
        return true;
      }
    }
  }
  return false;
}

// main
int main(int argc, char* argv[]) {
  // step1:
  Graph* graph0 = BuildGraph();

  // step2:
  if (saveJamesBond(graph0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
