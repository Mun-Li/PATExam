// 用两种不同的方法，输出0-N的数字
// MMM, 2023.01.09
#include<stdio.h>


// 方法一：循环输出
void printN(int N)
{
	for (int i = 0; i <= N; i++)
	{
		printf("%d\n", i);
	}
}

// 方法二：递归输出
// 看起来代码比较简洁，但是会消耗较大的空间
void IrPrintN(int N)
{
	if (N >= 0)
	{
		IrPrintN(N-1);
		printf("%d\n", N);
	}
}


int main()
{
	int N = 0;
	printf("Please enter N = ");
	scanf_s("%d", &N);
	printf("循环输出的结果\n");
	printN(N);
	printf("递归输出的结果\n");
	IrPrintN(N);
	return 0;
}