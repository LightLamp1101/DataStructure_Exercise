#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef char element[100]; 
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current;

// 이중 연결 리스트를 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%s| |->", p->data);
	}
	printf("\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode *)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// 노드 removed를 삭제
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main() {
	int i, input1,input2;
	char ch[10];
	element song;
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	DListNode* d, *order1, *order2;
	init(head);
	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");
	current = head->rlink;
	print_dlist(head);
	do {
		printf("\n현재 재생음악 : %s", current->data);
		printf("\n명령어를 입력하시오(<, >, q, <<, >>, add, del, order): ");
		scanf("%s",ch);
		if (!strcmp(ch,"<")) {
			current = current->llink;
			if (current == head)
				current = current->llink;
		} else if (!strcmp(ch, ">")) {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		} else if (!strcmp(ch, "<<")) {
			for (i = 0; i < 2; i++) {
				current = current->llink;
				if (current == head)
					current = current->llink;
			}
		} else if (!strcmp(ch, ">>")) {
			for (i = 0; i < 2; i++) {
				current = current->rlink;
				if (current == head)
					current = current->rlink;
			}
		} else if (!strcmp(ch, "add")) {
			printf("\n추가할 음악명을 입력해주세요 : \n");
			scanf("%s",song);
			dinsert(head, song);
		} else if (!strcmp(ch, "del")) {
			d = current;
			current = current->rlink;
			if (current == head)
				current = current->rlink;
			ddelete(head, d);
		} else if (!strcmp(ch, "order")) {
			printf("순서 변경할 곡들의 번호를 입력해주세요 [ex) : 1 3] : ");
			scanf("%d %d", &input1, &input2);
			order1 = order2 = head;
			for (i = 0; i < input1; i++) order1 = order1->rlink;
			for (i = 0; i < input2; i++) order2 = order2->rlink;
			strcpy(song,order1->data);
			strcpy(order1->data, order2->data);
			strcpy(order2->data, song);
		}
		print_dlist(head);
		getchar();
	} while (strcmp(ch, "q"));

}

//<<, >>, add, del, order
// 2칸씩 뛰어넘기, 음악 추가, 음악 삭제, 음악 순서 변경