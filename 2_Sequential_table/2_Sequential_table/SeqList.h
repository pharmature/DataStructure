#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//静态顺序表 -- 不太实用
//N小了不够用，N大了可能浪费
//#define N 10
//typedef int SLDataType;
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;//记录存储多少个有效数据
//}SL;
//
////SLT命名
////void SeqListInit(SL s);
//void SLInit(SL s);
//void SLPushBack(SL s, int x); //尾插


//动态顺序表 -- 按需扩空间

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a; //指向动态开辟的数组
	int size;      //有效数据个数
	int capacity;  //容量空间的大小
}SL;

void SLPrint(SL* ps);

void SLInit(SL* ps);
void SLDestroy(SL* ps);

//尾插尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
