#include<iostream>
using namespace std;

const int MaxN = 10005;
int dp[MaxN]{0};

// 由于到达第n层楼梯可以由n-1直接跳上去，也可以由n-2直接跳上去
// 和斐波那契数列有点像
int main(void) {

  int n{};
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 2])%10007;
  }
  cout << dp[n];
  return 0;
}
