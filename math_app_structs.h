/*
	Writen by: Oscar Bergström
	https://github.com/OSCARJFB
*/

#ifndef MATH_APP_STRUCTS_H
#define MATH_APP_STRUCTS_H

/// @brief This data structure holds information about the addition operations.
/// @brief Use as follows: term_a + term_b = sum.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
/// @brief *Finally status is keeping track on wheter or not the operation is active or not.
typedef struct Addition
{
    int term_a, term_b, sum;
    int min_range, max_range;
    bool status;
}Addition;

/// @brief This data structure holds information about the subtraction operations.
/// @brief Use as follows: term_a - term_b = sum.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
/// @brief *Finally status is keeping track on wheter or not the operation is active or not.
typedef struct Subtraction
{
    int term_a, term_b, sum;
    int min_range, max_range;
    bool status;
}Subtraction;



/// @brief This data structure holds information about the multiplication operations.
/// @brief Use as follows: factor_a * factor_b = product.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
/// @brief *Finally status is keeping track on wheter or not the operation is active or not.
typedef struct Multiplication
{
    int factor_a, factor_b, product;
    int min_range, max_range;
    bool status;
}Multiplication;


/// @brief This data structure holds information about the division operations.
/// @brief Use as follows: numerator / denominator = quotient.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
/// @brief *Finally status is keeping track on wheter or not the operation is active or not.
typedef struct Division
{
    int numerator, denominator, quotient;
    int min_range, max_range;
    bool status;
}Division;

/// @brief This data structure is used as a linked list which stores the result of the math test.
typedef struct result
{
    double seconds; 
    int a, b;
    int user_answer, correct_answer;
    char operator;
    struct result *next;
}result;

#endif // MATH_APP_STRUCTS_H