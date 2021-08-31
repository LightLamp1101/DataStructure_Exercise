#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;


TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode *insert_node(TreeNode* node, int key) {
	// 트리가 공백이면 새로운 노드를 반환
	if (node == NULL) return new_node(key);

	// 아니라면 순환적으로 탐색
	if (key < node->data) {
		node->left = insert_node(node->left, key);
	}
	else if (key > node->data) {
		node->right = insert_node(node->right, key);
	}
	return node;
}



TreeNode* min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode * delete_node(TreeNode * root, int key)
{
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->data)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->data)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
		if (root->left == NULL) {
			TreeNode * temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		// 세 번째 경우
		TreeNode * temp = min_value_node(root->right);
		// 중위 순회시 후계 노드를 복사한다.
		root->data = temp->data;
		// 중위 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		printf(" / %d", root->data); // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}

//순환적인 탐색 함수
TreeNode *search(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->data) return node;
	else if (key < node->data)
		return search(node->left, key);
	else
		return search(node->right, key);
}


int main(void)
{
	TreeNode * root = NULL;
	TreeNode * tmp = NULL;
	root = insert_node(root, 21);
	root = insert_node(root, 19);
	root = insert_node(root, 18);
	root = insert_node(root, 14);
	root = insert_node(root, 13);
	root = insert_node(root, 10);
	root = insert_node(root, 8);
	root = insert_node(root, 7);
	root = insert_node(root, 6);
	root = insert_node(root, 4);
	root = insert_node(root, 3);
	root = insert_node(root, 1);
	root = insert_node(root, 24);
	root = insert_node(root, 37);
	root = insert_node(root, 40);
	root = insert_node(root, 45);
	root = insert_node(root, 71);
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	return 0;
}