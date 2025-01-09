// 最大子列和问题，设计多个算法来解决，并比较复杂度
// 其实这里还隐藏一个更复杂的问题，如何把这个最大子列给提取出来
// 测试一下每个函数大概的运行时间


#include<stdio.h>
#include<time.h>


// 数组的个数
#define N 13
// 求三个数的最大值
#define Max3(A, B, C) (A > B ? (A > C ? A : C) : (B > C ? B : C))


// 方法一，直接进行遍历、穷举法
// 时间复杂度为O(n^3)
int MaxSubseqSum1(int List[])
{
	int MaxSum, ThisSum;
	MaxSum = 0;
	for (int i = 0; i < N; i++)/*控制子列首部*/
	{
		for (int j = i; j < N; j++)/*控制子列尾部*/
		{
			ThisSum = 0;/*初始化子列的每个数据*/
			for (int k = i; k <= j; k++)
			{
				ThisSum += List[k];
			}
			if (ThisSum > MaxSum)/*更新最大子列和*/
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}


// 方法二，在计算子列的时候，不用每次都清零
// 时间复杂度O(n^2)
int MaxSubseqSum2(int List[])
{
	int MaxSum, ThisSum;
	MaxSum = 0;
	for (int i = 0; i < N; i++)/*控制子列首部*/
	{
		ThisSum = 0;/*初始化子列的每个数据*/
		for (int j = i; j < N; j++)/*控制子列尾部*/
		{
			ThisSum += List[j];
			if (ThisSum > MaxSum)/*更新最大子列和*/
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}


// 方法二的另一种表现形式
int MaxSubseqSum2_2(int List[])
{
	int MaxSum = 0, ThisSum = 0, Sum[N] = { 0 };
	Sum[0] = List[0];
	for (int i = 1; i < N; i++)/*先求每个子列的和*/
	{
		Sum[i] = Sum[i-1] + List[i];
	}
	for (int i = 0; i < N; i++)
	{
		ThisSum = Sum[i];
		for (int j = 0; j <= i; j++)/*从子列的首部逐渐的递减*/
		{
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
			ThisSum -= List[j];/*这里最后一步就为0了*/
		}
	}
	return MaxSum;
}


// 方法三：分而治之，将大问题划分为小问题，进而迭代解决
// 码量有点点多（你不会就坚持不下去了吧？）
// 时间复杂度O(nlogn)
int HalfSlove(int List[], int Left, int Right)
{
	// 存放左右子问题的解
	int MaxLeftSum = 0, MaxRightSum = 0;
	// 存放跨分解线的的解
	int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;
	int LeftBorderSum = 0, RightBorderSum = 0;
	int Center = 0;
	Center = (Left + Right) / 2;

	// 递归的终止条件
	// 此时子列就只有一个数值
	if (Left == Right)
	{
		if (List[Left] <= 0)
		{
			return 0;
		}
		else
		{
			return List[Left];
		}
	}

	// 开始进行分的过程，递归的意义究竟是什么
	// 求左列的最大值
	MaxLeftSum = HalfSlove(List, Left, Center);

	// 求右列的最大值
	MaxRightSum = HalfSlove(List, Center + 1, Right);

	// 求分界线的最大值
	for (int i = Center; i >= Left; i--)
	{
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}
	for (int i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}

	// 把分开的问题合起来
	// 要比较的都是最大值，这里调试了很久
	return Max3(MaxLeftSum, MaxRightSum, (MaxRightBorderSum + MaxLeftBorderSum));
}


// 保持和其它函数一样的格式
int MaxSubseqSum3(int List[])
{
	return HalfSlove(List, 0, N - 1);
}


// 方法四：在线处理，"贪心算法"
// 当子列的和为负数的时候, 直接就抛弃，如果大于当前的最大值就更新
int MaxSubseqSum4(int List[])
{
	int ThisSum = 0, MaxSum = 0;
	for (int i = 0; i < N; i++)
	{
		ThisSum += List[i];
		if (ThisSum > MaxSum)/*判断最大值是否更新*/
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)/*判断当前的子列是否小于0*/
		{
			ThisSum = 0;
		}
	}
	return MaxSum;
}


int main()
{
	int List[N] = { 2,-5,3,1,4,-2,5,-1,-2,6,3,-1,-1};
	int MaxSum = 0;
	MaxSum = MaxSubseqSum1(List);
	printf("1最大的子列和为：%d\n", MaxSum);
	MaxSum = MaxSubseqSum2(List);
	printf("2最大的子列和为：%d\n", MaxSum);
	MaxSum = MaxSubseqSum2_2(List);
	printf("2_2最大的子列和为：%d\n", MaxSum);
	MaxSum = MaxSubseqSum3(List);
	printf("3最大的子列和为：%d\n", MaxSum);
	MaxSum = MaxSubseqSum4(List);
	printf("4最大的子列和为：%d\n", MaxSum);
	return 0;
}

