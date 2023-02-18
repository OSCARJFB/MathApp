/*
	Writen by: Oscar Bergström
	https://github.com/OSCARJFB
*/

#ifndef MATH_APP_PROTOTYPES_H
#define MATH_APP_PROTOTYPES_H
#include "math_app_structs.h"

/// @brief Runs the application until escape sequence is hit.
void runApplication(void);

/// @brief initialization for addition.
/// @return struct with operation data.
Addition setUpAddition(void);

/// @brief initialization for subtraction.
/// @return struct with operation data.
Subtraction setUpSubtraction(void);

/// @brief initialization for multiplication.
/// @return struct with operation data.
Multiplication setUpMultiplication(void);

/// @brief initialization for division.
/// @return struct with operation data.
Division setUpDivision(void);

/// @brief initialization for division.
/// @return struct with operation data.
Division setUpDivision(void);

/// @brief This function allow the user to set the different math operators ON or OFF.
/// @param char*
/// @return A bool, either true or false. Determining if the operation is ON or OFF.
bool useOperator(const char *);

/// @brief Gets the minimum and maximum range of an mathimatical operation.
/// @param int*
/// @param int*
void getMinMax(int *, int *);

/// @brief Get user input.
/// @return a char pointer containing user input.
char *getString(void);

/// @brief Controller for running the math tests.
/// @param struct
/// @param struct
/// @param struct
/// @param struct
void runTests(Addition, Subtraction, Multiplication, Division);

/// @brief Addition test query.
int runAdditionTest(Addition, int, result *);

/// @brief Addition test query.
int runSubtractionTest(Subtraction, int, result *);

/// @brief Addition test query.
int runMultiplicationTest(Multiplication, int, result *);

/// @brief Division test query.
/// @param struct
/// @param int
/// @return an integer value, which provides information about what type of test to proceed to next.
int runDivisionTest(Division, int, result *);

/// @brief Consverts the user input to a floating point decimal value.
/// @param char*
/// @return user input as a floating point value.
int convertInputToInt(void);

/// @brief
/// @param struct**
/// @param double
/// @param int
/// @param int
/// @param char
/// @param int
/// @param int
void addResultToNode(result **, double, int, int,
					 int, int, char);

/// @brief
/// @param struct*
/// @param double
/// @param int
/// @param int
/// @param char
/// @param int
/// @param int
void addFirstNode(result *, double, int, int,
				  int, int, char);

#endif // MATH_APP_PROTOTYPES_H
