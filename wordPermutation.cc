// 单词排列
// 给定一个不存在重复字母的单词
// 将其中的字母进行重新排列
// 输出所有可能的单词
// ========================
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string stt{};
string sort_stt;
string word;
int stt_len{};

static void PrintPermutation(int idx) {
  if (idx == stt_len + 1) {
    cout << word << endl;
  } else {
    for (int i = 0; i < stt_len; ++i) {
      if (word.find(sort_stt[i]) == string::npos) {
        word += sort_stt[i];
        PrintPermutation(idx + 1);
        word.erase(word.length() - 1);
      }
    }
  }
}

int main() {
  cin >> stt;
  stt_len = stt.length();
  sort_stt = stt;
  sort(sort_stt.begin(), sort_stt.end());

  PrintPermutation(1);

  return 0;
}
