// 4_4 贪心
// B1023 组个最小数
//
// ========================

#include <iostream>
#include <string>
using namespace std;

unsigned int num[10] = {0};
string ans{};

int main() {
  int all_num = 0;
  for (int i = 0; i < 10; ++i) {
    cin >> num[i];
    all_num = all_num + num[i];
  }

  for (int i = 1; i <= all_num; ++i) {
    if (i == 1) {
      for (int j = 1; j <= 9; ++j) {
        if (num[j] != 0){
          ans = ans + char(48+j);
          num[j] = num[j] - 1;
          break;
        }
      }
    } else {
      for (int j = 0; j <= 9; ++j) {
        if (num[j] != 0) {
          ans = ans + char(48 + j);
          num[j] = num[j] - 1;
          break;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
