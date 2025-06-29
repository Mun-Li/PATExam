/**
 * @copyright: Copyright (c) MMM 2017 - 2025. All rights reserved
 * @file:      4_3 棋盘覆盖问题.cc
 * @author:    LongLong.Li
 * @version:   1.0
 * @date:      2025-06-09
 * @brief:     
 * @userguide: 这问题是人想出来的？？？
 */
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int _x, int _y) : x(_x), y(_y) {};  // 构造函数
};

vector<Point> AllPoint;

/**
 * @brief:     
 * @k:       当前棋盘的大小：k = 2^n
 * @cx:      当前棋盘中初始状态的黑色棋子位置x
 * @cy:      当前棋盘中初始状态的黑色棋子位置y
 * @ox:      当前棋盘左下角相对于原点x的位置
 * @oy:      当前棋盘左下角相对于原点y的位置
 * @note:
 */
void OverlayCheckerboard (int k, int cx, int cy, int ox, int oy) { 
    if (k == 1) {
        return;
    }

    // 分开四块棋盘进行递归：
    int h = k/2;

    // 覆盖左下角棋盘
    if ((cx - ox < h) && (cy - oy < h)) {  // 黑点在左下角
        AllPoint.push_back(Point(ox + h, oy + h));
        OverlayCheckerboard(h, cx, cy, ox, oy);
    } else {
        OverlayCheckerboard(h, ox + h - 1, oy + h - 1, ox, oy);
    }

    // 覆盖左上角棋盘
    if ((cx - ox < h) && (cy - oy >= h)) {  // 黑点在左上角
        AllPoint.push_back(Point(ox + h, oy + h - 1));
        OverlayCheckerboard(h, cx, cy, ox, oy + h);
    } else {
        OverlayCheckerboard(h, ox + h - 1, oy + h, ox, oy + h);
    }

    // 覆盖右下角棋盘
    if ((cx - ox >= h) && (cy - oy < h)) {  // 黑点在右下角
        AllPoint.push_back(Point(ox + h - 1, oy + h));
        OverlayCheckerboard(h, cx, cy, ox + h, oy);
    } else {
        OverlayCheckerboard(h, ox + h, oy + h - 1, ox + h, oy);
    }

    // 覆盖右上角棋盘
    if ((cx - ox >= h) && (cy - oy >= h)) {  // 黑点在右上角
        AllPoint.push_back(Point(ox + h - 1, oy + h - 1));
        OverlayCheckerboard(h, cx, cy, ox + h, oy + h);
    } else { 
        OverlayCheckerboard(h, ox + h, oy + h, ox + h, oy + h);
    }
}

bool SortAllPoint(Point A, Point B) {
    return ((A.x != B.x) ? (A.x < B.x) : (A.y < B.y));
}

int main() {
    int n = 0, cx = 0, cy = 0;
    scanf("%d %d %d", &n, &cx, &cy);
    OverlayCheckerboard(int(pow(2.0, n)), cx, cy, 1, 1);
    sort(AllPoint.begin(), AllPoint.end(), SortAllPoint);
    while(AllPoint.empty() == false) {
        Point temp = AllPoint[0];
        printf("%d %d\n", temp.x, temp.y);
        AllPoint.erase(AllPoint.begin());
    }
}
