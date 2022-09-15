#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
//#include <time.h>


char * subcadena(char * p, int i, int n);

int main(){
	char aux[] = "Hola Mundo";
	char *str = (char*)malloc(strlen(aux)*sizeof(char));
	strcpy(str,aux);
	char *subStr = subcadena(str,5,10);
	printf("%s\n", subStr);
	return 0;
}

char * subcadena(char *p, int i, int n){
	char *subStr = malloc((n-i+1)*sizeof(char));
	subStr[n-i] = '\0';
	int j;
	for(j=0;j<n;j++){
		subStr[j] = p[i+j];
	}
	return subStr;
}
