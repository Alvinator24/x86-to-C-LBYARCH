#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void distance(double *x1, double *x2, double *y1, double *y2, double *z, int n) {
    int i;
    for (i = 0; i < n; i++) {
        double dx = x1[i] - x2[i];
        double dy = y1[i] - y2[i];
        z[i] = sqrt(dx * dx + dy * dy);
    }
}

int main() {
    int n_values[] = {1 << 20, 1 << 24, 1 << 28};
    int num_trials = 30;
    int num_sizes = sizeof(n_values) / sizeof(n_values[0]);
    int size_index;
    for (size_index = 0; size_index < num_sizes; size_index++) {
        int n = n_values[size_index];
        double *x1 = (double *)malloc(n * sizeof(double));
        double *x2 = (double *)malloc(n * sizeof(double));
        double *y1 = (double *)malloc(n * sizeof(double));
        double *y2 = (double *)malloc(n * sizeof(double));
        double *z = (double *)malloc(n * sizeof(double));
        int i;
		for (i = 0; i < n; i++) {
            x1[i] = (rand() % 1000) / 100.0;
            x2[i] = (rand() % 1000) / 100.0;
            y1[i] = (rand() % 1000) / 100.0;
            y2[i] = (rand() % 1000) / 100.0;
        }
        
        double total_time = 0.0;
        int trial;
        for (trial = 0; trial < num_trials; trial++) {
            clock_t start_time = clock();
            distance(x1, x2, y1, y2, z, n);
            clock_t end_time = clock();
            total_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        }

        double average_time = total_time / num_trials;
        printf("Average execution time for n = %d: %lf seconds\n", n, average_time);
        free(x1);
        free(x2);
        free(y1);
        free(y2);
        free(z);
    }

    return 0;
}
