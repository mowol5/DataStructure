#include <stdio.h>
#include <math.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

struct polynomial1 { // 다항식 구조체 타입 선언
	int degree; // 다항식의 차수
	float coef[MAX_DEGREE]; // 다항식의 계수
}; 

polynomial1 poly_sub(polynomial1 A, polynomial1 B) {
	polynomial1 C;//결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos] = A.coef[Apos];
			degree_a--;
			printf("Apos: %d / Bpos: %d / Cpos: %d\n", Apos, Bpos, Cpos);
			printf("A.coef[%d]: %.2f / B.coef[%d]: %.2f / C.coef[%d]: %.2f\n", Apos, A.coef[Apos], Bpos, B.coef[Bpos], Cpos, C.coef[Cpos]);
			Cpos++;
			Apos++;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos] = A.coef[Apos] - B.coef[Bpos];
			degree_a--;
			degree_b--;
			printf("Apos: %d / Bpos: %d / Cpos: %d\n", Apos, Bpos, Cpos);
			printf("A.coef[%d]: %.2f / B.coef[%d]: %.2f / C.coef[%d]: %.2f\n", Apos, A.coef[Apos], Bpos, B.coef[Bpos], Cpos, C.coef[Cpos]);
			Apos++;
			Bpos++;
			Cpos++;
		}
		else {
			C.coef[Cpos] = B.coef[Bpos];
			degree_b--;
			printf("Apos: %d / Bpos: %d / Cpos: %d\n", Apos, Bpos, Cpos);
			printf("A.coef[%d]: %.2f / B.coef[%d]: %.2f / C.coef[%d]: %.2f\n", Apos, A.coef[Apos], Bpos, B.coef[Bpos], Cpos, C.coef[Cpos]);
			Cpos++;
			Bpos++;
		}
		printf("---\n");
	}
	return C;
}

void print_poly(polynomial1 p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d ", fabs(p.coef[p.degree - i]), i);

		if (p.coef[p.degree - i + 1] >= 0)
			printf(" + ");
		else
			printf(" - ");
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

int main() {
	polynomial1 a = {5, {3, 6, 0, 0, 0, 10}};
	polynomial1 b = { 4, {7, 0, 5, 0, 1} };
	polynomial1 c;

	print_poly(a);
	print_poly(b);
	printf("-----------------------\n");
	c = poly_sub(a, b);
	printf("-----------------------\n");
	print_poly(c);

	return 0;
}