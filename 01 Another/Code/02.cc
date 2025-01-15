// 比较秦九韶算法和直接算法的运行时间
// 多项式为：f(x)=2+0.3x+2.3x^2+3.6x^3+5.1x^4+6.2x^5
#include<stdio.h>
#include<math.h>
#include<time.h>
#define MaxTimes 10000000

// 秦九韶算法
double QinDuo(int n, double a[], double x)
{
	double sum = a[n];
	for (int i = n - 1; i >= 0; i--)
	{
		sum = sum * x + a[i];
	}
	return sum;
}

// 直接计算
double DirectDuo(int n, double a[], double x)
{
	double sum = a[0];
	for (int i = 1; i <= n; i++)
	{
		sum = sum + a[i] * pow(x, i);
	}
	return sum;
}


int main()
{
	// n为多项式的最高项次数
	// 用数组存储多项式的系数：
	int n = 5;
	double a[6] = { 2, 0.3, 2.3, 3.6, 5.1, 6.2 };
	double x = 0;
	printf("输入多项式x的取值：");
	scanf_s("%lf", &x);
	printf("秦九韶的计算方法：%lf\n", QinDuo(n, a, x));
	printf("  直接计算的方法：%lf\n", DirectDuo(n, a, x));

	// 开始评估两者所消耗的时间，为了对比更加明显，循环计算1000次
	// 最终的显示单位[s]
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < MaxTimes; i++)
	{
		QinDuo(n, a, x);
	}
	stop = clock();
	printf("秦九韶的计算方法的时间：%lfs\n", (double(stop) - double(start))/CLK_TCK);

	start = clock();
	for (int i = 0; i < MaxTimes; i++)
	{
		DirectDuo(n, a, x);
	}
	stop = clock();
	printf("  直接计算的方法的时间：%lfs\n", (double(stop) - double(start))/CLK_TCK);
	return 0;
}