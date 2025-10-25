/**
 * @file conversion.c
 * @brief Days to Weeks Converter
 * @author Jaden Mardini
 * 
 * Professional time conversion utility with input validation
 * and proper pluralization handling.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DAYS_PER_WEEK 7
#define MAX_DAYS (INT_MAX / DAYS_PER_WEEK)

/**
 * @brief Validates day input to prevent overflow
 */
static int validate_days(int days) {
    if (days > MAX_DAYS) {
        fprintf(stderr, "Error: Too many days (maximum: %d)\n", MAX_DAYS);
        return 0;
    }
    return 1;
}

/**
 * @brief Safely reads integer input
 */
static int read_days(int* days) {
    printf("Enter number of days (positive to convert, 0 or negative to quit): ");
    
    if (scanf("%d", days) != 1) {
        fprintf(stderr, "Error: Invalid input format\n");
        return 0;
    }
    
    /* Clear input buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    return 1;
}

/**
 * @brief Returns appropriate plural suffix
 */
static const char* plural_suffix(int count) {
    return (count == 1) ? "" : "s";
}

/**
 * @brief Converts days to weeks and remaining days
 */
static void convert_days(int days) {
    if (!validate_days(days)) {
        return;
    }
    
    int weeks = days / DAYS_PER_WEEK;
    int remaining = days % DAYS_PER_WEEK;
    
    printf("\nConversion Result:\n");
    printf("-----------------\n");
    printf("%d day%s = %d week%s and %d day%s\n",
           days, plural_suffix(days),
           weeks, plural_suffix(weeks),
           remaining, plural_suffix(remaining));
    
    if (weeks > 0) {
        printf("That's approximately %.2f weeks total\n", 
               (double)days / DAYS_PER_WEEK);
    }
    printf("\n");
}

/**
 * @brief Main program entry point
 */
int main(void) {
    printf("=== Days to Weeks Converter ===\n");
    printf("Author: Jaden Mardini\n\n");
    
    int days;
    
    do {
        if (!read_days(&days)) {
            return EXIT_FAILURE;
        }
        
        if (days > 0) {
            convert_days(days);
        }
        
    } while (days > 0);
    
    printf("Thank you for using the converter!\n");
    return EXIT_SUCCESS;
}
