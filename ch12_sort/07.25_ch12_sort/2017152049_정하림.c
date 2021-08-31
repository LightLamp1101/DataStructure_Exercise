#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STUDENT_CNT 10
#define SWAP(x,y,z) ( (z) = (x), (x) = (y), (y) = (z) )

typedef struct Source {
	char name[20];
	char age;
	char address[50];
}Source;

typedef struct index {
	int studentNum;
	Source* s;
}Index;

void bubble_sort(Index list[], int n);
int partition(Index studentarr[], int left, int right);
void quick_sort(Index studentarr[], int left, int right);


int main() {
	Source studentSrc[MAX_STUDENT_CNT] = {		// ���� ������ �ʱ�ȭ
		{"���ϸ�", 25, "��⵵ ����"},
		{"�Ǽ�ȣ", 23, "��⵵ ȭ��"},
		{"�豤��", 24, "��⵵ �ȼ�"},
		{"�̽���", 26, "������ ����"},
		{"���Ͽ�", 22,  "������ ����"},
		{"������", 25, "��û���� ����"},
		{"������", 32, "��⵵ ����"},
		{"�輼��", 23, "����"},
		{"�ڴ���", 25, "����"},
		{"������", 24, "����� ������"}
	};
	Index studentIndex[MAX_STUDENT_CNT];
	int i;
	for (i = 0 ; i < MAX_STUDENT_CNT; i++) {	// �ε��� ������ �ʱ�ȭ
		studentIndex[i].studentNum = 2017152050 - i;		// �й��� �������� �ο�
		studentIndex[i].s = &studentSrc[i];				// �й��� ���������͸� ��Ī
	}

	// bubble_sort(studentIndex, MAX_STUDENT_CNT);			// �������� ȣ��
	quick_sort(studentIndex, 0, MAX_STUDENT_CNT - 1);		// ������ ȣ��

	for (i = 0; i < MAX_STUDENT_CNT; i++) {					// �ε����� ���� �л� ���� ���
		printf("�й� : %d, �̸� : %s, ���� : %d, �ּ� : %s \n",
			studentIndex[i].studentNum, studentIndex[i].s->name, studentIndex[i].s->age, studentIndex[i].s->address);
	}
	printf("\n");
	return 0;

}

void bubble_sort(Index list[], int n)
{
	int i, j;
	Index temp;
	for (i = n - 1; i>0; i--) {
		for (j = 0; j<i; j++) // �յ��� ���ڵ带 ���� �� ��ü
			if (list[j].studentNum>list[j + 1].studentNum)
				SWAP(list[j], list[j + 1], temp);
	}
}



int partition(Index studentarr[], int left, int right)
{
	int pivot, low, high;
	Index temp;
	low = left;
	high = right + 1;
	pivot = studentarr[left].studentNum;
	do {
		do
			low++;
		while (low <= right &&studentarr[low].studentNum<pivot);
		do
			high--;
		while (high >= left && studentarr[high].studentNum>pivot);
		if (low<high) SWAP(studentarr[low], studentarr[high], temp);
	} while (low<high);
	SWAP(studentarr[left], studentarr[high], temp);
	return high;
}

void quick_sort(Index studentarr[], int left, int right)
{
	if (left<right) {
		int q = partition(studentarr, left, right);
		quick_sort(studentarr, left, q - 1);
		quick_sort(studentarr, q + 1, right);
	}
}


