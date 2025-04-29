#include <stdio.h>                           // Standard I/O
#include <math.h>                            // Math functions (sqrt)

#define MIN_LIMIT 5                          // Minimum allowed value
#define MAX_LIMIT 25                         // Maximum allowed value

int main(void) {                             // Entry point
    int low, high, rc;                       // 'low' and 'high' limits, 'rc' for scanf

    printf("Enter lower limit (%d-%d): ",    // Prompt with ASCII hyphen
        MIN_LIMIT, MAX_LIMIT);
    rc = scanf_s("%d", &low);                // Read lower limit
    if (rc != 1 || low < MIN_LIMIT || low > MAX_LIMIT) {
        fprintf(stderr,                      // Validate and error if needed
            "Error: lower limit must be between %d and %d.\n",
            MIN_LIMIT, MAX_LIMIT);
        return 1;
    }

    printf("Enter upper limit (%d-%d, >= lower): ", // Prompt with ">=" instead of ?
        MIN_LIMIT, MAX_LIMIT);
    rc = scanf_s("%d", &high);               // Read upper limit
    if (rc != 1 || high < low || high > MAX_LIMIT) {
        fprintf(stderr,                      // Validate and error if needed
            "Error: upper limit must be between %d and %d and >= %d.\n",
            MIN_LIMIT, MAX_LIMIT, low);
        return 1;
    }

    // Print table header
    printf("+-------------------------------------+\n");
    printf("| Num |  Square  |   Cube   |  Sqrt   |\n");
    printf("+-------------------------------------+\n");

    for (int i = low; i <= high; ++i) {      // Loop from low to high
        printf("| %3d | %8d | %8d | %7.2f |\n",
            i,                            // Number
            i * i,                        // Square
            i * i * i,                    // Cube
            sqrt((double)i));             // Square root
    }

    printf("+-------------------------------------+\n"); // Footer

    return 0;                                // Success
}                                             // End of main
