#include <iostream>  //文件输入输出流
#include <string>
#include <fstream>
#include "stdlib.h "

#define MAXQSIZE 20
#define OK 1
#define ERROR 0
typedef string QElemType;
typedef string SElemType;
typedef int Status; //返回状态值类型

typedef struct {
	QElemType* base;//初始化时动态分配存储空间
	int front;//头指针
	int rear;//尾指针
	int number;//号码
}SqQueue, *SqQueuer;

//自创的数据结构
typedef struct LNode {
	string keshi;
	struct LNode* next;
	//队列数组
	SqQueue doctor[20];
}Hospital,*Hospitalr;

//初始化医院数据结构
Status InitHospital(Hospitalr& H) {
	H = new LNode;
	H->next = NULL;
	return OK;
}

//循环队列的初始化
void InitQueue(SqQueue& Q) {
	//构造一个空队列Q
	Q.number = 0;
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0; //头指针和尾指针置为零，队列为空
}

void CreateList_R(Hospitalr& H, int n) {
    //尾插法创建12个空间科室的医院
	H = new LNode; 
	Hospitalr node = NULL; 
	Hospitalr end = NULL;
	H->next = NULL;
	end = H;
	for (int i = 0; i < n; i++) {
		node = new LNode;
		node->keshi = "";
		//end向右移动，始终指向最后一个结点
		end->next = node;
		end = node;
		//20个队列对应20个医生，每个医生都可以排队
		for (int j = 0; j < MAXQSIZE; j++) {
			InitQueue(end->doctor[j]);
		}
	}
	end->next = NULL;
}




//求循环队列的长度
Status QueueLength(SqQueue Q){
	//返回Q的元素个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//算法3.13　循环队列的入队
Status EnQueue(SqQueue& Q, QElemType e){
	//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //队满
		return ERROR;
	Q.base[Q.rear] = e; //新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针加1
	Q.number++;
	return OK;
}

//循环队列的出队
Status DeQueue(SqQueue& Q, QElemType& e){
	//删除Q的队头元素，用e返回其值
	if (Q.front == Q.rear)
		return ERROR; //队空
	e = Q.base[Q.front]; //保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; //队头指针加1
	Q.number--;
	return OK;
}

//取循环队列的队头元素
SElemType GetHead(SqQueue Q) {
	//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.base[Q.front]; //返回队头元素的值，队头指针不变
}

void Destroy(Hospital*& H) {
	Hospital* p;
	p = H;
	free(p->doctor);
}