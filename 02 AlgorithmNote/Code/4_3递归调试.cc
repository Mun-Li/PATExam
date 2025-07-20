/**
 * @copyright: Copyright (c) Mun.Li 2017 - 2025. All rights reserved
 * @file:      4_3递归调试.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-07-19
 * @brief:     
 * @userguide: 
 */
#include <cstdio>

void FunF(int n, int deepth)
{
    for (int i = 0; i < deepth - 1; ++i) {
        printf("    ");
    }
    printf("n=%d\n", n);
    if (n <= 2) {
        return;
    } else {
        FunF(n - 2, deepth + 1);
        FunF(n - 1, deepth + 1);
    }
}


int main()
{
    int n = 0;
    scanf("%d", &n);
    FunF(n, 1);
    return 0;
}









