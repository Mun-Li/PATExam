// Author:MMM
// https://pintia.cn/problem-sets/17/exam/problems/263

#include<iostream>
using namespace std;

int main()
{
	// 读入了20位以下的数据
	char a[21] = { 0 };
	char b[21] = { 0 };
	int visa[10] = { 0 };
	int visb[10] = { 0 };
	int n = 0, flag = 0;
	cin >> a;

	// 处理数据，每位转化为十进制
	// 并且数据翻倍
	for (int i = 0; a[i] != '\0'; i++)
	{
		a[i] -= '0';
		visa[int(a[i])]++;  // 记录a中每个数字出现的次数
		b[i] = 2 * a[i];
		n++;  // 记录输入数据的长度
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (b[i] > 9)
		{
			b[i] -= 10;
			b[i - 1] += 1;
		}
		visb[int(b[i])]++;  // 记录b中每个数字出现的次数
	}

	// 对比两个数据是否由相同的数字组成
	if (b[0] > 9)
	{
		cout << "No" << endl;
	}
	else
	{
		visb[int(b[0])]++;  // 记录b中每个数字出现的次数

		// 然后根据visa和visb判断两个数据
		for (flag = 0; flag < 10; flag++)
		{
			if (visa[flag] != visb[flag])
			{
				break;
			}
		}

		if (flag == 10)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	// 无论满足要求都要输出翻倍的结果
	for (int i = 0; i < n; i++)
	{
		cout << int(b[i]);
	}
	return 0;
}
