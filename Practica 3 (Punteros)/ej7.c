/*	Desarrollar la función cargarStrDin() que permita ingresar una frase desde el teclado
hasta presionar ENTER. Y que lo ingresado lo almacene en un arreglo en memoria
dinámica y sin desperdiciar espacio. Luego la función deberá remitir al exterior el
contenido cargado. Realizar una prueba desde el programa principal imprimiendo en
consola el contenido remitido por la función.	*/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>

char* cargarStrDin();

int main(){
	char *str = cargarStrDin();
	printf("%s\n", str);
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
	str[size-1] = 0;
	return str;
}
