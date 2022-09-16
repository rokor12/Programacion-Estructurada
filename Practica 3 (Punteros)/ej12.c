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

void cargarTexto(t_texto*);				// 3.10
t_texto** cargarTextos();				// 3.12.a
void ordenar(t_texto**);				// 3.12.b
void intercambio(t_texto*, t_texto*);	// 3.12.b
void comparar(t_texto*, t_texto*);
void imprimir(t_texto**);

int main(){
	t_texto **strings = cargarTextos();
	imprimir(strings);
	ordenar(strings);
	imprimir(strings);
	return 0;
}

void ordenar(t_texto** strings){
	int i,j;
	for(i=0;strcmp(strings[i]->txt,"");i++){
		for(j=i+1;strcmp(strings[j]->txt,"");j++){
			if(strcmp(strings[i]->txt,strings[j]->txt)>0){
				intercambio(strings[i],strings[j]);
		    }
		}
	}
}

void imprimir(t_texto** strings){
	int i=0;
	printf("\nFrases:\n");
	while(strings[i]->longitud!=0){
		printf("%d, %s\n",strings[i]->longitud,strings[i]->txt);
		i++;
	}
}

t_texto** cargarTextos(){
	t_texto **strings = (t_texto**)malloc(sizeof(t_texto*));
	int size = 1,aux=1;
	while(aux!=0){
		strings = realloc(strings,size*sizeof(t_texto*));
		strings[size-1] = (t_texto*)malloc(sizeof(t_texto));
		cargarTexto(strings[size-1]);
		aux = strings[size-1]->longitud;
		size++;
	}
	return strings;
}

void cargarTexto(t_texto* str){
	str->txt = (char*)malloc(sizeof(char));
	int size = 0;
	char c;
	printf("Cargar Frase: ");
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

void intercambio(t_texto *a, t_texto *b){
	t_texto aux = *a;
	*a = *b;
	*b = aux;
}
