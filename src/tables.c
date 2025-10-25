/**
 * @file tables.c
 * @brief Mathematical Tables Generator
 * @author Jaden Mardini
 * 
 * Professional mathematical table generator with squares, cubes,
 * and square roots with comprehensive validation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_LIMIT 1
#define MAX_LIMIT 100

/**
 * @brief Validates input limits
 */
static int validate_limits(int low, int high) {
    if (low < MIN_LIMIT || low > MAX_LIMIT) {
        fprintf(stderr, "Error: Lower limit must be between %d and %d\n", 
                MIN_LIMIT, MAX_LIMIT);
        return 0;
    }
    
    if (high < MIN_LIMIT || high > MAX_LIMIT) {
        fprintf(stderr, "Error: Upper limit must be between %d and %d\n", 
                MIN_LIMIT, MAX_LIMIT);
        return 0;
    }
    
    if (high < low) {
        fprintf(stderr, "Error: Upper limit must be >= lower limit\n");
        return 0;
    }
    
    return 1;
}

/**
 * @brief Safely reads integer input with validation
 */
static int read_limit(const char* prompt, int min_val, int max_val, int* value) {
    printf("%s", prompt);
    
    if (scanf("%d", value) != 1) {
        fprintf(stderr, "Error: Invalid input format\n");
        return 0;
    }
    
    /* Clear input buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    if (*value < min_val || *value > max_val) {
        fprintf(stderr, "Error: Value must be between %d and %d\n", min_val, max_val);
        return 0;
    }
    
    return 1;
}

/**
 * @brief Prints formatted table header
 */
static void print_header(void) {
    printf("\n");
    printf("+-----+----------+----------+---------+\n");
    printf("| Num |  Square  |   Cube   |  Sqrt   |\n");
    printf("+-----+----------+----------+---------+\n");
}

/**
 * @brief Prints formatted table footer
 */
static void print_footer(void) {
    printf("+-----+----------+----------+---------+\n");
}

/**
 * @brief Prints a single table row
 */
static void print_row(int num) {
    long long square = (long long)num * num;
    long long cube = (long long)num * num * num;
    double sqrt_val = sqrt((double)num);
    
    printf("| %3d | %8lld | %8lld | %7.2f |\n", 
           num, square, cube, sqrt_val);
}

/**
 * @brief Generates and displays mathematical table
 */
static void generate_table(int low, int high) {
    print_header();
    
    for (int i = low; i <= high; i++) {
        print_row(i);
    }
    
    print_footer();
    
    printf("\nTable generated for range %d to %d (%d entries)\n", 
           low, high, high - low + 1);
}

/**
 * @brief Main program entry point
 */
int main(void) {
    printf("=== Mathematical Tables Generator ===\n");
    printf("Author: Jaden Mardini\n\n");
    
    int low, high;
    
    if (!read_limit("Enter lower limit (1-100): ", MIN_LIMIT, MAX_LIMIT, &low)) {
        return EXIT_FAILURE;
    }
    
    if (!read_limit("Enter upper limit (1-100): ", low, MAX_LIMIT, &high)) {
        return EXIT_FAILURE;
    }
    
    if (!validate_limits(low, high)) {
        return EXIT_FAILURE;
    }
    
    generate_table(low, high);
    
    return EXIT_SUCCESS;
}
