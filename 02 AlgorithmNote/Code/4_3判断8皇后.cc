#include<cstdio>

int g_array[8][8] = {0};
int g_flag = 0;

int main()
{
    int flagC = 0, flagR = 0;
    int mainDiagFlag = 0, subDiagFlag = 0;
    
    // 输入国际棋盘
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            scanf("%d", &g_array[i][j]);
        }
    }

    // 判断每行、每列中有无多个1?
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            flagR = flagR + g_array[i][j];
            flagC = flagC + g_array[j][i];
        }
        if ((flagC > 1) || (flagR > 1)) {
            printf("NO");
            g_flag = 1;
            break;
        }
        flagR = 0;
        flagC = 0;
    }

    //  如何把对角线都加起来?
    if (g_flag == 0) {
        for (int i = 1; i < 8; ++i) {
            int ii = i;         
            for (int j = 0; j <= i; ++j) {
                mainDiagFlag = mainDiagFlag + g_array[ii][j];
                subDiagFlag = subDiagFlag + g_array[ii][7 - j];
                ii--;
            }
            if ((mainDiagFlag > 1) || (subDiagFlag > 1)) {
                printf("No");
                g_flag = 1;
                break;
            }
            mainDiagFlag = 0;
            subDiagFlag = 0;
        }
    }

    if (g_flag == 0) {
        printf("YES");
    }
    return 0;
}
