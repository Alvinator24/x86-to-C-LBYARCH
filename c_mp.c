#include <stdio.h>
#include <math.h>

void distance(double *x1, double *x2, double *y1, double *y2, double *z, int n) {
	int i = 0;
    for (i = 0; i < n; i++) {
        double dx = x1[i] - x2[i];
        double dy = y1[i] - y2[i];
        z[i] = sqrt(dx * dx + dy * dy);
    }
}

int main() {
    // Example vectors (same as the provided assembly input)
    double x1[] = {1.5, 4.0, 3.5, 2.0};
    double x2[] = {3.0, 2.5, 2.5, 1.0};
    double y1[] = {4.0, 3.0, 3.5, 3.0};
    double y2[] = {2.0, 2.5, 1.0, 1.5};
    double z[4]; // Output vector for results
    int n = 4; // Length of the vectors

    // Call the distance function
    distance(x1, x2, y1, y2, z, n);

    // Print the results
    printf("Results:\n");
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("z[%d] = %.8f\n", i, z[i]);
    }

    return 0;
}
