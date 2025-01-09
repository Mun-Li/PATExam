// 打印沙漏的题目
#include<iostream>
using namespace std;

int main()
{
	int N = 0;  // 符号的个数
	int Sum = 0, Ele = 0, i = 0, j = 0, k = 0;
	char a;
	cin >> N >> a;
	if (N == 0)
	{
		cout << 0;
		return 0;
	}
	// 计算沙漏的行数
	for (j = 1; Sum <= N; j++)
	{
		Sum = 2 * j * j - 1;
	}
	j -= 2;
	Ele = N - (2*j*j - 1);  // 剩余的符号数

	// 开始画沙漏
	k = 0;  // 左边空格数
	// 上沙漏
	for (i = j; i > 0; i--)
	{
		for (int m = 0; m < k; m++)
		{
			cout << ' ';
		}
		for (int m = 0; m < 2 * i - 1; m++)
		{
			cout << a;
		}
		cout << endl;
		k++;
	}
	k -= 2;
	// 下沙漏
	for (i = 2; i <= j; i++)
	{
		for (int m = 0; m < k; m++)
		{
			cout << ' ';
		}
		for (int m = 0; m < 2 * i - 1; m++)
		{
			cout << a;
		}
		cout << endl;
		k--;
	}
	cout << Ele;
	return 0;
}