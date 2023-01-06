#ifndef MATH_APP_STRUCTS_H
#define MATH_APP_STRUCTS_H

/// @brief This data structure holds information about the addition operations.
/// @brief Use as follows: term_a + term_b = sum.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
struct Addition
{
    int term_a, term_b, sum;
    int min_range_a, max_range_b;
    char *desc;
};

/// @brief This data structure holds information about the subtraction operations.
/// @brief Use as follows: term_a - term_b = sum.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
struct Subtraction
{
    int term_a, term_b, sum;
    int min_range_a, max_range_b;
    char *desc;
};

/// @brief This data structure holds information about the multiplication operations.
/// @brief Use as follows: factor_a * factor_b = product.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
struct Multiplication
{
    int factor_a, factor_b, product;
    int min_range_a, max_range_b;
    char *desc;
};

/// @brief This data structure holds information about the division operations.
/// @brief Use as follows: numerator / denominator = quotient.
/// @brief min_range_a = Possible minimum value of generated numbers.
/// @brief max_range_b = Possible maximum value of generated numbers.
/// @brief *desc, should hold text data on how this mathimatical operation is done.
struct Division
{
    int numerator, denominator, quotient;
    int min_range_a, max_range_b;
    char *desc;
};

/// @brief In future add exponentiation, nthroot and logarithm 


#endif // MATH_APP_STRUCTS_H