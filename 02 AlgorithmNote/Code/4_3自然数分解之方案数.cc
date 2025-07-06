/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3自然数分解之方案数.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-07-05
 * @brief:     
 * @userguide: 
 */
#include <cstdio>

/**
 * @brief:     将n拆成不超过bound的组合数
 * @n:
 * @bound:
 * @return: 
 * @note:
 */
int FunF(int n, int bound)
{
    if ((n <= 1) ||
        (bound <= 0)) {
        return 0;
    }
    
    int count = 0;
    for (int i = 1; i <= bound; ++i) {
        count += FunF(n - i, i);  // [i, f(n-i, i)]
        if ((n - i > 0) &&
            (n - i <= i) &&
            (n - i <= bound)) {   // [i, n-i]
            ++count;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", FunF(n, n - 1));
    return 0;
}
