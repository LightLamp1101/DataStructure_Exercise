// �迭�� �̿��� ����

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define MAX_STACK_SIZE 100		// ���� �ִ� ũ��
typedef int element;						// �������� �ڷ���
element stack[MAX_STACK_SIZE];	// 1���� �迭
int top = -1;

int is_empty();
int is_full();
void push(element item);
element pop();

int main(void) {
	push(1);
	push(2);
	push(3);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;
}


// ���� ���� ����
int is_empty() {
	return (top == -1);
}

// ��ȭ ���� ����
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

// ���� �Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		return stack[top--];
	}
}


/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // ������ �ִ� ũ��
typedef int element; // �������� �ڷ���
element stack[MAX_STACK_SIZE]; // 1���� �迭
int top = -1;
// ���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
// ���� �Լ�
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}
*/