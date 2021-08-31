#include <stdio.h>
#pragma warning(disable : 4996)

int recursiveSquare(int n, int t);
int loopSquare(int n, int t);

int main() {

	int inputN = 0, inputT = 0;

	printf("거듭제곱할 수와 횟수를 입력해주세요 ex)2^3 : ");
	scanf("%d^%d", &inputN, &inputT);

	printf("재귀함수로 구한 팩토리얼 : %d\n", recursiveSquare(inputN, inputT));
	printf("반복문 함수로 구한 팩토리얼 : %d\n", loopSquare(inputN, inputT));

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