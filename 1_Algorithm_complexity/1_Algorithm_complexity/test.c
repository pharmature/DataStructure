#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>


//ʱ�临�Ӷ�

//1.Сʱ������OJ
//����num������0��n������������������ȱ��һ��
//��д�����ҳ��Ǹ�ȱʧ����������O(n)ʱ�������

//˼·1��������
//(n+1)*n/2-(�������������)
//ʱ�临�Ӷ� - O(n)
//�ռ临�Ӷ� - O(1)

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

//˼·2��qsort����
//ʱ�临�Ӷ� - O(nlogn)
//�ռ临�Ӷ� - O(logn)

//˼·3�����
//ʱ�临�Ӷ� - O(n)
//�ռ临�Ӷ� - O(1)

int missingNumber(int* nums, int numsize)
{
	int N = numsize;
	int x = 0;//ȱʧֵ
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


//2.��ת����OJ
//˼·1����תk��
//ʱ�临�Ӷ� - O(N)
//�ռ临�Ӷ� - O(1)
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

//˼·2���Կռ任ʱ��
//ʱ�临�Ӷ� - O(N)
//�ռ临�Ӷ� - O(N)
void rotate(int* nums, int numsize, int k)
{
	k = k % numsize;
	//�䳤���� - C99
	int tmp[numsize];

	//��k��������ǰ��
	int j = 0;
	for (int i = numsize - k; i < numsize; ++i)
	{
		tmp[j] = nums[i];
		++j;
	}

	//ǰN-K������������
	for (int i = 0; i < numsize-k; ++i)
	{
		tmp[j] = nums[i];
		++j;
	}

	//������ȥ
	for (int i = 0; i < numsize; ++i)
	{
		nums[i] = tmp[i];
	}
}

//˼·3��������ת
//ǰn-k������
//��k������
//��������

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


//쳲��������е�ʱ�临�Ӷ�
//O(2^N)
//O(N) - �Ż�Ϊ�����㷨
long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}
//�ռ临�Ӷ�O(N)

//ʱ�����ۼƵ�һȥ������
//�ռ��ǿ����ظ����õ�






