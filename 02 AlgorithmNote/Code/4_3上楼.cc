/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3上楼.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-05-27
 * @brief:     
 * @userguide: 
 */
#include<cstdio>

int StairWays(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n > 2) {
        // 有两种方式上到第n个阶梯：
        // 1. 从第n-1直接一步到n
        // 2. 从第n-2直接两步到n
        return (StairWays(n - 1) + StairWays(n - 2));
    }
    return 0;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d", StairWays(n));
    return 0;
}
