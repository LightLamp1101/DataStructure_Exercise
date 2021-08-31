#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define SIZE 100

char* runLen(char* text);

int main() {
	char text[SIZE] = { "AAAAAAABBCCCDEEEEFFFFFFG" };
	char* result;
	result = runLen(text);
	printf("%s", result);

	return 0;
}

char* runLen(char* text) {
	static char temp[SIZE] = "";
	char *ch[2];
	int i, cnt = 1;
	char buf[100];
	for (i = 0; i < strlen(text); i++) {
		if (text[i] == text[i + 1]) {
			cnt++;
		}
		else {
			ch[0] = text[i];
			ch[1] = '\0';
			strcat(temp, ch);
			sprintf(buf, "%d", cnt);
			strcat(temp, buf);
			cnt = 1;
		}
	}
	return temp;
}