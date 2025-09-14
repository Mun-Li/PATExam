/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3全排列ii.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-08-17
 * @brief:     
 * @userguide: 
 */
#include<stdio.h>
#include<vector>
using namespace std;

#define MAX_N (8 + 1)

static int g_n = 0;
static int g_arrayN[MAX_N] = {0};
static vector<int> g_tempResult;
static vector<vector<int>> g_result;

static bool IsInVector(int tmp, vector<int> tmpVector)
{
    for (int i = 0; i < tmpVector.size(); ++i) {
        if (tmp == tmpVector[i]) {
            return true;
        }
    }
    return false;
}

/**
 * 获取前k个数的排列  // TODO 这种类型的递归需要好好理解一下
 */
static void GetFullPermutation(int k)
{
    if (k == g_n + 1) {
        g_result.push_back(g_tempResult);
    } else {
        for (int i = 1; i <= g_n; ++i) {
            if (IsInVector(g_arrayN[i], g_tempResult) == false) {
                g_tempResult.push_back(g_arrayN[i]);
                GetFullPermutation(k + 1);
                g_tempResult.pop_back();
            }
        }
    }
}

int main()
{
    scanf("%d", &g_n);
    for (int i = 1; i <= g_n; ++i) {
        scanf("%d", &g_arrayN[i]);
    }
    
    GetFullPermutation(1);

    for (int i = 0; i < g_result.size(); ++i) {
        for (int j = 0; j < g_n; ++j) {
            printf("%d", g_result[i][j]);
            if (j < g_n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}