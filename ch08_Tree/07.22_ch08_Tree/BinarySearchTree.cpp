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
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ
	if (node == NULL) return new_node(key);

	// �ƴ϶�� ��ȯ������ Ž��
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
	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode * delete_node(TreeNode * root, int key)
{
	if (root == NULL) return root;
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->data)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->data)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
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
		// �� ��° ���
		TreeNode * temp = min_value_node(root->right);
		// ���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->data = temp->data;
		// ���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf(" / %d", root->data); // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}

//��ȯ���� Ž�� �Լ�
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
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");
	return 0;
}