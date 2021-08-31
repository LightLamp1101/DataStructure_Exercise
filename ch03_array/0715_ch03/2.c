#include <stdio.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))  

#define MAX_DEGREE 101 // 다항식의 최대차수 + 1

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B);
void print_poly(polynomial p);

int main(void)
{
	polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial res = { 0 };

	int Apos = 0, Bpos = 0, respos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	res.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { // A항 > B항
			res.coef[respos++] = A.coef[Apos++];
			degree_a--;
		} else if (degree_a == degree_b) { // A항 == B항
			res.coef[respos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		} else { // B항 > A항
			res.coef[respos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return res;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i>0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

