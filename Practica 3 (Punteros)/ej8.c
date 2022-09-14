#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>

char* cargarStrDin1(); //ej7
void cargarStrDin2(char* str);

int main(){
	char *str1 = cargarStrDin1();
	printf("%s\n", str1);
	char *str2 = (char*)malloc(sizeof(char)); //requiere estar inicializado
	cargarStrDin2(str2);
	printf("%s\n", str2);
	return 0;
}

void cargarStrDin2(char* str){
	int size = 0;
	char c;
	printf("cargar String2: ");
	c = getchar();
	while(c!='\n'){
		size++;
		str = realloc(str,size*sizeof(char));
		str[size-1] = c;
		c = getchar();
	}
	size++;
	str = realloc(str,size*sizeof(char));
	str[size-1] = 0;
}

char* cargarStrDin1(){
	char *str = (char*)malloc(sizeof(char));
	int size = 0;
	char c;
	printf("cargar String1: ");
	c = getchar();
	while(c!='\n'){
		size++;
		str = realloc(str,size*sizeof(char));
		str[size-1] = c;
		c = getchar();
	}
	size++;
	str = realloc(str,size*sizeof(char));
	str[size-1] = 0;
	return str;
}
