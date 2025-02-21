// 整数配对
// https://sunnywhy.com/sfbj/4/4
//
// ==============================
#include <algorithm>
#include <iostream>
using namespace std;

const int n_max = 10001, m_max = 10001;

int n = 0, m = 0;
int S[n_max] = {0}, T[m_max] = {0};

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> T[i];
  }
  sort(S, S + n);
  sort(T, T + m);

  int count = 0;
  int idx_S = 0, idx_T = 0;
  while (idx_S < n && idx_T < m) {
    if (S[idx_S] <= T[idx_T]) {
      count++;
      idx_S++;
      idx_T++;
    } else {
      idx_T++;
    }
  }
  cout << count;
  return 0;
}
