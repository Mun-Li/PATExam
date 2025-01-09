#include<iostream>
using namespace std;

const int MAXN = 102;
string s1{};
string s2{};
int LongestCommonSubseq[MAXN][MAXN]{};

int main(void) {
  cin >> s1;
  cin >> s2;
  for (int i = 1; i <= s1.size(); ++i) {
    for (int j = 1; j <= s2.size(); ++j) {
      if (s1[i - 1] == s2[j - 1]) { // 注意字符串是从0,0开始的
        LongestCommonSubseq[i][j] = LongestCommonSubseq[i - 1][j - 1] + 1;
      } else {
        LongestCommonSubseq[i][j] = max(LongestCommonSubseq[i - 1][j],
                                        LongestCommonSubseq[i][j - 1]);
      }
    }
  }
  cout << LongestCommonSubseq[s1.size()][s2.size()];

  return 0;
}
