#include <iostream>  //�ļ����������
#include <string>
#include <fstream>
#include "stdlib.h "

#define MAXQSIZE 20
#define OK 1
#define ERROR 0
typedef string QElemType;
typedef string SElemType;
typedef int Status; //����״ֵ̬����

typedef struct {
	QElemType* base;//��ʼ��ʱ��̬����洢�ռ�
	int front;//ͷָ��
	int rear;//βָ��
	int number;//����
}SqQueue, *SqQueuer;

//�Դ������ݽṹ
typedef struct LNode {
	string keshi;
	struct LNode* next;
	//��������
	SqQueue doctor[20];
}Hospital,*Hospitalr;

//��ʼ��ҽԺ���ݽṹ
Status InitHospital(Hospitalr& H) {
	H = new LNode;
	H->next = NULL;
	return OK;
}

//ѭ�����еĳ�ʼ��
void InitQueue(SqQueue& Q) {
	//����һ���ն���Q
	Q.number = 0;
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0; //ͷָ���βָ����Ϊ�㣬����Ϊ��
}

void CreateList_R(Hospitalr& H, int n) {
    //β�巨����12���ռ���ҵ�ҽԺ
	H = new LNode; 
	Hospitalr node = NULL; 
	Hospitalr end = NULL;
	H->next = NULL;
	end = H;
	for (int i = 0; i < n; i++) {
		node = new LNode;
		node->keshi = "";
		//end�����ƶ���ʼ��ָ�����һ�����
		end->next = node;
		end = node;
		//20�����ж�Ӧ20��ҽ����ÿ��ҽ���������Ŷ�
		for (int j = 0; j < MAXQSIZE; j++) {
			InitQueue(end->doctor[j]);
		}
	}
	end->next = NULL;
}




//��ѭ�����еĳ���
Status QueueLength(SqQueue Q){
	//����Q��Ԫ�ظ����������еĳ���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//�㷨3.13��ѭ�����е����
Status EnQueue(SqQueue& Q, QElemType e){
	//����Ԫ��eΪQ���µĶ�βԪ��
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //����
		return ERROR;
	Q.base[Q.rear] = e; //��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; //��βָ���1
	Q.number++;
	return OK;
}

//ѭ�����еĳ���
Status DeQueue(SqQueue& Q, QElemType& e){
	//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if (Q.front == Q.rear)
		return ERROR; //�ӿ�
	e = Q.base[Q.front]; //�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE; //��ͷָ���1
	Q.number--;
	return OK;
}

//ȡѭ�����еĶ�ͷԪ��
SElemType GetHead(SqQueue Q) {
	//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if (Q.front != Q.rear) //���зǿ�
		return Q.base[Q.front]; //���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}

void Destroy(Hospital*& H) {
	Hospital* p;
	p = H;
	free(p->doctor);
}