/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3数字螺旋矩阵.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-06-16
 * @brief:     
 * @userguide: 
 */

#include <cstdio>

#define MAX_N (25)

int g_matrixN[MAX_N][MAX_N] = {0};
int g_currentN = 1;

/**
 * @brief:     
 * @n: 螺旋阵的边长
 * @x: 螺旋阵的起点坐标x
 * @y: 螺旋阵的起点坐标y
 * @note:
 */
void GenMatrixN(int n, int x, int y)
{
    if (n == 0) {
        return;
    } else if (n == 1) {
        g_matrixN[x][y] = g_currentN++;
    } else {
        // step1: 从左到右输出第一排
        for (int j = y; j <= y + n -2; ++j) {
            g_matrixN[x][j] = g_currentN++;
        }

        // step2: 从上到下输出右边第一列
        for (int i = x; i <= x + n - 2; ++i) {
            g_matrixN[i][y + n -1] = g_currentN++;
        }

        // step3: 从右到左输出最后一排
        for (int j = y + n - 1; j >= y + 1; --j) {
            g_matrixN[x + n - 1][j] = g_currentN++;
        }

        // step4: 从下到上输出左边第一列
        for (int i = x + n - 1; i >= x + 1; --i) {
            g_matrixN[i][y] = g_currentN++;
        }

        // 开始递归里边一层的螺旋阵
        GenMatrixN(n - 2, x + 1, y + 1);
    }
}

void PrintMatrixN(int n)
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d", g_matrixN[i][j]);
            printf(j < n ? " " : "\n");  // TODO 🐂
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    GenMatrixN(n, 1, 1);
    PrintMatrixN(n);
    return 0;
}
