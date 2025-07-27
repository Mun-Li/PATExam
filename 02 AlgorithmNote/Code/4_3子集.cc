/**
 * @copyright: Copyright (c) ECOFLOW 2017 - 2025. All rights reserved
 * @file:      4_3子集.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-07-27
 * @brief:     
 * @userguide: 
 */
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n = 0;
vector<int> tmp;
vector<vector<int>> result;

void GetSubSet(int idx) {
    if (idx == n + 1) {
        result.push_back(tmp);
    } else {
        tmp.push_back(idx);
        GetSubSet(idx + 1);
        tmp.pop_back();
        GetSubSet(idx + 1);
    }
}

bool CmpResult(vector<int> &A, vector<int> &B) {
    return ((A.size() != B.size()) ? (A.size() < B.size()) : (A < B));
}

int main() {
    scanf("%d", &n);
    GetSubSet(1);
    sort(result.begin(), result.end(), CmpResult);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j + 1 < result[i].size(); ++j) {
            printf("%d ", result[i][j]);
        }
        if (i == 0) {  // 空集 直接换行
            printf("\n");
        } else {
            printf("%d\n", result[i][result[i].size() - 1]);
        }
    }
    return 0;
}


