// 4_4 贪心
// 区间不相交问题
//
// ========================
#include<iostream>
#include<algorithm>
using namespace std;

const int max_n = 10001;
struct OpenInterval {
  unsigned int x;
  unsigned int y;
};

OpenInterval interval_array[max_n];

static bool cmp (OpenInterval O1, OpenInterval O2) {
  if (O1.x != O2.x) {
    return O1.x > O2.x;
  } else {
    return O1.y < O2.y;
  }
}

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> interval_array[i].x >> interval_array[i].y;
  }
  sort(interval_array, interval_array + n, cmp);
  int ans = 1, last_x = interval_array[0].x;
  for (int i = 1; i < n; ++i) {
    if (interval_array[i].y <= last_x) {
      ans = ans + 1;
      last_x = interval_array[i].x;
    }
  }
  cout << ans;
  return 0;
}
