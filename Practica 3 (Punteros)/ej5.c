/*
Dada la estructura t_tres:
Desarrollar una función que modifique el contenido de una variable externa de este tipo,
de manera que los valores contenidos en cada campo queden ordenados. Es decir, el
campo “a” debe tener el valor más bajo, el campo “b” el segundo más bajo y así
sucesivamente.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct{
int a, b, c;
}t_tres;

int aleatorio(int inf, int sup);
void ordenarT_tres(t_tres *aux);
void ordenarArr(int *arr, int arrSize);

int main(){
	t_tres var;
	var.a = aleatorio(0,100);
	var.b = aleatorio(0,100);
	var.c = aleatorio(0,100);
	printf("%d %d %d\n",var.a,var.b,var.c);
	ordenarT_tres(&var);
	printf("%d %d %d\n",var.a,var.b,var.c);
	return 0;
}

int aleatorio(int inf, int sup){
    return inf + (rand() % (sup-inf+1));
}

void ordenarArr(int *arr, int arrSize){
	int i,j,aux;
	for(i=0;i<arrSize-1;i++){
		for(j=i+1;j<arrSize;j++){
			if(arr[i]>arr[j]){
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}
}
void ordenarT_tres(t_tres *var){
	int *arrAux = (int*)malloc(3*sizeof(int));
	arrAux[0] = var->a;
	arrAux[1] = var->b;
	arrAux[2] = var->c;
	ordenarArr(arrAux,3);
	var->a = arrAux[0];
	var->b = arrAux[1];
	var->c = arrAux[2];
}
