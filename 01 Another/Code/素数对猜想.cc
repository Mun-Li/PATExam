// 素数对猜想
#include<iostream>
#include<math.h>

using namespace std;


int main()
{
	int N = 0, Sum = 0;  // 总的个数
	int k = 0, j = 0;  // 数组标识
	double temp = 0;  // 临时变量
	int Prime[2] = { 0 };  // 相邻的两个素数
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		// 判断是否为素数
		temp = sqrt(i);
		for (j = 2; j <= temp; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > temp)  // 为素数
		{
			Prime[(k % 2)] = i;
			k++;
			if (abs(Prime[0] - Prime[1]) == 2)
			{
				Sum++;
			}
		}
	}
	cout << Sum;
	return 0;
}