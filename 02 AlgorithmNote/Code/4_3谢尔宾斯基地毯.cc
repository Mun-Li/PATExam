/**
 * @copyright: Copyright (c) ECOFLOW 2017 - 2025. All rights reserved
 * @file:      4_3谢尔宾斯基地毯.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-06-29
 * @brief:     
 * @userguide: 
 */
#include "cstdio"
#include "cstring"
#include "cmath"

#define MAX_N (3 * 3 * 3 * 3 * 3 * 3 + 2)

char g_matX[MAX_N][MAX_N];

static void FunX(int hx, int ox, int oy) {
    for (int i = ox; i <= hx + ox; ++i) {
        for (int j = oy; j <= hx + oy; ++j) {
            g_matX[i][j] = 'X';
        }
    }
}

static void FunF(int nx, int ox, int oy) {
    if (nx == 1) {
        g_matX[ox][oy] = ' ';
        return;
    }

    if (nx == 2) {
        g_matX[ox][oy] = ' ';
        g_matX[ox][oy + 1] = ' ';
        g_matX[ox][oy + 2] = ' ';

        g_matX[ox + 1][oy] = ' ';
        g_matX[ox + 1][oy + 1] = 'X';
        g_matX[ox + 1][oy + 2] = ' ';

        g_matX[ox + 2][oy] = ' ';
        g_matX[ox + 2][oy + 1] = ' ';
        g_matX[ox + 2][oy + 2] = ' ';
    }

    int hx = nx / 3;
    int hx2 = 2 * hx;

    // 第一排
    FunF(hx, ox, oy);
    FunF(hx, ox, oy + hx);
    FunF(hx, ox, oy + hx2);

    // 第二排
    FunF(hx, ox + hx, oy);
    FunX(hx, ox + hx, oy + hx);  // 中间填充X
    FunF(hx, ox + hx, oy + hx2);

    // 第三排
    FunF(hx, ox + hx2, oy);
    FunF(hx, ox + hx2, oy + hx);
    FunF(hx, ox + hx2, oy + hx2);
}

int main()
{
    int n = 0, nxAll = 0;
    memset(g_matX, ' ', sizeof(g_matX));
    scanf("%d", &n);

    nxAll = (int)pow(3.0, n - 1) + 2;
    
    // 填充地毯图案
    FunF(nxAll - 2, 1, 1);

    // 填充最外圈
    for(int i = 0; i < nxAll; ++i) {
        if ((i == 0) ||
            (i == nxAll - 1)) {
            for (int j = 0; j < nxAll; ++j) {
                g_matX[i][j] = '+';
            }
        } else {
            g_matX[i][0] = '+';
            g_matX[i][nxAll - 1] = '+';
        }
    }

    // 打印输出
    for(int i = 0; i < nxAll; ++i) {
        for(int j = 0; j < nxAll; ++j) {
            printf("%c", g_matX[i][j]);
        }
        printf("\n");
    }

    return 0;
}
