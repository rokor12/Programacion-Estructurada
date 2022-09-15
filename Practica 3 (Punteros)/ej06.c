#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct
{
	int val1,val2;
//	int n, o , p;
//	char p1[26], p2[50];
//	double a, b, c;
}
t_varios;

void intercambio(t_varios *a, t_varios *b);

int aleatorio(int inf, int sup){
    return inf + (rand() % (sup-inf+1));
}

int main(){
	t_varios *a = (t_varios*)malloc(sizeof(t_varios));
	t_varios *b = (t_varios*)malloc(sizeof(t_varios));
	a->val1 = 1; a->val2 = 1;
	b->val1 = 2; b->val2 = 2;
	printf("%d %d | %d %d\n", a->val1,a->val2,b->val1,b->val2);
	intercambio(a,b);
	printf("%d %d | %d %d\n", a->val1,a->val2,b->val1,b->val2);
	return 0;
}

void intercambio(t_varios *a, t_varios *b){
	t_varios aux = *a;
	*a = *b;
	*b = aux;
}
