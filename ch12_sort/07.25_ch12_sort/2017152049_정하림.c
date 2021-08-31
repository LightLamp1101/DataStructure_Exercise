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
	Source studentSrc[MAX_STUDENT_CNT] = {		// 원본 데이터 초기화
		{"정하림", 25, "경기도 시흥"},
		{"권순호", 23, "경기도 화성"},
		{"김광민", 24, "경기도 안성"},
		{"이승현", 26, "강원도 원주"},
		{"정하영", 22,  "강원도 원주"},
		{"윤지우", 25, "충청남도 세종"},
		{"정의진", 32, "경기도 수원"},
		{"김세종", 23, "용인"},
		{"박대한", 25, "정왕"},
		{"김윤태", 24, "서울시 강서구"}
	};
	Index studentIndex[MAX_STUDENT_CNT];
	int i;
	for (i = 0 ; i < MAX_STUDENT_CNT; i++) {	// 인덱스 데이터 초기화
		studentIndex[i].studentNum = 2017152050 - i;		// 학번을 역순으로 부여
		studentIndex[i].s = &studentSrc[i];				// 학번과 원본데이터를 매칭
	}

	// bubble_sort(studentIndex, MAX_STUDENT_CNT);			// 버블정렬 호출
	quick_sort(studentIndex, 0, MAX_STUDENT_CNT - 1);		// 퀵정렬 호출

	for (i = 0; i < MAX_STUDENT_CNT; i++) {					// 인덱스를 통해 학생 정보 출력
		printf("학번 : %d, 이름 : %s, 나이 : %d, 주소 : %s \n",
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
		for (j = 0; j<i; j++) // 앞뒤의 레코드를 비교한 후 교체
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


