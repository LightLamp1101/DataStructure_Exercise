#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//오류 처리 함수
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void insert_last(ListNode* head, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	ListNode *search = head;
	p->data = value;
	p->link = NULL;
	for (; search->link != NULL; search = search->link);
	search -> link = p;
}

void print_list(ListNode* head) {
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL\n");
}

ListNode* search_list(ListNode *head, char* x)
{
	ListNode *p = head;
	while (p != NULL) {
		if (!strcmp(p->data.name, x)) {
			printf("%s는 연결리스트에 있습니다.\n", x);
			return p;
		}
		p = p->link;
	}
	printf("탐색 실패!\n");
	return NULL;
}

void merge_list(ListNode* h1, ListNode* h2) {
	ListNode* p = h1;
	while (p->link != NULL) p = p->link;
	p->link = h2;
}


int main(void)
{
	ListNode *head = NULL;
	ListNode *head2 = NULL;
	element data;
	char inputFruit[100];

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	insert_last(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	insert_last(head, data);
	print_list(head);

	strcpy(data.name, "PEACH");
	head2 = insert_first(head2, data);

	strcpy(data.name, "MELON");
	insert_last(head2, data);
	print_list(head2);

	merge_list(head, head2);
	print_list(head);


	printf("당신이 찾고 싶은 과일 이름을 입력하세요 : ");
	scanf("%s", inputFruit);
	search_list(head, inputFruit);
	return 0;
}