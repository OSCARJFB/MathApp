#ifndef MATH_APP_PROTOTYPES_H
#define MATH_APP_PROTOTYPES_H
#include "math_app_structs.h"

/// @brief Runs the application until escape sequence is hit.
void runApplication(void);

/// @brief 
/// @param  
/// @return 
Addition setUpAddition(void);

/// @brief 
/// @param  
/// @return 
Subtraction setUpSubtraction(void);

/// @brief 
/// @param  
/// @return 
Multiplication setUpMultiplication(void);

/// @brief 
/// @param  
/// @return 
Division setUpDivision(void);

/// @brief 
/// @param  
/// @return 
Subtraction setUpSubtraction(void);

/// @brief 
/// @param  
/// @return 
Multiplication setUpMultiplication(void);

/// @brief 
/// @param  
/// @return 
Division setUpDivision(void);

/// @brief This function allow the user to set the different math operators ON or OFF.
/// @param char*  
/// @return A bool, either true or false. Determining if the operation is ON or OFF.
bool useOperator(const char*);

void getMinMax(int*, int*);

char *getString(void);

void runTests(Addition, Subtraction, Multiplication, Division);

int runAdditionTest(Addition, int);

int runSubtractionTest(Subtraction, int);

int runMultiplicationTest(Multiplication, int);

int runDivisionTest(Division, int);


#endif //MATH_APP_PROTOTYPES_H
