#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType a[MAXSIZE];
	int length;
}SqList;
SqList b;
void create_list(SqList* L);
void out_list(SqList L);
void insert_sq(SqList* L, int i, ElemType e);
ElemType delete_sq(SqList* L, int i);
int locat_sq(SqList L, ElemType e);

int main()
{
	int k, i;
	ElemType e, x;
	do
	{
		printf("\n\n\n");
		printf("\n 1.建立线性表");
		printf("\n 2.在i位置上插入元素e");
		printf("\n 3.删除第i个元素，返回其值");
		printf("\n 4.查找值为e的元素");
		printf("\n 5.结束程序运行");
		printf("\n=======================");
		printf("\n 请输入你的选择(1,2,3,4,5)");

		scanf_s("%d", &k);
		switch (k)
		{
		case 1:
		{
			create_list(&b);
			out_list(b);
		}break;
		case 2:
		{
			printf("\n i,e=?");
			scanf_s("%d,%d", &i, &e);
			insert_sq(&b, i, e);
			out_list(b);
		}break;
		case 3:
		{
			printf("\n i=?");
			scanf_s("%d", &i);
			x = delete_sq(&b, i);
			out_list(b);
			printf("\n x=%d", x);
		}break;
		case 4:
		{
			int loc;
			printf("\n e=?");
			scanf_s("%d", &e);
			loc = locat_sq(b, e);
			if (loc == -1)
				printf("\b 未找到 &d", loc);
			else printf("\n 已找到，元素位置是%d", loc);
		}break;
		case 5:
		{
			return 0;
		}
		}
	} while (k < 6);
}

void create_list(SqList* L)
{
	printf("\n n=?");
	scanf_s("%d", &L->length);
	for (int i = 0; i < L->length; i++)
	{
		printf("\n data %d=?", i);
		scanf_s("%d", &(L->a[i]));
	}
}

void out_list(SqList L)
{
	printf("\n");
	for (int i = 0; i <= L.length; i++)
	{
		printf("%10d", L.a[i]);
	}
	printf("\n");
}

void insert_sq(SqList* L, int i, ElemType e)
{
	int j;
	if (L->length == MAXSIZE)
		printf("\n overflow!");
	else if ((i < 1) || (i > L->length + 1))
		printf("\n error i!");
	else
	{
		for (j = L->length - 1; j >= i - 1; j--)
		L->a[j + 1] = L->a[j];
		L->a[i - 1] = e;
		++L->length;
	}
}

ElemType delete_sq(SqList* L, int i)
{
	ElemType x;
	int j;
	if ((i < 1) || (i > L->length))
	{
		printf("\n error i!");
		x = -1;
	}
	else
	{
		x = L->a[i - 1];
		for (j = i; j < L->length; j++)
			L->a[j - 1] = L->a[j];
		--L->length;
	}return(x);
}

int locat_sq(SqList L, ElemType e)
{
	int i;
	for (i = 0; i < L.length; i++)
		if (L.a[i] == e) return i + 1;
	return 0;
}
