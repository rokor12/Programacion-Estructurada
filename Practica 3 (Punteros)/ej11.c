#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <math.h>
//#include <time.h>

typedef struct{
int a, b;
}t_dosint;

void intercambio(t_dosint*);
void intercambioAux(int*,int*);
int main(){
	t_dosint *var = (t_dosint*)malloc(sizeof(t_dosint));
	var->a = 1; var->b = 2;
	printf("%d,%d\n",var->a,var->b);
	intercambio(var);
	printf("%d,%d\n",var->a,var->b);
	return 0;
}

void intercambio(t_dosint *var){
	intercambioAux(&var->a,&var->b);
}

void intercambioAux(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}
