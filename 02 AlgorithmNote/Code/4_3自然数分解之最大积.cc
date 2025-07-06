/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3自然数分解之最大积.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-07-04
 * @brief:     
 * @userguide:  利用的是递归方法  // TODO 也可以用动态规划的方法
 */
#include "cstdio"
#include "algorithm"

using namespace std;


int FunF(int n)
{
    if (n == 1) {
        return 1;
    }

    int maxFn = 1;
    for (int i = 1; i < n; ++i) {
        maxFn = max(maxFn, max(i * FunF(n - i), i * (n - i)));
    }
    
    return maxFn;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", FunF(n));
}

