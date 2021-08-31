#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;
// ���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
void init_queue(DequeType *q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
void queue_print(DequeType *q)
{
	printf("Deque(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// ���� �Լ�
void add_rear(DequeType *q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� �Լ�
element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

	// ���� �Լ�
	element get_front(DequeType *q)
	{
		if (is_empty(q))
			error("ť�� ��������Դϴ�");
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	}
	void add_front(DequeType *q, element val)
	{
		if (is_full(q))
			error("ť�� ��ȭ�����Դϴ�");
		q->data[q->front] = val;
		q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}