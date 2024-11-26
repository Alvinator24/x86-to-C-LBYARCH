#include <stdio.h>
#include <math.h>
#include <time.h>

// Function to calculate distances between points
void distance(double *x1, double *x2, double *y1, double *y2, double *z, int n) {
    for (int i = 0; i < n; i++) {
        double dx = x1[i] - x2[i];
        double dy = y1[i] - y2[i];
        z[i] = sqrt(dx * dx + dy * dy);
    }
}

int main() {
    // Arrays for the x and y coordinates of two sets of points.
    double x1[] = {1.5, 4.0, 3.5, 2.0};
    double x2[] = {3.0, 2.5, 2.5, 1.0};
    double y1[] = {4.0, 3.0, 3.5, 3.0};
    double y2[] = {2.0, 2.5, 1.0, 1.5};
    double z[4];
    int n = 4;

    // Start the timer to measure the execution time.
    clock_t start_time = clock();

    // Call the function to calculate the distances.
    distance(x1, x2, y1, y2, z, n);

    // Stop the timer after the calculation.
    clock_t end_time = clock();

    // Print the results of the distance calculations.
    printf("Results:\n");
    for (int i = 0; i < n; i++) {
        printf("z[%d] = %.6f\n", i, z[i]);
    }

    // Calculate and print execution time.
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution Time: %.6f seconds\n", elapsed_time);

    return 0;
}

