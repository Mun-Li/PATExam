/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3汉诺塔.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-05-31
 * @brief:     
 * @userguide: 
 */
#include<cstdio>
#include<cmath>

void HanoiTower(const int n, const char A, const char B, const char C) {
    if (n == 0) {
        return;
    } else {
        HanoiTower(n-1, A, C, B);  // 1. 依靠C，将前n-1个盘子移到B
        printf("%c->%c\n", A, C);    // 2. 将最后一个盘子n从A移到C
        HanoiTower(n-1, B, A, C);  // 3. 依靠A，将B中的n-1个盘子移到C
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", int(pow(2, n)-1));
    HanoiTower(n, 'A', 'B', 'C');
    return 0;
}
