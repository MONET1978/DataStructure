#include<stdio.h>
#include<stdlib.h>
#include <iostream>
typedef int ElemType;
typedef struct LNode {
	ElemType data; //数据域
	struct LNode* next; //指针域
}LNode, * LinkList;
// *LinkList为Lnode类型的指针
void InitLinkList_L(LinkList &L)//定义L是头指针，即函数传入一个LinkList类型的头指针L
{
	L = new LNode;
	L->next = NULL;
	printf("OK");
}
void DestroyList_L(LinkList& L) {//销毁
	LinkList p; while (L)
	{
		p = L;
		L = L->next; 
		delete p;//deletP意味着删除P所指向的内存空间元素。而且需要保留L以指向下一个节点
	}
	printf("OK");
}
//判断表是否为空
int ListEmpty(LinkList &L) { //若L为空表，则返回1，否则返回0 
	if (L->next) //L头指针->头结点->next=首元结点非空 
		return 0;
	else
		return 1;
}
//清空
void ClearList(LinkList& L) {
	// 将L重置为空表 
	LinkList p, q; p = L->next; //此时p和l同时指向第一个结点
	while (p) //没到表尾，即P所指链表存在
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL; //头结点指针域为空
}
//求表长
int ListLength_L(LinkList &L) {
		//返回L中数据元素个数
	LinkList p; p = L->next; //p指向第一个结点
	int i = 0;
	while (p) {//遍历单链表,统计结点数
		i++; 
		p = p->next;
	}
	return i;
}
//获取线性表L中的某个数据元素的内容
void GetElem_L(LinkList L, int i, ElemType& e) {
	LinkList p = L->next; 
	int j = 1; //初始化
	while (p && j < i) { //向后扫描，直到p指向第i个元素或p为空
		p = p->next; 
		++j;
	}
	if (!p || j > i)
		printf("ERROR"); //第i个元素不存在
	else e = p->data; //取第i个元素
	printf("%d",e);
}//GetElem_L
//在线性表L中查找值为e的数据元素
int LocateELem_L(LinkList L, ElemType e) {
	LinkList p = L->next; int j = 1;
	while (p && p->data != e)
	{
		p = p->next; 
		j++;
	}
	if (p) return *p,j;
	else return 0;//返回L中值为e的数据元素的位置序号，查找失败返回0
}
//在L中第i个元素之前插入数据元素e
int ListInsert_L(LinkList& L, int i, ElemType e) {
	LinkList p = L; 
	int j = 0;
	while (p && j < i - 1) { p = p->next; ++j; } //寻找第i−1个结点
	if (!p || j > i - 1)
		printf("ERROR"); //i大于表长 + 1或者小于1
	LinkList s = new LNode; //生成新结点s
	s->data = e; //将结点s的数据域置为e
	s->next = p->next; //将结点s插入L中
	p->next = s;
}//ListInsert_L
//将线性表L中第i个数据元素删除
void ListDelete_L(LinkList& L, int i, ElemType& e) {
	LinkList p = L; int j = 0;
	while (p->next && j < i - 1) { //寻找第i个结点，并令p指向其前驱
		p = p->next; 
		++j;
	}
	if (!(p->next) || j > i - 1) 
		printf("ERROR");  //删除位置不合理
	LinkList q = p->next; //临时保存被删结点的地址以备释放
	p->next = q->next; //改变删除结点前驱结点的指针域
	e = q->data; //保存删除结点的数据域
	delete q; //释放删除结点的空间
}//ListDelete_L
//前插
void CreateList_F(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL; //先建立一个带头结点的单链表
	for (int i = n; i > 0; --i) {
		LinkList p = new LNode; //生成新结点
		scanf_s("") >> p->data; //输入元素值
		p->next = L->next; L->next = p; //插入到表头
	}
}//CreateList_F
//后插
void CreateList_L(LinkList& L, int n) {
	//正位序输入n个元素的值，建立带表头结点的单链表L
	L = new LNode;
	L->next = NULL;
	LinkList r = L; //尾指针r指向头结点
	for (int i = 0; i < n; ++i) {
		LinkList p = new LNode; //生成新结点
		scanf_s("") >> p->data; //输入元素值
		p->next = NULL;
		r->next = p; //插入到表尾
		r = p; //r指向新的尾结点
	}
}//CreateList_L
