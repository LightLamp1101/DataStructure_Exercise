#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

// 연결 리스트 헤더
typedef struct ListType {
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)mall
}

//plist는 연결리스트의 헤더를 가리킴 coef는 계수
//expon은 지수
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	if (temp == NULL)error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3)
	}
	return head; // 변경된 헤드 포인터를 반환한다.
}