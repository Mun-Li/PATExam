/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3全排列I.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-05-25
 * @brief:     
 * @userguide: 
 */
#include<stdio.h>
using namespace std;

#define MAX_N 10

int n = 0;
int Pm[MAX_N] = {0};
bool hash_table[MAX_N] = {false};

void FullPermutation(int index) {
    if (index == n+1) {                      // 如果是最后的Pm[end]
        for(int i = 1; i <= n; ++i) {
            printf("%d", Pm[i]);
            if(i < n) {
                printf(" ");
            }
        }
        printf("\n");
    } else if ((index >= 1)&&                // Pm[i]的完整排列需要后一个的完整排列Pm[i+1]
               (index <= n)) {
        for(int x = 1; x <= n; ++x) {        // 从最小的x开始试凑
            if(hash_table[x] == false) {
                Pm[index] = x;               // 当前Pm[i]位置设为最小的x
                hash_table[x] = true;        // 并且标志x已经在排列中了
                FullPermutation(index + 1);  // 完成Pm[i+1]的完整排列
                hash_table[x] = false;       // 当前Pm[i]位置设为另一个x, 上一个x的标志取消
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    FullPermutation(1);
    return 0;
}

/**
 * @brief:     官方题解1
 * @note:
 */
// #include <cstdio>
// #include <vector>
// using namespace std;

// const int MAXN = 8 + 1;
// vector<vector<int> > result;
// vector<int> temp;
// int n;
// bool used[MAXN] = {false};

// void DFS(int idx) {
//     if (idx == n + 1) {
//         result.push_back(temp);
//         return;
//     }
//     for (int i = 1; i <= n; i++) {
//         if (!used[i]) {
//             temp.push_back(i);
//             used[i] = true;
//             DFS(idx + 1);
//             used[i] = false;
//             temp.pop_back();
//         }
//     }
// }

// int main() {
//     scanf("%d", &n);
//     DFS(1);
//     for (int i = 0; i < result.size(); i++) {
//         for (int j = 0; j < result[i].size(); j++) {
//             printf("%d", result[i][j]);
//             printf(j + 1 < result[i].size() ? " " : "\n");
//         }
//     }
//     return 0;
// }

/**
 * @brief:     官方题解2
 * @note:      深度优先搜索的案例
 */
// #include <cstdio>
// #include <vector>
// using namespace std;

// const int MAXN = 8 + 1;
// vector<vector<int> > result;
// vector<int> temp;
// int n;
// bool used[MAXN] = {false};

// void DFS(int idx) {
//     if (idx == n + 1) { // 如果排列长度达到n，表示排列完成
//         result.push_back(temp);
//         return;
//     }
//     for (int i = 1; i <= n; i++) {
//         if (!used[i]) { // 如果数字i未被使用
//             temp.push_back(i); // 将i加入当前排列
//             used[i] = true; // 标记i已被使用
//             DFS(idx + 1); // 递归构建下一个位置的排列
//             used[i] = false; // 回溯，标记i未被使用
//             temp.pop_back(); // 从当前排列中移除i
//         }
//     }
// }

// int main() {
//     scanf("%d", &n);
//     DFS(1); // 从第一个位置开始构建排列
//     for (int i = 0; i < result.size(); i++) {
//         for (int j = 0; j < result[i].size(); j++) {
//             printf("%d", result[i][j]);
//             printf(j + 1 < result[i].size() ? " " : "\n"); // 输出排列，每个数字之间用空格隔开
//         }
//     }
//     return 0;
// }