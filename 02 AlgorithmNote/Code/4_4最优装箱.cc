// 最优装箱
// 最多能把多少个箱子装上船
// https://sunnywhy.com/sfbj/4/4
//
// =====================
#include<iostream>
#include<algorithm>
using namespace std;

const int n_max = 100001;

int n, W;
int wi[n_max]{};

int main() {
  cin >> n >> W;
  for (int i = 0; i < n; ++i) {
    cin >> wi[i];
  }
  sort(wi, wi+n);

  int count = 0;
  int sum_w = 0;
  int remain_w = W;
  for(int i = 0; i < n; ++i) {
    if (remain_w >= wi[i]) {
      count = count + 1;
      sum_w = sum_w + wi[i];
      remain_w = remain_w - wi[i];
    } else {
      break;
    }
  }
  cout << count << ' ' << sum_w;
  return 0;
}
