/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3 斐波拉契数列1.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-05-16
 * @brief:     
 * @userguide: 
 */
#include<iostream>
using namespace std;

long long int Fb(long long int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else if (n > 2) {
        return Fb(n-1) + Fb(n-2);
    }
}

int main() {
    int n = 0;
    cin >> n;
    cout << Fb(n);
    return 0;
}
