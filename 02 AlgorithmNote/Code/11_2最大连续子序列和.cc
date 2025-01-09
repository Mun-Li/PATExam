#include<iostream>
using namespace std;

const int MaxN = 10002;
int a[MaxN]{};
int dp[MaxN]{};

int main() {
  int n{}, max_dp{};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0] = a[0];
  max_dp = dp[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] > dp[i - 1] + a[i]) {
      dp[i] = a[i];
    } else {
      dp[i] = dp[i - 1] + a[i];
    }
    if (dp[i] > max_dp){
      max_dp = dp[i];
    }
  }
  cout << max_dp;
  return 0;
}
