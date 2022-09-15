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
