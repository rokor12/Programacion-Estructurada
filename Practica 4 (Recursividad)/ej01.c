#include <stdio.h>
#include <stdlib.h>

int producto(int a, int b);

int main(){
	int a;
	int b;
	printf("Ingrese el primer valor: ");
	scanf("%d",&a);
	printf("Ingrese el segundo valor: ");
	scanf("%d",&b);
	printf("Resultado: %d\n",producto(a,b));
	return 0;
}

int producto(int a, int b){
	if(b!=0){
		return a + producto(a,b-1);
	}
	return 0;
}
