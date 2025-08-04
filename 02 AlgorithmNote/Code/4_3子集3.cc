/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3子集3.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-08-03
 * @brief:     
 * @userguide: 
 */
#include<cstdio>
#include<vector>

using namespace std;

vector<int> input;
vector<int> tmp;
vector<vector<int>> result;

/**
 * @brief:     判断当前子集中无该子集tmp
 * @note:
 */
static bool IsNoSet(int k) {
    for (int i = 0; i < result.size(); ++i) {
        if (result[i].size() == k) {
            if (result[i]  == tmp) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief:     搜索大小为k的子集
 * @k:
 * @note:
 */
static void SeekSetK(int k, int start) {
    if (k == tmp.size()) {        // 子集tmp大小为k
        if (IsNoSet(k) == true) {  // 判断当前无该子集
            result.push_back(tmp);
        }
    } else {  // 递归搜索
        for(int i = start; i < input.size(); ++i) {
            tmp.push_back(input[i]);
            SeekSetK(k, i + 1);
            tmp.pop_back();
        }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        input.push_back(0);
        scanf("%d", &input[i]);
    }

    // 统计所有子集
    // 子集的大小k有0, 1, 2, 3, ... , n
    for (int k = 0; k <= n; ++k) {
        SeekSetK(k, 0);
    }

    // 打印输出子集
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            printf("%d", result[i][j]);
            if (j < result[i].size() - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
