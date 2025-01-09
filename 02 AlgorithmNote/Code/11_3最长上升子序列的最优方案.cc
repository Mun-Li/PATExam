#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 100;
int a[MAXN]{};
vector<int> a_vector[MAXN]{};  // 每个a所对应的上升子序列

int main() { 
  int n {}, MaxLength{};
  cin >> n;
  for (int i = 0; i < n; ++i) {  // 输入序列
    cin >> a[i];
  }
  a_vector[0].push_back(a[0]);     // 初始化第一个a所对应的上升子序列，就是它本身
  MaxLength = a_vector[0].size();  // 这个时候它就是最大的
  for (int i = 1; i < n; ++i) {
    a_vector[i].push_back(a[i]);   // 初始每个a所对应的上升子序列就是它本身
    for (int j = 0; j < i; ++j) {  // 切记从前往后搜索，这样就自然满足了序号的要求（而不是从后面开始搜索）
      if (a[i] >= a[j] && a_vector[i].size() <= a_vector[j].size()) {
        a_vector[i] = a_vector[j];
        a_vector[i].push_back(a[i]);  // 保存此刻最长序列的值
      }
    }
    if (a_vector[i].size() > MaxLength) {  // 记录当前最长的序列长度
      MaxLength = a_vector[i].size();
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a_vector[i].size() == MaxLength) {  // 第一个最长的子序列就是我们所需要的
      cout << MaxLength << endl;
      cout << a_vector[i][0];
      for (int j = 1; j < a_vector[i].size(); ++j) {
        cout << ' ' << a_vector[i][j];
      }
      break;  // 后面还有的话，序号就落后于第一个最长的子序列
    }
  }
  // 输出
  return 0;
}