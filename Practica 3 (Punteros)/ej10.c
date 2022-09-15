#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>

struct s_texto
{
char * txt;
int longitud;
};
typedef struct s_texto t_texto;

void cargarTexto(t_texto*);
void escribirArchTex(char[],t_texto*);

int main(){
	t_texto *str = (t_texto*)malloc(sizeof(t_texto));
	cargarTexto(str);
	printf("%d,%s\n",str->longitud,str->txt);
	escribirArchTex("archivo.txt",str);
	return 0;
}

void escribirArchTex(char archivo[],t_texto* str){
	FILE *arch;
	arch = fopen(archivo,"a");
	fprintf(arch,"%d,%s\n",str->longitud,str->txt);
	fclose(arch);
}

void cargarTexto(t_texto* str){
	str->txt = (char*)malloc(sizeof(char));
	int size = 0;
	char c;
	printf("cargar String2: ");
	c = getchar();
	while(c!='\n'){
		size++;
		str->txt = realloc(str->txt,size*sizeof(char));
		str->txt[size-1] = c;
		c = getchar();
	}
	size++;
	str->txt = realloc(str->txt,size*sizeof(char));
	str->txt[size-1] = '\0';
	str->longitud = size-1;
}
