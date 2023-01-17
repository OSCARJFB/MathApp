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

	puts("Would you like to turn on the addition operator, yes(y) No(n):");
	add.status = useOperator() == true ? true : false;
	if (add.status)
	{
		getMinMax(&add.min_range, &add.min_range);
	}


	system("clear");

	return add;
}

Subtraction setUpSubtraction(void)
{
	Subtraction sub;

	puts("Would you like to turn on the subtraction operator, yes(y) No(n):");
	sub.status = useOperator() == true ? true : false;
	if (sub.status)
	{
		getMinMax(&sub.min_range, &sub.min_range);
	}

	system("clear");

	return sub;
}

Multiplication setUpMultiplication(void)
{
	Multiplication mult;

	puts("Would you like to turn on the multiplication operator, yes(y) No(n):");
	mult.status = useOperator() == true ? true : false;
	if (mult.status)
	{
		getMinMax(&mult.min_range, &mult.min_range);
	}

	system("clear");

	return mult;
}

Division setUpDivision(void)
{
	Division div;

	fputs("Would you like to turn on the division operator, yes(y) No(n): ", stdout);
	div.status = useOperator() == true ? true : false;
	if (div.status)
	{
		getMinMax(&div.min_range, &div.min_range);
	}

	system("clear");

	return div;
}

bool useOperator()
{
	int key_pressed = WHITESPACE;

	while (key_pressed != 'y' && key_pressed != 'Y' &&
		   key_pressed != 'n' && key_pressed != 'N')
	{
		key_pressed = getc(stdin);
	}

	return key_pressed == 'y' || key_pressed == 'Y' ? true : false;
}

void getMinMax(int *min, int *max)
{	
	char *input;
	bool setMin = true, setMax = true;
	while(setMax)
	{
		fputs("Set the maximum value for this operator: ", stdout);
		input = getString();
		free(input);
		setMax = false; 
	}
	puts(input);
}

char *getString()
{
	int index = 0, key_pressed = 0;
	char *input = malloc(sizeof(char));
	if(input == NULL)
	{
		exit(-1);
	}

	while((key_pressed = getchar()) != EOF)
	{	
		key_pressed = getchar(); 
		if(key_pressed == ENTER)
		{
			break;
		}

		input[index++] = (char)key_pressed; 
		input = realloc(input, (index + 1) * sizeof(char));
		if(input == NULL)
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
	int answer;

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
	int answer;

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
	int answer;

	if (div.status == false)
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

	if (answer == div.quotient)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong!\n");
	}
}
