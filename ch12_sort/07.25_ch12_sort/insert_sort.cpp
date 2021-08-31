#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, z) ( (z)=(x), (x) = (y), (y) = (z) )
#define MAX_SIZE 10


void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; // ���ڵ��� ������ �̵�
		list[j + 1] = key;
	}
}

void inc_insertion_sort(int list[], int first,int last,int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void bubble_sort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) // �յ��� ���ڵ带 ���� �� ��ü
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}

void shell_sort(int list[], int n) // n = size;
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if (gap % 2 == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, 1, n - 1, gap);
	}
}

				  // i�� ���ĵ� ���ʸ���Ʈ�� ���� �ε���
				  // j�� ���ĵ� �����ʸ���Ʈ�� ���� �ε���
				  // k�� ���ĵ� ����Ʈ�� ���� �ε���
int sorted[MAX_SIZE]; // �߰� ������ �ʿ�

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i>mid) // ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else // ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot);

		do {
			high--;
		} while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void) {
	int sorted[MAX_SIZE]; // �߰� ������ �ʿ�
	int i;
	int n = MAX_SIZE;
	srand(time(NULL));
	int list[MAX_SIZE];

	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}
	quick_sort(list, 0, n-1);
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}

