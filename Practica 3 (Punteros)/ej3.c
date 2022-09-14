#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void redondeo(double *val);

int main(){
	double *val = (double*)malloc(sizeof(double));
	*val = 2.51;
	printf("%f\n",*val);
	redondeo(val);
	printf("%f\n",*val);
	return 0;
}

void redondeo(double *val){
	*val = round(*val);
}
