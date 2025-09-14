/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3全排列iii.c
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-08-24
 * @brief:     
 * @userguide: 
 */

#include<cstdio>
#include<vector>
using namespace std;

#define MAX_N (8)

int g_n = 0;
int g_input[MAX_N] = {0};
bool g_hashTable[MAX_N] = {false};
vector<int> g_temp;
vector<vector<int>> g_result;

bool IsInResult(vector<int> &tempA, vector<vector<int>> &resultA) {
    for (int i = 0; i < resultA.size(); ++i) {
        if (tempA == resultA[i]) {
            return true;
        }
    }
    return false;
}

/**
 * @brief:深度搜索第k位
 */
void GetFullPermutation(int k)
{
    if (k == g_n &&
       (IsInResult(g_temp, g_result) == false)) {  // 已搜索到最后一个了
        g_result.push_back(g_temp);
        for (int i = 0; i < g_n; ++i) {
            printf((i < g_n - 1) ? "%d " : "%d\n", g_temp[i]);
        }
    } else {  // 遍历第k位置的可能性
        for (int i = 0; i < g_n; ++i) {
            if (g_hashTable[i] == false) {
                g_temp.push_back(g_input[i]);
                g_hashTable[i] = true;
                GetFullPermutation(k + 1);
                g_temp.pop_back();
                g_hashTable[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%d", &g_n);
    for (int i = 0; i < g_n; ++i) {
        scanf("%d", &g_input[i]);
    }

    GetFullPermutation(0);
    
    return 0;
}
