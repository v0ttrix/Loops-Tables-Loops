/**
 * @file loops.c
 * @brief Number Range Generator
 * @author Jaden Mardini
 * 
 * Professional implementation of number range generation with
 * comprehensive input validation and error handling.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DEFAULT_RANGE 16
#define MIN_START INT_MIN
#define MAX_START (INT_MAX - DEFAULT_RANGE)

/**
 * @brief Validates input range to prevent overflow
 */
static int validate_start(int start) {
    if (start < MIN_START || start > MAX_START) {
        fprintf(stderr, "Error: Start value would cause overflow\n");
        return 0;
    }
    return 1;
}

/**
 * @brief Safely reads integer input
 */
static int read_integer(const char* prompt, int* value) {
    printf("%s", prompt);
    
    if (scanf("%d", value) != 1) {
        fprintf(stderr, "Error: Invalid input format\n");
        return 0;
    }
    
    /* Clear input buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    return 1;
}

/**
 * @brief Generates and displays number range
 */
static void generate_range(int start, int range) {
    printf("\nNumbers from %d to %d:\n", start, start + range);
    printf("------------------------\n");
    
    for (int i = start; i <= start + range; i++) {
        printf("%d\n", i);
    }
    
    printf("------------------------\n");
    printf("Total numbers: %d\n", range + 1);
}

/**
 * @brief Main program entry point
 */
int main(void) {
    printf("=== Number Range Generator ===\n");
    printf("Author: Jaden Mardini\n\n");
    
    int start;
    
    if (!read_integer("Enter starting number: ", &start)) {
        return EXIT_FAILURE;
    }
    
    if (!validate_start(start)) {
        return EXIT_FAILURE;
    }
    
    generate_range(start, DEFAULT_RANGE);
    
    return EXIT_SUCCESS;
}
