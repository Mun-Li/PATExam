// 数组元素循环右移问题

#include<iostream>
using namespace std;

// 方法一：旁门左道
//int main()
//{
//    int a[100] = { 0 };
//    int N = 0, M = 0;
//    cin >> N;  // 数组的个数
//    cin >> M;  // 移动的个数
//    for (int i = 0; i < N; i++)
//    {
//        cin >> a[i];
//    }
//
//    // 考虑到M大于N的情况
//    M %= N;
//    for (int i = N - M; i < N; i++)
//    {
//        cout << a[i];
//        cout << ' ';
//    }
//    for (int i = 0; i < N - M; i++)
//    {
//        cout << a[i];
//        if (i < N - M - 1)
//            cout << ' ';
//    }
//    return 0;
//}


// 方法二：一个个的移动
//int main()
//{
//    int a[100] = { 0 };
//    int N = 0, M = 0, tem = 0;
//    cin >> N;  // 数组的个数
//    cin >> M;  // 移动的个数
//    for (int i = 0; i < N; i++)
//    {
//        cin >> a[i];
//    }
//
//    // 考虑到M大于N的情况
//    M %= N;
//
//    // 循环右移数组
//    for (int i = 0; i < M; i++)
//    {
//        tem = a[N - 1];
//        for (int j = 0; j < N - 1; j++)
//        {
//            a[N - 1 - j] = a[N - 2 - j];
//        }
//        a[0] = tem;
//    }
//
//    // 打印移动完后的数组
//    for (int i = 0; i < N; i++)
//    {
//        cout << a[i];
//        if (i < N - 1)
//        {
//            cout << ' ';
//        }
//    }
//    return 0;
//}


// 方法三：数组反转
void Swap(int* a, int* b)
{
	// 利用“异或”逻辑，进行交换
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
    int a[100] = { 0 };
    int N = 0, M = 0;
    cin >> N;  // 数组的个数
    cin >> M;  // 移动的个数
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    // 若M比N大
    M %= N;
    // 首先反转整个数组
    for (int i = 0, j = N - 1; i < j; i++, j--)
    {
        Swap(&a[i], &a[j]);
    }

    // 然后反转前M个
    for (int i = 0, j = M - 1; i < j; i++, j--)
    {
        Swap(&a[i], &a[j]);
    }

    // 在反转后N-M个
    for (int i = M, j = N - 1; i < j; i++, j--)
    {
        Swap(&a[i], &a[j]);
    }

    // 打印移动完后的数组
    for (int i = 0; i < N; i++)
    {
        cout << a[i];
        if (i < N - 1)
        {
            cout << ' ';
        }
    }

	return 0;
}
