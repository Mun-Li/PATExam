#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 递归生成固定大小的子集（保证字典序）
 * @param n 序列最大值
 * @param k 当前要生成的子集大小
 * @param start 当前起始数字
 * @param temp 临时存储当前子集的数组
 * @param tempIndex 当前子集元素个数
 * @param result 存储所有子集的二维数组
 * @param colSizes 存储每个子集大小的数组
 * @param currentIndex 当前存储的子集索引
 */
void backtrack(int n, int k, int start, int* temp, int tempIndex, 
               int** result, int* colSizes, int* currentIndex) {
    // 子集已满，保存结果
    if (tempIndex == k) {
        // 分配内存并复制子集
        result[*currentIndex] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            result[*currentIndex][i] = temp[i];
        }
        colSizes[*currentIndex] = k;  // 记录子集大小
        (*currentIndex)++;  // 移动到下一个位置
        return;
    }
    
    // 从start开始选择数字（保证升序和字典序）
    for (int i = start; i <= n; i++) {
        temp[tempIndex] = i;  // 选择当前数字
        // 递归选择下一个数字（i+1保证升序）
        backtrack(n, k, i + 1, temp, tempIndex + 1, result, colSizes, currentIndex);
    }
}

/**
 * @brief 获取序列[1, n]的所有子集（按大小和字典序排序）
 * @param n 序列最大值
 * @param returnSize 返回的子集总数
 * @param returnColumnSizes 返回每个子集大小的数组
 * @return 二维数组，包含所有子集
 */
int** getSubsets(int n, int* returnSize, int** returnColumnSizes) {
    // 计算子集总数：2^n
    int total = 1 << n;
    *returnSize = total;
    
    // 分配结果数组
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    
    // 分配临时数组（最大长度为n）
    int* temp = (int*)malloc(n * sizeof(int));
    int currentIndex = 0;  // 当前存储位置索引
    
    // 按子集大小从0到n生成子集
    for (int k = 0; k <= n; k++) {
        backtrack(n, k, 1, temp, 0, result, *returnColumnSizes, &currentIndex);
    }
    
    free(temp);  // 释放临时数组
    return result;
}

/**
 * @brief 打印所有子集（测试函数）
 */
void printSubsets(int** subsets, int* colSizes, int n) {
    int total = 1 << n;
    for (int i = 0; i < total; i++) {
        printf("[");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d", subsets[i][j]);
            if (j < colSizes[i] - 1) printf(", ");
        }
        printf("]\n");
    }
}

int main() {
    int n = 3;
    int returnSize;
    int* returnColumnSizes = NULL;
    
    printf("Subsets of [1, %d] by size and lexicographical order:\n", n);
    int** subsets = getSubsets(n, &returnSize, &returnColumnSizes);
    printSubsets(subsets, returnColumnSizes, n);
    
    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(subsets[i]);
    }
    free(subsets);
    free(returnColumnSizes);
    
    return 0;
}