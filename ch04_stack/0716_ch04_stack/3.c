// ����ü�� �̿��� ����

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef int element;
typedef struct {
	element *data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);


int main(void)
{
	StackType *s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	free(s);
	free(s->data);
}


// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (StackType *)malloc(sizeof(StackType));
}
// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (s->capacity - 1));
}

// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (StackType *)realloc(s->data, s->capacity*sizeof(StackType));
	}
	s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

