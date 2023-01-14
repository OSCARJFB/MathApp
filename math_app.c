#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "math_app_macros.h"
#include "math_app_prototypes.h"
#include "math_app_structs.h"

int main(void)
{
	srand(time(NULL));
	runApplication();

	return 0;
}

void runApplication()
{

	bool isRunning = true, initialized = false;

	Addition add;
	Subtraction sub;
	Multiplication mult;
	Division div;

	while (isRunning)
	{
		if (!initialized)
		{
			add = setUpAddition();
			sub = setUpSubtraction();
			mult = setUpMultiplication();
			div = setUpDivision();
			initialized = true;
		}

		runTests(add, sub, mult, div);
	}
}

Addition setUpAddition(void)
{
	Addition add;
	bool initializing;
	int khit;

	printf("Would you like to turn on the addition operator(1):");
	scanf("%d", &khit);
	printf("\n");

	initializing = khit == 1 ? true : false;
	add.status = initializing == true ? true : false;

	while (initializing)
	{
		printf("Set minimum value for this operator: ");
		scanf("%d", &add.min_range);
		printf("\n");

		printf("Set maximum value for this operator: ");
		scanf("%d", &add.max_range);
		printf("\n");

		initializing = false;
	}

	return add;
}


Subtraction setUpSubtraction(void)
{
	Subtraction sub;
	bool initializing;
	int khit;

	printf("Would you like to turn on the subtraction operator(1):");
	scanf("%d", &khit);
	printf("\n");

	initializing = khit == 1 ? true : false;
	sub.status = initializing == true ? true : false;
	
	while (initializing)
	{
		printf("Set minimum value for this operator: ");
		scanf("%d", &sub.min_range);
		printf("\n");

		printf("Set maximum value for this operator: ");
		scanf("%d", &sub.max_range);
		printf("\n");

		initializing = false;
	}
	
	return sub;
}


Multiplication setUpMultiplication(void)
{
	Multiplication mult;
	bool initializing;
	int khit;
	
	printf("Would you like to turn on the multiplication operator(1):");
	scanf("%d", &khit);
	printf("\n");

	initializing = khit == 1 ? true : false;
	mult.status = initializing == true ? true : false;

	while (initializing)
	{
		printf("Set minimum value for this operator: ");
		scanf("%d", &mult.min_range);
		printf("\n");

		printf("Set maximum value for this operator: ");
		scanf("%d", &mult.max_range);
		printf("\n");

		initializing = false;
	}

	return mult;
}


Division setUpDivision(void)
{
	Division div;
	bool initializing;
	int khit;

	printf("Would you like to turn on the division operator(1):");
	scanf("%d", &khit);
	printf("\n");
	
	initializing = khit == 1 ? true : false;
	div.status = initializing == true ? true : false;

	while (initializing)
	{
		printf("Set minimum value for this operator: ");
		scanf("%d", &div.min_range);
		printf("\n");

		printf("Set maximum value for this operator: ");
		scanf("%d", &div.max_range);
		printf("\n");

		initializing = false;
	}

	return div;
}


void runTests(Addition add, Subtraction sub, Multiplication mult, Division div)
{
	bool testing = true;
	int typeOfTest;

	system("clear");
	printf("Test started: \n");
	
	while (testing)
	{
		typeOfTest = rand() % 4 + 1;
		switch (typeOfTest)
		{
		case 1:
			typeOfTest = runAdditionTest(add, typeOfTest);
		case 2:
			typeOfTest = runSubtractionTest(sub, typeOfTest); 
		case 3:
			typeOfTest = runMultiplicationTest(mult, typeOfTest);
		case 4:
			typeOfTest = runDivisionTest(div, typeOfTest); 	
		case 5:
			break;
		}
	}
}

int runAdditionTest(Addition add, int typeOfTest)
{
	int answer;

	if(add.status == false)
	{
		return typeOfTest + 1;
	}

	add.term_a = rand() % add.max_range + add.min_range;
	add.term_b = rand() % add.max_range + add.min_range;
	add.sum = add.term_a + add.term_b;

	printf("%d + %d = ", add.term_a, add.term_b);
	scanf("%d", &answer);
	printf("\n");

	if(answer == add.sum)
	{
		printf("Correct!\n");
	} 
	else 
	{
		printf("Wrong!\n");
	}

	return 5;
}

int runSubtractionTest(Subtraction sub, int typeOfTest)
{
	int answer;

	if(sub.status == false)
	{
		return typeOfTest + 1;
	}

	sub.term_a = rand() % sub.max_range + sub.min_range;
	sub.term_b = rand() % sub.max_range + sub.min_range;
	sub.sum = sub.term_a - sub.term_b;

	printf("%d - %d = ", sub.term_a, sub.term_b);
	scanf("%d", &answer);
	printf("\n");

	if(answer == sub.sum)
	{
		printf("Correct!\n");
	} 
	else 
	{
		printf("Wrong!\n");
	}
}

int runMultiplicationTest(Multiplication mult, int typeOfTest)
{
	int answer;

	if(mult.status == false)
	{
		return typeOfTest + 1;
	}

	mult.factor_a = rand() % mult.max_range + mult.min_range;
	mult.factor_b = rand() % mult.max_range + mult.min_range;
	mult.product = mult.factor_a * mult.factor_b;


	printf("%d * %d = ", mult.factor_a, mult.factor_b);
	scanf("%d", &answer);
	printf("\n");

	if(answer == mult.product)
	{
		printf("Correct!\n");
	} 
	else 
	{
		printf("Wrong!\n");
	}
}

int runDivisionTest(Division div, int typeOfTest)
{
	int answer;

	if(div.status == false)
	{
		return typeOfTest + 1;
	}

	div.numerator = rand() % div.max_range + div.min_range;
	div.denominator = rand() % div.max_range + div.min_range;
	div.numerator = div.denominator > div.numerator ? div.denominator : div.numerator;
	div.quotient = div.numerator / div.denominator;

	printf("%d / %d = ", div.numerator, div.denominator);
	scanf("%d", &answer);
	printf("\n");

	if(answer == div.quotient)
	{
		printf("Correct!\n");
	} 
	else 
	{
		printf("Wrong!\n");
	}
}

