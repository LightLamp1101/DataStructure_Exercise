#include <stdio.h>
#include <stdlib.h>

typedef int element; // 항목의 정의
typedef struct {
	element data;
	struct  ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode *p = malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; 
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head; // (1)
	head = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}

// pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main(void)
{
	/*
	ListNode *head = NULL;
	head = (ListNode *)malloc(sizeof(ListNode));

	head->data = 10;
	head->link = NULL;

	ListNode *p;
	p = (ListNode *)malloc(sizeof(ListNode));
	p->data = 20;
	p->link = NULL;

	head->link = p;
	*/
	ListNode *head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;

}