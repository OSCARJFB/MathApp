/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#ifndef MATH_APP_STRUCTS_H
#define MATH_APP_STRUCTS_H

// Data structure keeping track of the addition operator.
typedef struct Addition
{
    int term_a, term_b, sum;
    int min_range, max_range;
    bool status;
} Addition;

// Data structure keeping track of the subtraction operator.
typedef struct Subtraction
{
    int term_a, term_b, sum;
    int min_range, max_range;
    bool status;
} Subtraction;

// Data structure keeping track of the multiplication operator.
typedef struct Multiplication
{
    int factor_a, factor_b, product;
    int min_range, max_range;
    bool status;
} Multiplication;

// Data structure keeping track of the division operator.
typedef struct Division
{
    int numerator, denominator, quotient;
    int min_range, max_range;
    bool status;
} Division;

#endif // MATH_APP_STRUCTS_H