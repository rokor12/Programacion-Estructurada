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

void cargarTexto(t_texto*);					// 3.12.a | 3.10
t_texto** cargarTextos();					// 3.12.a
void ordenar(t_texto**);					// 3.12.b
void intercambio(t_texto*, t_texto*);		// 3.12.b | 3.1 (modificada)
void imprimirStrings(t_texto**);
void imprimirString(t_texto*);				// 3.12.c
void cargarStringsArch(char[],t_texto**);	// 3.12.d
void escribirArchTex(char[],t_texto*);		// 3.12.d | 3.10


int main(){
	t_texto **strings = cargarTextos();
	ordenar(strings);
	imprimirStrings(strings);
	cargarStringsArch("frases_con_longitud.csv",strings);
	return 0;
}

void cargarStringsArch(char archivo[],t_texto **strings){
	int i;
	for(i=0;strcmp(strings[i]->txt,"");i++){
		escribirArchTex(archivo,strings[i]);
	}
}

void escribirArchTex(char archivo[],t_texto* string){
	FILE *arch;
	arch = fopen(archivo,"a");
	fprintf(arch,"%d;%s\n",string->longitud,string->txt);
	fclose(arch);
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

void imprimirStrings(t_texto** strings){
	int i=0;
	printf("\nFrases:\n");
	while(strings[i]->longitud!=0){
		imprimirString(strings[i]);
		i++;
	}
}

void imprimirString(t_texto* string){
	printf("%s\n",string->txt);
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

void cargarTexto(t_texto* string){
	string->txt = (char*)malloc(sizeof(char));
	int size = 0;
	char c;
	printf("Cargar Frase: ");
	c = getchar();
	while(c!='\n'){
		size++;
		string->txt = realloc(string->txt,size*sizeof(char));
		string->txt[size-1] = c;
		c = getchar();
	}
	size++;
	string->txt = realloc(string->txt,size*sizeof(char));
	string->txt[size-1] = '\0';
	string->longitud = size-1;
}

void intercambio(t_texto *a, t_texto *b){
	t_texto aux = *a;
	*a = *b;
	*b = aux;
}
