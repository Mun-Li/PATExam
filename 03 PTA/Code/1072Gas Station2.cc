#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int max_inf = 0x3FFFFFFF;

struct Node {
  int v;  // next vertex
  int w;  // weight
  Node(int v_, int w_) : v(v_), w(w_){};
};
vector<Node> graph[1020]{};  // undirected graph

// N:  the total number of houses
// M:  the total number of the candidate locations for the gas stations
// K:  the number of roads connecting the houses and the gas stations
// Ds: the maximum service range of the gas station.
int N{}, M{}, K{}, Ds{};

int min_dist[1020]{};
bool flag_node[1020]{};

void Dijkstra_Min_Dist(int start) {
  // init
  fill(min_dist + 1, min_dist + N + M + 1, max_inf);
  fill(flag_node + 1, flag_node + N + M + 1, false);
  min_dist[start] = 0;

  for (int i = 1; i <= N + M; ++i) {
    // step1: find the min of min_dist
    int min_dist_min = max_inf, min_u = -1;
    for (int i = 1; i <= N + M; ++i) {
      if (min_dist[i] < min_dist_min && (flag_node[i] == false)) {
        min_u = i;
        min_dist_min = min_dist[i];
      }
    }
    if (min_u == -1) {
      return;
    }

    // step2: update min_dist
    flag_node[min_u] = true;
    for (int j = 0; j < graph[min_u].size(); ++j) {
      int v = graph[min_u][j].v;
      int w = graph[min_u][j].w;
      if (min_dist[min_u] + w < min_dist[v] && (!flag_node[v])) {
        min_dist[v] = min_dist[min_u] + w;
      }
    }
  }
  return;
}

int main() {
  // input exampl
  cin >> N >> M >> K >> Ds;
  for (int i = 1; i <= K; ++i) {
    string s1{}, s2{};
    int Dist{};
    int s1_n{}, s2_n{};
    cin >> s1 >> s2 >> Dist;
    if (s1[0] == 'G') {  // is gas station
      s1_n = stoi(s1.substr(1)) + N;
    } else {
      s1_n = stoi(s1);
    }
    if (s2[0] == 'G') {  // is gas station
      s2_n = stoi(s2.substr(1)) + N;
    } else {
      s2_n = stoi(s2);
    }
    // make a undirected graph
    graph[s1_n].push_back(Node(s2_n, Dist));
    graph[s2_n].push_back(Node(s1_n, Dist));
  }

  // caculate all the distance, all gas station
  int ans_gas_id{}, ans_gas_min{};
  double ans_gas_ave{};
  bool ans_flag = false;
  for (int i = N + 1; i <= N + M; ++i) {
    int sum_dist{}, min_all_dis = max_inf;
    double sum_dist_ave{};
    bool flag_sum = true;
    Dijkstra_Min_Dist(i);
    for (int j = 1; j <= N; ++j) {
      if (min_dist[j] > Ds) {  // more than service distance
        flag_sum = false;
        break;
      } else {
        sum_dist += min_dist[j];
        if (min_dist[j] < min_all_dis) {
          min_all_dis = min_dist[j];
        }
      }
    }
    if (flag_sum) {
      ans_flag = true;
      sum_dist_ave = double(sum_dist) / N;
      if (min_all_dis > ans_gas_min) {
        ans_gas_id = i - N;
        ans_gas_min = min_all_dis;
        ans_gas_ave = sum_dist_ave;
      } else if (min_all_dis == ans_gas_min) {
        if (sum_dist_ave < ans_gas_ave) {
          ans_gas_id = i - N;
          ans_gas_ave = sum_dist_ave;
        }
      }
    }
  }
  if (ans_flag) {
    cout << 'G' << ans_gas_id << endl;
    printf("%.1f %.1f", 1.0 * ans_gas_min, ans_gas_ave);
  } else {
    printf("No Solution\n");
  }

  return 0;
}
