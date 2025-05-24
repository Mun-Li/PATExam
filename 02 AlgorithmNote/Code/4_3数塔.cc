#include<iostream>

#define MAX_N 20

// TODO: 下面这个宏定义在编译前是会直接展开的
// 因此，加上随外围的括号
#define MAX_FUN(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int n = 0;
int counting_tower[MAX_N][MAX_N] = {0};  // 数塔

int FindMaxPath(int i, int j) {
    if(i == n-1) {                       // 如果是最后一排的，直接是该数字
        return counting_tower[i][j];
    } else if ((i >= 0) &&               // 否者，就是当前数加上 max(左, 右)
               (i < n-1)) {
        int a = FindMaxPath(i + 1, j);
        int b = FindMaxPath(i + 1, j + 1);
        
        return counting_tower[i][j] + MAX_FUN(a, b);
    }
}

int main() {

    /* 输入数塔 */
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &counting_tower[i][j]);
        }
    }
    
    /* 寻找最大路径值 */
    printf("%d", FindMaxPath(0, 0));
    return 0;
}

/**
 * @brief:     官方题解
 * @note:
 */
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// const int MAXN = 20 + 1;
// int n, a[MAXN][MAXN];
// // 计算以第i行第j列作为塔顶时到达塔底的路径最大值
// int getMax(int i, int j) {
//     if (i == n) {          // 如果是最下面一排
//         return a[n][j];    // 那么这个数塔只有一个元素a[n][j]，该元素就是最大值
//     } else {               // 如果不是最下面一排
//         // 分别计算以左下角和右下角元素作为塔顶时的结果，较大的加上塔顶元素即为结果
//         return max(getMax(i + 1, j), getMax(i + 1, j + 1)) + a[i][j];
//     }
// }
// int main() {
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) {       // 输入数塔
//         for (int j = 1; j <= i; j++) {
//             scanf("%d", &a[i][j]);
//         }
//     }
//     printf("%d\n", getMax(1, 1));    // 以第1行第1列的元素作为塔顶时为最终结果
//     return 0;
// }