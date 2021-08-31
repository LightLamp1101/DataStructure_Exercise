#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000000

int parent[MAX_VERTICES];

int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
int found[MAX_VERTICES]; /* �湮�� ���� ǥ�� */

typedef struct GraphType {
	int n; // ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

typedef struct GraphType2 {
	int n; // ������ ����
	int dist[MAX_VERTICES][MAX_VERTICES];
	int traffic[MAX_VERTICES][MAX_VERTICES];
	int weather[MAX_VERTICES][MAX_VERTICES];
} GraphType2;


int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i<n; i++)
		if (distance[i]< min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d : ", step++);
	printf("distance : ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("            found : ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i<g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE; /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;
	for (i = 0; i<g->n - 1; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w<g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w]<distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}

void findWeight(GraphType2 source, GraphType destination, int dist_weight, int traffic_weight, int weather_weight) {
	int i, j;
	for (i = 0; i < source.n; i++)
		for (j = 0; j < source.n; j++)
			destination.weight[i][j] = source.dist[i][j] * ((float)dist_weight / 100) + source.traffic[i][j] * ((float)traffic_weight / 100) + source.weather[i][j] * ((float)weather_weight / 100);
}


int main(void)
{
	GraphType g = { 7,
	{ { 0, 7, INF, INF, 3, 10, INF },
	{ 7, 0, 4, 10, 2, 6, INF },
	{ INF, 4, 0, 2, INF, INF, INF },
	{ INF, 10, 2, 0, 11, 9, 4 },
	{ 3, 2, INF, 11, 0, INF, 5 },
	{ 10, 6, INF, 9, INF, 0, INF },
	{ INF, INF, INF, 4, 5, INF, 0 } }
	};

	GraphType result;
	GraphType2 roadInfo = {
		7, 	
			{ { 0, 70, INF, 50, INF, 20, INF }, 
			  { 70, 0, 60, INF, 20, INF, INF },
			  { INF, 60, 0, 20, INF, INF, 20 },
			  { 50, INF, 20, 0, INF, 50, INF },
			  { INF, 20, INF, INF, 0, 20, INF },
			  { 20, INF, INF, 50, 20, 0, 40 },
			  { INF, INF, 20, INF, INF, 40, 0 }
			},

			{ { 0, 10, INF, 50, INF, 50, INF },
			{ 10, 0, 10, INF, 10, INF, INF },
			{ INF, 10, 0, 10, INF, INF, 10 },
			{ 50, INF, 10, 0, INF, 10, INF },
			{ INF, 10, INF, INF, 0, 40, INF },
			{ 50, INF, INF, 10, 40, 0, 40 },
			{ INF, INF, 10, INF, INF, 40, 0 }
			},

			{ {	0,		0,		INF,	0,		INF,	50,		INF },
			{	0,		0,		0,		INF,	0,		INF,	INF },
			{	INF,	0,		0,		0,		INF,	INF,	0 },
			{	0,		INF,	0,		0,		INF,	50,		INF },
			{	INF,	0,		INF,	INF,	0,		50,		INF },
			{	50,		INF,	INF,	50,		50,		0,		05 },
			{	INF,	INF,	0,		INF,	INF,	50,		0 }
			}
	};


	findWeight(roadInfo, result, 50, 30, 20);
	shortest_path(&result, 0);
	return 0;
}