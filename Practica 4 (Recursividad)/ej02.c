#include <stdio.h>
#include <stdlib.h>

int cociente(int a, int b);

int main(){
	int a;
	int b;
	printf("Ingrese el primer valor: ");
	scanf("%d",&a);
	printf("Ingrese el segundo valor: ");
	scanf("%d",&b);
	printf("Resultado: %d\n",cociente(a,b));
	return 0;
}

int cociente(int a, int b){
	if(a>=b){
		return 1 + cociente(a-b,b);
	}
	return 0;
}
