/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3回文字符串.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-05-24
 * @brief:     
 * @userguide: 
 */
#include<iostream>
#include<string>

using namespace std;

string str{};

bool JudgePalindrome(string str) {
    if(str.size() != 1) {  // 非空字符串
        if(str[0] == str[str.size()-1]) {
            string temp_str = str.substr(1, str.size()-2);
            if(temp_str.empty()) {
                return true;
            } else {
                return JudgePalindrome(temp_str);
            }
        } else {
            return false;
        }
    } else {
        return true;
    }
}

int main() {
    cin >> str;
    if(JudgePalindrome(str)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

/**
 * @brief:     官方题解
 * @note:   我这写的什么。。。啰里啰唆的
 */
// #include <iostream>
// #include <string>
// using namespace std;

// string s;

// bool isPalindrome(int i, int j) {
//     if (i >= j) {
//         return true;
//     } else {
//         return (s[i] == s[j]) && isPalindrome(i + 1, j - 1);
//     }
// }

// int main() {
//     cin >> s;
//     cout << (isPalindrome(0, s.length() - 1) ? "Yes" : "No") << endl;
//     return 0;
// }