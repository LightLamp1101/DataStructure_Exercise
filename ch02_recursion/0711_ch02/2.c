#include <stdio.h>
#pragma warning(disable : 4996)

int recursiveSquare(int n, int t);
int loopSquare(int n, int t);

int main() {

	int inputN = 0, inputT = 0;

	printf("�ŵ������� ���� Ƚ���� �Է����ּ��� ex)2^3 : ");
	scanf("%d^%d", &inputN, &inputT);

	printf("����Լ��� ���� ���丮�� : %d\n", recursiveSquare(inputN, inputT));
	printf("�ݺ��� �Լ��� ���� ���丮�� : %d\n", loopSquare(inputN, inputT));

	getchar();
	getchar();

	return 0;
}

int recursiveSquare(int n, int t) {
	if (t <= 1) return n;
	return n * recursiveSquare(n, t-1);
}

int loopSquare(int n, int t) {
	int i, result = 1;
	for (i = 0; i < t; i++) {
		result *= n;
	}
	return result;
}