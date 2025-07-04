/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3盒分形.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-06-29
 * @brief:     
 * @userguide: 
 */

#include "cstdio"
#include "cmath"
#include "cstring"

#define MAX_N (3 * 3 * 3 * 3 * 3 * 3)  // 1 <= n <= 7;

char g_matX[MAX_N][MAX_N];  // TODO: char类型的初始化?

/**
 * @brief:     
 * @nx: 需要生成盒子X的边长
 * @x: 盒子X的起点x
 * @y: 盒子X的起点y
 * @note:
 */
void GenMatrixX(int nx, int x, int y)
{
    // end: 在中间填充X
    if (nx == 1) {
        g_matX[x][y] = 'X';
        return;
    }

    int nxNext = nx/3;

    // step1: 填充左上角的X
    GenMatrixX(nxNext, x, y);

    // step2: 填充右上角的X
    GenMatrixX(nxNext, x, y + 2 * nxNext);

    // step3: 填充右下角的X
    GenMatrixX(nxNext, x + 2 * nxNext, y + 2 * nxNext);

    // step4: 填充左下角的X
    GenMatrixX(nxNext, x + 2 * nxNext, y);

    // step5: 填充中间的X
    GenMatrixX(nxNext, x + nxNext, y + nxNext);
}

int main ()
{
    int n = 0, nx = 0;
    memset(g_matX, ' ', sizeof(g_matX));   // TODO: char类型的初始化?
    scanf("%d", &n);
    nx = (int)pow(3.0, n - 1);
    GenMatrixX(nx, 0, 0);
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < nx; ++j) {
            // TODO 字符串的打印 : ' ' / " " / %c / %s
            printf("%c", g_matX[i][j]);
        }
        printf("\n");
    }
}
