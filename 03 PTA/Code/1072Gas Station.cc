#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int mINF = 0x7FFFFFFF;

// N: num of houses
// M: num of gas stations
// K: num of roads connecting houses and gas stations
// Ds: the maximum service range of gas station
int N{}, M{}, K{}, Ds{};
int Graph[1100][1100]{};  // graph for housing and stations
int dist[1100]{};  // distance between vert a and vert b
bool visit[1100]{};  // is visit?

void Dijkstra(int start) {
  fill(dist + 1, dist + N + M + 1, mINF);
  fill(visit + 1, visit + N + M + 1, false);
  dist[start] = 0;

  // for all vertx of graph
  for (int i = 1; i <= N + M; ++i) {
    int u = -1, min_u = mINF;

    // step1: index of the minmun of distance
    for (int j = 1; j <= N + M; ++j) {
      if (dist[j] < min_u && (visit[j] == false)) {
        u = j;
        min_u = dist[u];
      }
    }
    if (u == -1) {  // no minmum
      break;
    }

    // step2: update the distance from u to j
    visit[u] = true;
    for (int j = 1; j <= N + M; ++j) {
      if ((visit[j] == false) && (Graph[u][j] != 0) &&
          (dist[u] + Graph[u][j] < dist[j])) {
        dist[j] = dist[u] + Graph[u][j];
      }
    }
  }
}


int main() {

  cin >> N >> M >> K >> Ds;  // input first lines

  // next, input K lines
  for (int i = 0; i < K; ++i) {
    string t1{}, t2{};
    int a{}, b{}, w{};
    cin >> t1 >> t2 >> w;
    if (t1[0] == 'G') {  // gas station
      a = N + stoi(t1.substr(1));  // the length of numbers is unknown
    } else {  // housing
      a = stoi(t1);
    }
    if (t2[0] == 'G') {  // gas station
      b = N + stoi(t2.substr(1));
    } else {  // housing
      b = stoi(t2);
    }
    Graph[a][b] = Graph[b][a] = w;
  }

  int ans_id{};  // ans_id: the id of solution of gas station
  double ans_min{};  // ans_min: the minmum distance between solution and all housing
  double ans_aver = mINF;  // ans_aver: the average distance between solution and all housing
  bool ans_flag{};  // ans_flag: 

  for (int i = N + 1; i <= N + M; ++i) {
    int id = i - N;
    double ans_min_i = mINF;
    double ans_aver_i = 0.0;
    bool ans_flag_i = true;

    // dijkstra for minmun distance
    // between every station and housing
    Dijkstra(i);
    
    // seek minmum in all dist
    for (int i = 1; i <= N; ++i) {
      if (dist[i] > Ds) {
        ans_flag_i = false;
        break;
      }
      ans_aver_i += double(dist[i]);
      if (dist[i] < ans_min_i) {
        ans_min_i = dist[i];
      }
    }
    
    if (ans_flag_i == false) {  // next gas station
      continue;
    }

    // update answer candidate
    ans_flag = true;
    ans_aver_i /= N;
    if (ans_min_i > ans_min) {  // as far as possible
      ans_id = id;
      ans_min = ans_min_i;
      ans_aver = ans_aver_i;
    } else if (ans_min_i == ans_min) {
      if (ans_aver_i < ans_aver) {
        ans_id = id;
        ans_min = ans_min_i;
        ans_aver = ans_aver_i;
      }
    }
  }

  if (ans_flag) {
    printf("G%d\n%.1f %.1f", ans_id, ans_min, ans_aver);
  } else {
    printf("No Solution");
  }
  return 0;
}
