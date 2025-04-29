#include <stdio.h>                           // Include standard I/O functions

#define RANGE 16                             // Number of values beyond the start

int main(void) {                             // Program entry point
    int start = 0, rc;                       // 'start' for input, 'rc' for scanf return

    printf("Enter a starting number: ");     // Ask user for the start value
    rc = scanf_s("%d", &start);              // Read integer into 'start'
    if (rc != 1)
    {                           // If reading failed
        fprintf(stderr,                      //   Report error 
            "Error: invalid input.\n");
        return 1;                            //   Exit with failure
    }

    printf("Numbers from %d to %d:\n",        // Print range header
        start, start + RANGE);

    for (int i = start; i <= start + RANGE; ++i) { // Loop over the range
        printf("%d\n", i);                   //   Print each number
    }

    return 0;                                // Success
}                                             // End of mains