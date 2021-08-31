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
			list[j + 1] = list[j]; // 레코드의 오른쪽 이동
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
		for (j = 0; j < i; j++) // 앞뒤의 레코드를 비교한 후 교체
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

				  // i는 정렬된 왼쪽리스트에 대한 인덱스
				  // j는 정렬된 오른쪽리스트에 대한 인덱스
				  // k는 정렬될 리스트에 대한 인덱스
int sorted[MAX_SIZE]; // 추가 공간이 필요

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i>mid) // 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else // 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
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
	int sorted[MAX_SIZE]; // 추가 공간이 필요
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

