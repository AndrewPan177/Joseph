// Joseph.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
using namespace std;

typedef struct LNode {
	ElemType No;
	ElemType Password;
	struct LNode *next;
	//struct LNode *prior;
}LNode, *LinkList;

//��������ѭ������
void CreateList(LinkList &L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = L;
	LinkList p;
	for (int i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));
		cin >> p->Password;
		p->No = i;
		p->next = L->next;
		L->next = p;
	}
}

//ɾ���� i ��Ԫ�أ����� e ���ݳ���
ElemType DeleteList(LinkList &L, int i) {//i = 4
	LinkList p, q;
	p = L; int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)cout << "Error!" << endl;
	q = p->next;
	p->next = q->next;
	int e = q->Password;
	free(q);
	return e;
}

//˳���ӡѭ������
void PrnList(LinkList L, int n) {
	LinkList p;
	p = L;

	p = p->next;
	for (int i = 0; i < n; i++) {
		cout << p->No << "-" << p->Password << " ";
		if (p->next == L)
			p = p->next->next;
		else p = p->next;
	}
	cout << endl;
}

//Լɪ��
void Joseph(LinkList &L, int n, int m) {
	LinkList p, q;									//p���ڱ���L��q���ڻ��q��ǰ��
	int num = 1, i = 0, couter = 0, k = 0;
	int nH = n;
	int *temp = new int[n];
	//int *temp = (int*)malloc(sizeof(int));		�˴�ֻ����new��malloc�����
	p = L;
	p = p->next;
	while (L->next != L) {							//��ʼp��L�ı���
		if (num - 1 == m) {							//pָ��Ŀ��ڵ����һ�ڵ�
			q = L;// qΪ pǰ��

			if (q->next == p) {						//q��ʼ���p��ǰ��
				while (q->next && k < n) {
					q = q->next;
					k++;
				}
			}
			else {
				while (q->next != p) 
					q = q->next;
			}
			k = 0;
			
			temp[i] = q->No;						//����ÿһ�εĽ�����ں͵�ǰ���Ƚ�
			for (int j = 0; j < i; j++) {
				if (temp[j] < q->No)
					couter++;
			}
			m = DeleteList(L, q->No - couter);
			num = 1;	couter = 0;
			n--; i++;
		}

		if (p->next == L)							//p��ʼ����ƶ�
			p = p->next->next;
		else p = p->next;

		num++;
	}
	cout << "Joseph��";
	i = 0;
	while (i<nH) {
		cout << temp[i]<<" ";
		i++;
	}

	delete[]temp;
	cout << endl;
}

int main()
{
	LinkList L;
	int n = 7, m = 20;
	cout << "Input the password of everyone: " << endl;
	L = (LinkList)malloc(sizeof(LNode));

	CreateList(L, n);
	Joseph(L, n, m);

	cout << endl;
    return 0;
}
