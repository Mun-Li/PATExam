/**
 * @copyright: Copyright (c) Mun.Li 2017 - 2025. All rights reserved
 * @file:      4_301串.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-07-20
 * @brief:     
 * @userguide: 
 */

#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> tmp;

/**
 * @brief:     
 * @n:     代表第n位bit
 * @note:
 */
void DfsResult(int n)
{
    if (n == 0) {
        result.push_back(tmp);
    } else if (n >= 1) {
        tmp.push_back(0);
        DfsResult(n - 1);
        tmp.pop_back();
        tmp.push_back(1);
        DfsResult(n - 1);
        tmp.pop_back();
    } else {}
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    DfsResult(n);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            printf("%d", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
