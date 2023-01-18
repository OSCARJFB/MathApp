#ifndef MATH_APP_PROTOTYPES_H
#define MATH_APP_PROTOTYPES_H
#include "math_app_structs.h"

/// @brief Runs the application until escape sequence is hit.
void runApplication(void);
void exitApp(void);
Addition setUpAddition(void);
Subtraction setUpSubtraction(void);
Multiplication setUpMultiplication(void);
Division setUpDivision(void);
Subtraction setUpSubtraction(void);
Multiplication setUpMultiplication(void);
Division setUpDivision(void);
/// @brief This function allow the user to set the different math operators ON or OFF.
/// @param char*  
bool useOperator(const char*);
void getMinMax(int*, int*);
char *getString(void);
void runTests(Addition, Subtraction, Multiplication, Division);
int runAdditionTest(Addition, int);
int runSubtractionTest(Subtraction, int);
int runMultiplicationTest(Multiplication, int);
int runDivisionTest(Division, int);


#endif //MATH_APP_PROTOTYPES_H
