#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef int element; // ����� Ÿ��

typedef struct QueueNode { // ť�� ����� Ÿ��
	element data; 
	struct QueueNode *link;
} QueueNode;

typedef struct { // ť ADT ����
	QueueNode *front, *rear;
} LinkedQueueType;

void init(LinkedQueueType *q) {
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType *q)
{
	return (q->front == NULL);
}

// ���� �Լ�
void enqueue(LinkedQueueType *q, element data)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	temp->data = data; // ������ ����
	temp->link = NULL; // ��ũ �ʵ带 NULL
	if (is_empty(q)) { // ť�� �����̸�
		q->front = temp;
		q->rear = temp;
	}
	else { // ť�� ������ �ƴϸ�
		q->rear->link = temp; // ������ �߿�
		q->rear = temp;
	}
}

element dequeue(LinkedQueueType *q)
{
	QueueNode *temp = q->front;
	element data;
	if (is_empty(q)) { // �������
		fprintf(stderr, "ť�� �������\n");
		exit(1);
	}
	else {
		data = temp->data; // �����͸� ������.
		q->front = q->front->link; // front�� �������
		if (q->front == NULL) // ���� ����
			q->rear = NULL;
		free(temp); // �����޸� ����
		return data; // ������ ��ȯ
	}
}

int main() {

	LinkedQueueType q;
	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("%d\n",dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));

	return 0;
}