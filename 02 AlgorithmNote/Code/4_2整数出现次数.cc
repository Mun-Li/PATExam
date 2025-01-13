// 整数出现次数
//
//
// ========================

#include <iostream>
using namespace std;

const int nmax = 101;

int n = 0;
int intarray[nmax] = {0};
bool intflag[nmax] = {false};

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp = 0;
    cin >> temp;  // 1 <= temp <= 100
    if (intflag[temp] == false) {
      intflag[temp] = true;
      intarray[temp] = 1;
    } else {
      intarray[temp] += 1;
    }
  }

  // output
  for (int i = 1; i <= 100; ++i) {
    if (intflag[i]) {
      cout << i << ' ' << intarray[i] << endl;
    }
  }
  return 0;
}