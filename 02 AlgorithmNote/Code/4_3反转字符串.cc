#include<iostream>
#include<string>

using namespace std;
string str{};

/**
 * @brief:     反转打印字符串
 * @str:       待反转打印的字符串
 * @note:
 */
void PrintStr(string str) {
    if(str.length() == 1) {  // 如果只有一个字符，直接打印
        cout << str;
    } else {                 // 否则先打印最后一个字符，然后反转打印前面剩余字符
      cout << str[str.length()-1];
      str.pop_back();
      PrintStr(str);
    }
}


int main() {
    cin >> str;
    PrintStr(str);
    return 0;
}



/**
 * @brief:     官方题解
 * @note:
 */

// #include <iostream>
// #include <string>
// using namespace std;

// string s;

// string reverseStr(int n) {
//     if (n == 1) {
//         return s.substr(0, 1);
//     } else {
//         return s.substr(n - 1, 1) + reverseStr(n - 1);
//     }
// }

// int main() {
//     cin >> s;
//     cout << reverseStr(s.length()) << endl;
//     return 0;
// }