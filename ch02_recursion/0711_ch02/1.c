#include <stdio.h>
#pragma warning(disable : 4996)

int recursiveP(int n);
int loopP(int n);

int main() {

	int input = 0;

	printf("n! ������ n���� �Է��� �ּ��� : ");
	scanf("%d", &input);

	printf("����Լ��� ���� ���丮�� : %d\n", recursiveP(input));
	printf("�ݺ��� �Լ��� ���� ���丮�� : %d\n", loopP(input));

	getchar();
	getchar();

	return 0;
}

int recursiveP(int n) {
	if (n <= 1) return 1;
	return n * recursiveP(n - 1);
}

int loopP(int n) {
	int i , result = 1;
	for (i = n; i > 0; i--) {
		result *= i;
	}
	return result;
}