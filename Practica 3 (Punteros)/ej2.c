/*	Desarrollar una función que reciba como parámetro un arreglo de int y una posición de
dicho arreglo. Luego la función deberá retornar la dirección de memoria de la variable
que se encuentra en esa posición del arreglo.
Aclaración: La función se resuelve en una sóla línea de código.	*/

#include <stdio.h>
#include <stdlib.h>

int *fun(int *arr, int pos);

int main(){
	int arr[3] = {1,2,3};
	int pos = 2;
	printf("[%d, %d, %d]",arr[0],arr[1],arr[2]);
	printf("dir:%p, dir:%p, dir:%p]",fun(arr,0),fun(arr,1),fun(arr,2));
	return 0;
}

int *fun(int *arr, int pos){
	return &arr[pos];
}
