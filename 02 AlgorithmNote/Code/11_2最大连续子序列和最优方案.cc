#include <iostream>
using namespace std;

const int MaxN = 10002;
int a[MaxN]{};
int dp[MaxN]{};

int main() {
  int n{}, max_dp{};
  int index_i{}, index_j{};
  int cout_index_i{}, cout_index_j{};

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0] = a[0];
  index_i = 0;
  index_j = 0;
  cout_index_i = index_i;
  cout_index_j = index_j;
  max_dp = dp[0];

  for (int i = 1; i < n; ++i) {
    if (a[i] > dp[i - 1] + a[i]) {
      dp[i] = a[i];
      index_i = i;
      index_j = i;
    } else {
      dp[i] = dp[i - 1] + a[i];
      index_j = i;
    }
    if (dp[i] > max_dp) {
      max_dp = dp[i];
      cout_index_i = index_i;
      cout_index_j = index_j;
    }  // 后面这里不用在去判断 i，j的大小啥的了，肯定没有前面的小！
  }
  cout << max_dp << ' ' << cout_index_i + 1 << ' ' << cout_index_j + 1;
  return 0;
}
