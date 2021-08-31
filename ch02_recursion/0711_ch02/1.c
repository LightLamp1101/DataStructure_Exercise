#include <stdio.h>
#pragma warning(disable : 4996)

int recursiveP(int n);
int loopP(int n);

int main() {

	int input = 0;

	printf("n! 에서의 n값을 입력해 주세요 : ");
	scanf("%d", &input);

	printf("재귀함수로 구한 팩토리얼 : %d\n", recursiveP(input));
	printf("반복문 함수로 구한 팩토리얼 : %d\n", loopP(input));

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