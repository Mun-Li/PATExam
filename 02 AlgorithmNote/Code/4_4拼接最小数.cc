// 4_4 拼接最小数
// https://sunnywhy.com/sfbj/4/4
//
// ==========================
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

const int max_str = 10001;

int n{};
string str_all[max_str]{};

// 比较字符串对应的数字大小
static bool cmp(string str1, string str2) {
  return (str1 + str2) < (str2 + str1);
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> str_all[i];
  }
  sort(str_all, str_all+n, cmp);

  string result{};
  for(int i = 0; i < n; ++i){
    result += str_all[i];
  }
  while((result.size() > 1) && (result[0] == '0')) {
    result.erase(result.begin());
  }
  cout << result;
  return 0;
}
