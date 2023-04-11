#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��̬˳��� -- ��̫ʵ��
//NС�˲����ã�N���˿����˷�
//#define N 10
//typedef int SLDataType;
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;//��¼�洢���ٸ���Ч����
//}SL;
//
////SLT����
////void SeqListInit(SL s);
//void SLInit(SL s);
//void SLPushBack(SL s, int x); //β��


//��̬˳��� -- �������ռ�

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a; //ָ��̬���ٵ�����
	int size;      //��Ч���ݸ���
	int capacity;  //�����ռ�Ĵ�С
}SL;

void SLPrint(SL* ps);

void SLInit(SL* ps);
void SLDestroy(SL* ps);

//β��βɾ
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
