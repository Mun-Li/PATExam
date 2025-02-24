// 4_4 贪心
// 区间选点问题
// https://sunnywhy.com/sfbj/4/4/153
//=====================================
#include<iostream>
#include<algorithm>
using namespace std;

const int nmax = 100001;
struct Intergral {
  int x = 0;
  int y = 0;
};

int n = 0;
Intergral my_array[nmax];

static bool cmp(const Intergral a, const Intergral b) {
  if (a.y != b.y) {      // 如果右端点不相等
    return a.y < b.y;    // 右端点从小到大排列
  } else {
    return a.x < b.x;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n ; ++i) {
    cin >> my_array[i].x >> my_array[i].y;
  }
  sort(my_array, my_array+n, cmp);

  int ans = 1, last_y = my_array[0].y;
  for(int i = 1; i < n; ++i) {
    if(last_y < my_array[i].x) {
      ++ans;
      last_y = my_array[i].y;
    }
  }
  cout << ans;
  return 0;
}
