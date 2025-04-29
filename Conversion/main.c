#include <stdio.h>                            // Include standard I/O functions

#define DAYS_PER_WEEK 7                       // Define number of days in one week

int main(void) {                              // Program entry point
    int days, weeks, rem, rc;                 // Declare variables for days, computed weeks, remainder, and scanf return

    do {                                      // Start do–while loop to repeat until non-positive input
        printf("Enter number of days "        // Prompt user for number of days
            "(positive to convert, 0 or negative to quit): ");
        rc = scanf_s("%d", &days);            // Read input into 'days'
        if (rc != 1) {                        // If input is invalid
            fprintf(stderr,                   // Print error
                "Error: invalid input.\n");
            return 1;                         // Exit with failure
        }

        if (days > 0) {                       // Only convert if days > 0
            weeks = days / DAYS_PER_WEEK;     // Compute full weeks
            rem = days % DAYS_PER_WEEK;     // Compute leftover days
            printf("%d day%s is %d week%s and %d day%s.\n",
                days,                      // Original days
                days == 1 ? "" : "s",    // Pluralization for days
                weeks,                     // Number of weeks
                weeks == 1 ? "" : "s",    // Pluralization for weeks
                rem,                       // Remaining days
                rem == 1 ? "" : "s");   // Pluralization for remainder
        }
    } while (days > 0);                       // Repeat until user enters 0 or negative

    printf("Goodbye!\n");                     // Say goodbye on exit
    return 0;                                 // Return success status
}                                              // End of main