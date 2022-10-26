#include <stdio.h>
#include <stdlib.h>

void invertir(int*, unsigned int);
void imprimir(int*, unsigned int);
int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	imprimir(arr,10);
	invertir(&arr,10);
	imprimir(arr,10);
	return 0;
}

void invertir(int *arr, unsigned int largo){

	if(largo>0){
		int aux = *arr;
		*arr = *(arr+largo-1);
		*(arr+largo-1) = aux;
		invertir(arr+1,largo-2);
	}
}

void imprimir(int* arr, unsigned int largo){
	for(int i=0;i<largo;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
