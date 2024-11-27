#include <stdio.h>
#include <stdlib.h>

extern void distance(int n, double* vec1, double* vec2, double* vec3);

int main() {
	double x1[] = {1.5, 4.0, 3.5, 2.0};
	double x2[] = {3.0, 2.5, 2.5, 1.0};
	double y1[] = {4.0, 3.0, 3.5, 3.0};
	double y2[] = {2.0, 2.5, 1.0, 1.5};
	double* vec1 = (double*)malloc(4*sizeof(double));
	double* vec2 = (double*)malloc(4*sizeof(double));
	double* vec3 = (double*)malloc(4*sizeof(double));
	
	int i;
	for(i=0; i<4; i++){
		vec1[i] = x1[i] - x2[i];
		vec2[i] = y1[i] - y2[i];
	}
	
	int n = 4;
	distance(n, vec1, vec2, vec3);
	
	for(i=0; i<4; i++){
		printf("z[%d] = %lf\n", i, vec3[i]);
	}
	
	return 0;
}
