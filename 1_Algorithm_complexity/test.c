#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>


//时间复杂度

//1.小时的数字OJ
//数组num包含从0到n的所有整数，但其中缺了一个
//编写代码找出那个缺失的整数，在O(n)时间内完成

//思路1：求和相减
//(n+1)*n/2-(数组中所有相加)
//时间复杂度 - O(n)
//空间复杂度 - O(1)

int missingNumber(int* nums,int numsize)
{
	int N = numsize;
	int ret = N * (N + 1) / 2;
	for (int i = 0; i < numsize; ++i)
	{
		ret -= nums[i];
	}
	return ret;
}

//思路2：qsort排序
//时间复杂度 - O(nlogn)
//空间复杂度 - O(logn)

//思路3：异或
//时间复杂度 - O(n)
//空间复杂度 - O(1)

int missingNumber(int* nums, int numsize)
{
	int N = numsize;
	int x = 0;//缺失值
	for (int i = 0; i < numsize; ++i)
	{
		x ^= nums[i];
	}

	for (size_t j = 0; j < N + 1; ++j)
	{
		x ^= j;
	}
	return x;
}


//2.旋转数组OJ
//思路1：旋转k次
//时间复杂度 - O(N)
//空间复杂度 - O(1)
void rotate(int* nums, int numsize, int k)
{
	while (k--)
	{
		int ret = nums[numsize - 1];
		for (int i = numsize - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = ret;
	}
}

//思路2：以空间换时间
//时间复杂度 - O(N)
//空间复杂度 - O(N)
void rotate(int* nums, int numsize, int k)
{
	k = k % numsize;
	//变长数组 - C99
	int tmp[numsize];

	//后k个拷贝到前面
	int j = 0;
	for (int i = numsize - k; i < numsize; ++i)
	{
		tmp[j] = nums[i];
		++j;
	}

	//前N-K个拷贝到后面
	for (int i = 0; i < numsize-k; ++i)
	{
		tmp[j] = nums[i];
		++j;
	}

	//拷贝回去
	for (int i = 0; i < numsize; ++i)
	{
		nums[i] = tmp[i];
	}
}

//思路3：三步翻转
//前n-k个逆置
//后k个逆置
//整体逆置

void reverse(int* a, int begin, int end)
{
	while (begin < end)
	{
		int tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;

		++begin;
		--end;
	}
}
void rotate(int* nums, int numsize, int k)
{
	k %= numsize;

	reverse(nums, 0, numsize - k - 1);
	reverse(nums, numsize - k, numsize - 1);
	reverse(nums, 0, numsize - 1);
}


//斐波那契数列的时间复杂度
//O(2^N)
//O(N) - 优化为迭代算法
long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}
//空间复杂度O(N)

//时间是累计的一去不复返
//空间是可以重复利用的






