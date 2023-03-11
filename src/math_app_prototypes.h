/*
	Writen by: Oscar Bergström
	https://github.com/OSCARJFB
*/

#ifndef MATH_APP_PROTOTYPES_H
#define MATH_APP_PROTOTYPES_H
#include "math_app_structs.h"

// Runs the application until a escape sequence is hit.
void runApplication(void);

// initialization for addition operator.
Addition setUpAddition(void);

// initialization for subtraction operator.
Subtraction setUpSubtraction(void);

// initialization for multiplication operator.
Multiplication setUpMultiplication(void);

// initialization for division operator.
Division setUpDivision(void);

// This function allows the user to set the different math operators ON or OFF.
bool useOperator(const char *msg);

// Gets the minimum and maximum range of an mathimatical operation.
void getMinMax(int *min, int *max);

// Gets user input.
char *getString(void);

// A controller for running the math tests.
void runTests(Addition add, Subtraction sub, Multiplication mult, Division div);

// Run a addition test question.
int runAdditionTest(Addition add, int typeOfTest);

// Run a multiplication test question.
int runSubtractionTest(Subtraction sub, int typeOfTest);

// Run a multiplication test question.
int runMultiplicationTest(Multiplication mult, int typeOfTest);

// Run a division test question.
int runDivisionTest(Division div, int typeOfTest);

// Converts user input to integer value
int convertInputToInt(void);

#endif // MATH_APP_PROTOTYPES_H
