/**
 * @copyright: Copyright (c) Mun.Li 2017 - 2025. All rights reserved
 * @file:      4_3输出递归深度.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-07-19
 * @brief:     
 * @userguide: 
 */

#include <cstdio>

void FunF(int n) {
    static int deep = 1;
    printf("%d\n", deep);
    ++deep;
    if (n <= 2) {
        return;
    } else {
        FunF(n - 1);
        --deep;
        FunF(n - 2);
        --deep;
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    FunF(n);
    return 0;
}
