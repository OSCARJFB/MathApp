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
		getMinMax(&add.min_range, &add.min_range);
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
		getMinMax(&sub.min_range, &sub.min_range);
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
		getMinMax(&mult.min_range, &mult.min_range);
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
		getMinMax(&div.min_range, &div.min_range);
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
	char *input = NULL, *endptr = NULL;
	bool setMin = true, setMax = true;
	long result = 0;

	while (setMax)
	{
		printf("Set the minimum value for this operator: ");
		input = getString();
		errno = 0;
		result = strtol(input, &endptr, 10);
		if (errno != 0 || input == endptr)
		{
			perror("strtol");
		}
		else
		{
			*min = (int)result;
			setMax = false;
		}

		free(input);
		input = NULL;

		setMax = false;
	}

	while (setMin)
	{
		printf("Set the maximum value for this operator: ");
		input = getString();
		errno = 0;
		result = strtol(input, &endptr, 10);
		if (errno != 0 || input == endptr)
		{
			perror("strtol");
		}
		else
		{
			*min = (int)result;
			setMin = false;
		}

		free(input);
		input = NULL;

		setMin = false;
	}

}

char *getString(void)
{
	int index = 0, key_pressed = 0;
	char *input = malloc(sizeof(char));
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

	input[index + 1] = '\0';

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
	int answer = 0;

	if (add.status == false)
	{
		return typeOfTest + 1;
	}

	add.term_a = rand() % add.max_range + add.min_range;
	add.term_b = rand() % add.max_range + add.min_range;
	add.sum = add.term_a + add.term_b;

	printf("%d + %d = ", add.term_a, add.term_b);
	scanf("%d", &answer);
	printf("\n");

	if (answer == add.sum)
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
	int answer = 0;

	if (sub.status == false)
	{
		return typeOfTest + 1;
	}

	sub.term_a = rand() % sub.max_range + sub.min_range;
	sub.term_b = rand() % sub.max_range + sub.min_range;
	sub.sum = sub.term_a - sub.term_b;

	printf("%d - %d = ", sub.term_a, sub.term_b);
	scanf("%d", &answer);
	printf("\n");

	if (answer == sub.sum)
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
	int answer = 0;

	if (mult.status == false)
	{
		return typeOfTest + 1;
	}

	mult.factor_a = rand() % mult.max_range + mult.min_range;
	mult.factor_b = rand() % mult.max_range + mult.min_range;
	mult.product = mult.factor_a * mult.factor_b;

	printf("%d * %d = ", mult.factor_a, mult.factor_b);
	scanf("%d", &answer);
	printf("\n");

	if (answer == mult.product)
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
	int answer = 0;

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
	scanf("%d", &answer);
	printf("\n");

	if (answer == div.quotient)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong!\n");
	}
}
