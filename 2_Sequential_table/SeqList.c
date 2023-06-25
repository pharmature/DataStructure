#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLInit(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLDestroy(SL* ps)
{
	assert(ps);
	if (ps->a != NULL)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = ps->capacity = 0;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//扩容
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->size] = x;
	ps->size++;
}


void SLPopBack(SL* ps)
{
	assert(ps);
	//温柔的检查
	//if (ps->size == 0)
	//{
	//	return;
	//}

	//暴力的检查
	assert(ps->size > 0);

	//ps->a[ps->size - 1] = 0;
	ps->size--;
}



