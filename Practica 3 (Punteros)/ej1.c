/*	Desarrollar una función que reciba como parámetros dos punteros a int y qué
intercambie los valores de las variables apuntadas por dichos punteros.	*/
#include <stdio.h>
#include <stdlib.h>

void intercambio(int *a, int *b);

int main(){
	int *a = (int*)malloc(sizeof(int));
	int *b = (int*)malloc(sizeof(int));
	printf("Ingrese el primer valor: ");
	scanf("%d",a);
	printf("Ingrese el segundo valor: ");
	scanf("%d",b);
	printf("A: %d | B: %d\n",*a,*b);
	intercambio(a,b);
	printf("A: %d | B: %d\n",*a,*b);
	return 0;
}

void intercambio(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}
