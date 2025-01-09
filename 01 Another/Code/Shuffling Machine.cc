// Author: MMM
// https://pintia.cn/problem-sets/17/exam/problems/264
// 重复洗牌
// 题目的要求都有点读不懂了

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n = 0;
	string shuff[54];
	string temp_shuff[54];
	int order[54] = { 0 };

	// 读入洗牌的次数
	cin >> n;

	// 读入洗牌的次序
	for (int i = 0; i < 54; ++i)
	{
		cin >> order[i];
	}

	// 牌的初始位置
	for (int i = 0; i < 52; i++)
	{
		int j = i / 13;
		if (j == 0)
			shuff[i] += 'S';
		else if (j == 1)
			shuff[i] += 'H';
		else if (j == 2)
			shuff[i] += 'C';
		else
			shuff[i] += 'D';
		// 这个函数有点不太知道
		shuff[i] += to_string(i % 13 + 1);
	}
	shuff[52] = "J1";
	shuff[53] = "J2";


	for (int i = 0; i < n; i++)
	{
		// 根据要求的次序，调整牌的次序
		// 外循环为调整的次数
		for (int i = 0; i < 54; i++)
		{
			temp_shuff[order[i] - 1] = shuff[i];
		}
		// 更新牌的次序
		for (int i = 0; i < 54; i++)
		{
			shuff[i] = temp_shuff[i];
		}
	}

	for (int i = 0; i < 54; i++)
	{
		cout << shuff[i];
		cout << ' ';
	}
	return 0;
}
