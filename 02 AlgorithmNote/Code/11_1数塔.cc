#include<iostream>
using namespace std;

const int MaxN = 1000;
int NumTa[MaxN][MaxN]{};
int dp[MaxN][MaxN]{};

int main() {

  int n{};
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> NumTa[i][j];
    }
  }

  // 边界
  for (int i = 1; i <= n; ++i) {
    dp[n][i] = NumTa[n][i];
  }

  // 自下向顶
  for (int i = n - 1; i >= 1; --i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + NumTa[i][j];
    }
  }

  cout << dp[1][1];
  return 0;
}