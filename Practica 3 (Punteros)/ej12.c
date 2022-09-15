#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
//#include <time.h>

struct s_texto
{
char * txt;
int longitud;
};
typedef struct s_texto t_texto;

void cargarTexto(t_texto*);
t_texto** cargarTextos();
void imprimir(t_texto**);

int main(){
	t_texto **strings = cargarTextos();
	cargarTextos(strings);
	imprimir(strings);
}

void imprimir(t_texto** strings){
	int i=0;
	printf("TEST:\n");
	while(strings[i]->longitud!=0){
		printf("%s\n",strings[i]->txt);
		i++;
	}
}

t_texto** cargarTextos(){
	t_texto** strings = (t_texto**)malloc(sizeof(t_texto*));
	int size = 0;
	size++;
	strings = realloc(strings,size*sizeof(t_texto*));
	strings[size-1] = (t_texto*)malloc(sizeof(t_texto));
	cargarTexto(strings[size-1]);
	while(strlen(strings[size-1]->txt)!=0){
		size++;
		strings = realloc(strings,size*sizeof(t_texto*));
		strings[size-1] = (t_texto*)malloc(sizeof(t_texto));
		cargarTexto(strings[size-1]);
		printf("%d\n",strings[size-1]->longitud);
	}
	return strings;
}

void cargarTexto(t_texto* str){
	str->txt = (char*)malloc(sizeof(char));
	int size = 0;
	char c;
	printf("cargar String: ");
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
