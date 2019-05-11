#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK    1
#define SIZE  11
typedef struct list
{
	int data[SIZE];
	int front;
	int rear;
}list;

int Initlist(list *q)
{
	if (q == NULL)
	{
		return ERROR;
	}
	q->front = 0;
	q->rear = 0;
	return OK;
}
int scanf_1(list *q)
{
	int data = 0;
	for (data = 18001; data < 18011; data++)
	{
		{
			if (q == NULL || q->front == (q->rear + 1) % SIZE)
			{
				return ERROR;
			}
			q->rear = (q->rear + 1) % SIZE;
			q->data[q->rear] = data;
		}
	}
	return OK;
}

int Delete(list *q, int *x)
{
	if (q == NULL || q->rear == q->front)
	{
		return ERROR;
	}
	q->front = (q->front + 1) % SIZE;
	*x = q->data[q->front];
	return OK;
}
int GetFront(list *q, int *x)
{
	if (q == NULL)
	{
		return ERROR;
	}
	int data = (q->front + 1) % SIZE;
	*x = q->data[data];
	return OK;
}
void print(list q)
{
	if (q.rear == q.front)
	{
		printf("����Ϊ��\n");
		return;
	}
	int begin = (q.front + 1) % SIZE;
	int beyond = (q.rear + 1) % SIZE;
	int i;
	for (i = begin; i != beyond; i = (i + 1) % SIZE)
	{                                         
		printf("%d ", q.data[i]);
	}
	printf("\n");
}

int main()
{
	list q;
	Initlist(&q);
	scanf_1(&q);
	printf("��ǰ����������;");
	print(q);
	int front;
	int i = 9;;
	int x;
	while (i)
	{
		printf("��������;");
		Delete(&q, &x);
		printf("%-4d", x);
		printf("\n");
		printf("��ǰ����������;");
		print(q);
		printf("��%d����ȥ2�����Ҿ���\n", q.data[q.front + 1]);
		i--;
		printf("\n");
	}
	system("pause");
	return 0;
}

