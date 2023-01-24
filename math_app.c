/*
	Writen by: Oscar Bergström
	https://github.com/OSCARJFB
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include "math_app_macros.h"
#include "math_app_prototypes.h"
#include "math_app_structs.h"
#include "math_app_enums.h"

int main(void)
{
	srand(time(NULL));
	runApplication();

	return EXIT_SUCCESS;
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

	const char *msg = "Would you like to turn on the addition operator, yes? press (y): ";
	add.status = useOperator(msg) == true ? true : false;
	if (add.status)
	{
		getMinMax(&add.min_range, &add.max_range);
	}

	return add;
}

Subtraction setUpSubtraction(void)
{
	Subtraction sub;

	const char *msg = "Would you like to turn on the subtraction operator, yes? press (y): ";
	sub.status = useOperator(msg) == true ? true : false;
	if (sub.status)
	{
		getMinMax(&sub.min_range, &sub.max_range);
	}

	return sub;
}

Multiplication setUpMultiplication(void)
{
	Multiplication mult;

	const char *msg = "Would you like to turn on the multiplication operator, yes? press (y): ";
	mult.status = useOperator(msg) == true ? true : false;
	if (mult.status)
	{
		getMinMax(&mult.min_range, &mult.max_range);
	}

	return mult;
}

Division setUpDivision(void)
{
	Division div;

	const char *msg = "Would you like to turn on the division operator, yes? press (y): ";
	div.status = useOperator(msg) == true ? true : false;
	if (div.status)
	{
		getMinMax(&div.min_range, &div.max_range);
	}

	return div;
}

bool useOperator(const char *msg)
{
	char *input = NULL;
	bool use = false;

	printf("%s", msg);
	input = getString();
	use = strcmp(input, "y") == 0 || strcmp(input, "Y") == 0 ? true : false;

	free(input);
	input = NULL;

	return use;
}

void getMinMax(int *min, int *max)
{
	if (min == NULL || max == NULL)
	{
		printf("Error nullptr at: getMinMax");
		exit(-1);
	}

	char *input = NULL, *endptr = NULL;
	bool setMin = true, setMax = true;
	long result = 0;
	const char *min_msg = "Set the minimum value for this operator: ";
	const char *max_msg = "Set the maximum value for this operator: ";

	while (setMin || setMax)
	{
		setMin == true ? printf("%s", min_msg) : printf("%s", max_msg);
		input = getString();
		errno = 0;
		result = strtol(input, &endptr, 10);
		if (errno != 0 || input == endptr)
		{
			printf("Invalid input\n");
		}
		else if (setMin)
		{
			*min = (int)result;
			setMin = false;
		}
		else if (setMax && *min < (int)result)
		{
			*max = (int)result;
			setMax = false;
		}
		else
		{
			printf("Maximum value must be greater than minimum value\n");
		}

		free(input);
		input = NULL;
		endptr = NULL;
	}
}

char *getString(void)
{
	int index = 0, key_pressed = 0;
	char *input = NULL;
	input = malloc(sizeof(char));
	if (input == NULL)
	{
		exit(-1);
	}

	while ((key_pressed = getchar()) != EOF)
	{
		if (key_pressed == ENTER)
		{
			break;
		}

		input[index++] = (char)key_pressed;
		input = realloc(input, (index + 1) * sizeof(char));
		if (input == NULL)
		{
			exit(-1);
		}
	}

	input[index] = '\0';

	return input;
}

void runTests(Addition add, Subtraction sub, Multiplication mult, Division div)
{
	bool testing = true;
	int typeOfTest = 1;

	system("clear");
	printf("Test started: \n");

	while (testing)
	{
		typeOfTest = rand() % 4 + 1;
		switch (typeOfTest)
		{
		case addition:
			typeOfTest = runAdditionTest(add, typeOfTest);
		case subtraction:
			typeOfTest = runSubtractionTest(sub, typeOfTest);
		case multiplication:
			typeOfTest = runMultiplicationTest(mult, typeOfTest);
		case division:
			typeOfTest = runDivisionTest(div, typeOfTest);
		case no_test:
			break;
		}
	}
}

int runAdditionTest(Addition add, int typeOfTest)
{
	float answer = 0.0f;

	if (add.status == false)
	{
		return typeOfTest + 1;
	}

	add.term_a = rand() % add.max_range + add.min_range;
	add.term_b = rand() % add.max_range + add.min_range;
	add.sum = add.term_a + add.term_b;

	printf("%d + %d = ", add.term_a, add.term_b);
	answer = convertInputToFloat();

	if (answer == add.sum)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong, it's %f\n", add.sum);
	}

	return 5;
}

int runSubtractionTest(Subtraction sub, int typeOfTest)
{
	float answer = 0.0f;

	if (sub.status == false)
	{
		return typeOfTest + 1;
	}

	sub.term_a = rand() % sub.max_range + sub.min_range;
	sub.term_b = rand() % sub.max_range + sub.min_range;
	sub.sum = sub.term_a - sub.term_b;

	printf("%d - %d = ", sub.term_a, sub.term_b);
	answer = convertInputToFloat();

	if (answer == sub.sum)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong, it's %f\n", sub.sum);
	}
}

int runMultiplicationTest(Multiplication mult, int typeOfTest)
{
	float answer = 0.0f;

	if (mult.status == false)
	{
		return typeOfTest + 1;
	}

	mult.factor_a = rand() % mult.max_range + mult.min_range;
	mult.factor_b = rand() % mult.max_range + mult.min_range;
	mult.product = mult.factor_a * mult.factor_b;

	printf("%d * %d = ", mult.factor_a, mult.factor_b);
	answer = convertInputToFloat();

	if (answer == mult.product)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong, it's %f\n", mult.product);
	}
}

int runDivisionTest(Division div, int typeOfTest)
{
	float answer = 0.0f;

	if (div.status == false)
	{
		return typeOfTest + 1;
	}

	do
	{
		div.numerator = rand() % div.max_range + div.min_range;
		div.denominator = rand() % div.max_range + div.min_range;
	} while (div.numerator == 0 || div.denominator == 0);

	div.numerator = div.denominator > div.numerator ? div.denominator : div.numerator;
	div.quotient = div.numerator / div.denominator;

	printf("%d / %d = ", div.numerator, div.denominator);
	answer = convertInputToFloat();

	if (answer == div.quotient)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong the correct answer is %f\n", div.quotient);
	}
}

float convertInputToFloat(void)
{
	float answer = 0.0f;
	char *input = NULL, *endptr = NULL;
	bool getAnswer = true;

	while (getAnswer)
	{
		input = getString();
		errno = 0;
		answer = strtof(input, &endptr);
		if (errno != 0 || input == endptr)
		{
			printf("Invalid input\n");
		}
		else
		{
			getAnswer = false;
		}

		free(input);
		input = NULL;
		endptr = NULL;
	}

	return answer;
}
