#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>

char* cargarStrDin();

int main(){
	char *str = cargarStrDin();
	printf("%s\n", str);
	return 0;
}

char* cargarStrDin(){
	char *str = (char*)malloc(sizeof(char));
	int size = 0;
	char c;
	printf("cargar String (termina con enter): ");
	c = getchar();
	while(c!='\n'){
		size++;
		str = realloc(str,size*sizeof(char));
		str[size-1] = c;
		c = getchar();
	}
	size++;
	str = realloc(str,size*sizeof(char));
	str[size-1] = '\0';
	return str;
}
