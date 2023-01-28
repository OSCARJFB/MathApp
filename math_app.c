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
		exit(EXIT_FAILURE);
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
			exit(EXIT_FAILURE);
		}
	}

	input[index] = '\0';

	return input;
}

void runTests(Addition add, Subtraction sub, Multiplication mult, Division div)
{
	bool testing = true;
	int typeOfTest = 1;
	result *head = NULL;

	system("clear");
	printf("\n");
	
	while (testing && i < 10)
	{
		typeOfTest = rand() % 4 + 1;
		switch (typeOfTest)
		{
		case addition:
			typeOfTest = runAdditionTest(add, typeOfTest, head);
		case subtraction:
			typeOfTest = runSubtractionTest(sub, typeOfTest, head);
		case multiplication:
			typeOfTest = runMultiplicationTest(mult, typeOfTest, head);
		case division:
			typeOfTest = runDivisionTest(div, typeOfTest, head);
		case no_test:
			break;
		}
		++i;
	}

	free(head);
	head = NULL;
}

int runAdditionTest(Addition add, int typeOfTest, result *head)
{
	int answer = 0;
	clock_t t_s = 0, t_n = 0;
	double seconds = 0.0;

	if (add.status == false)
	{
		return typeOfTest + 1;
	}

	add.term_a = rand() % add.max_range + add.min_range;
	add.term_b = rand() % add.max_range + add.min_range;
	add.sum = add.term_a + add.term_b;

	t_s = clock();
	printf("%d + %d = ", add.term_a, add.term_b);
	answer = convertInputToInt();
	t_n = clock();

	seconds = (double)(t_n - t_n) / CLOCKS_PER_SEC;
	addResultToNode(&head, seconds, add.term_a, add.term_b, answer, add.sum, '+');

	if (answer == add.sum)
	{
		printf("Answer: %d was provided in: %f seconds which is correct.\n", add.sum, seconds);
	}
	else
	{
		printf("Answer: %d was provided in: %f seconds which is wrong.\n", add.sum, seconds);
	}

	return no_test;
}

int runSubtractionTest(Subtraction sub, int typeOfTest, result *head)
{
	float answer = 0;
	clock_t t_s = 0, t_n = 0;
	double seconds = 0.0;

	if (sub.status == false)
	{
		return typeOfTest + 1;
	}

	sub.term_a = rand() % sub.max_range + sub.min_range;
	sub.term_b = rand() % sub.max_range + sub.min_range;
	sub.sum = sub.term_a - sub.term_b;

	t_s = clock();
	printf("%d - %d = ", sub.term_a, sub.term_b);
	answer = convertInputToInt();
	t_n = clock();

	seconds = (double)(t_n - t_n) / CLOCKS_PER_SEC;
	addResultToNode(&head, seconds, sub.term_a, sub.term_b, answer, sub.sum, '-');

	if (answer == sub.sum)
	{
		printf("Answer: %d was provided in: %lf seconds which is correct.\n", sub.sum, seconds);
	}
	else
	{
		printf("Answer: %d was provided in: %lf seconds which is wrong.\n", sub.sum, seconds);
	}

	return no_test;
}

int runMultiplicationTest(Multiplication mult, int typeOfTest, result *head)
{
	int answer = 0.0f;
	clock_t t_s = 0, t_n = 0;
	double seconds = 0.0;

	if (mult.status == false)
	{
		return typeOfTest + 1;
	}

	mult.factor_a = rand() % mult.max_range + mult.min_range;
	mult.factor_b = rand() % mult.max_range + mult.min_range;
	mult.product = mult.factor_a * mult.factor_b;

	t_s = clock();
	printf("%d * %d = ", mult.factor_a, mult.factor_b);
	answer = convertInputToInt();
	t_n = clock();

	seconds = (double)(t_n - t_n) / CLOCKS_PER_SEC;
	addResultToNode(&head, seconds, mult.factor_a, mult.factor_b, answer, mult.product, '*');

	if (answer == mult.product)
	{
		printf("Answer: %d was provided in: %f seconds which is correct.\n", mult.product, seconds);
	}
	else
	{
		printf("Answer: %d was provided in: %f seconds which is wrong.\n", mult.product, seconds);
	}

	return no_test;
}

int runDivisionTest(Division div, int typeOfTest, result *head)
{
	int answer = 0;
	clock_t t_s = 0, t_n = 0;
	double seconds = 0.0;

	if (div.status == false)
	{
		return typeOfTest + 1;
	}

	do
	{
		div.numerator = rand() % div.max_range + div.min_range;
		div.denominator = rand() % div.max_range + div.min_range;
	} while (div.numerator == 0 || div.denominator == 0 || div.numerator % div.denominator > 0);

	div.numerator = div.denominator > div.numerator ? div.denominator : div.numerator;
	div.quotient = div.numerator / div.denominator;

	t_s = clock();
	printf("%d / %d = ", div.numerator, div.denominator);
	answer = convertInputToInt();
	t_n = clock();

	seconds = (double)(t_n - t_n) / CLOCKS_PER_SEC;
	addResultToNode(&head, seconds, div.numerator, div.denominator, answer, div.quotient, '/');

	if (answer == div.quotient)
	{
		printf("Answer: %d was provided in: %f seconds which is correct.\n", div.quotient, seconds);
	}
	else
	{
		printf("Answer: %d was provided in: %f seconds which is wrong.\n", div.quotient, seconds);
	}

	return no_test;
}

int convertInputToInt(void)
{
	long answer = 0;
	char *input = NULL, *endptr = NULL;
	bool getAnswer = true;

	while (getAnswer)
	{
		input = getString();
		errno = 0;
		answer = strtol(input, &endptr, 10);
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

void addResultToNode(result **head, double seconds, int a, int b,
					 int user_answer, int correct_answer, char operator)
{
	if (*head == NULL)
	{
		addFirstNode(*head, seconds, a, b,
					 user_answer, correct_answer, operator);
		return;
	}

	result *new_node = malloc(sizeof(result));
	if (new_node == NULL)
	{
		printf("addResultFromTest: Invalid nullptr error.");
		exit(EXIT_FAILURE);
	}

	new_node->seconds = seconds;
	new_node->a = a, new_node->b = b;
	new_node->user_answer = user_answer, new_node->correct_answer = correct_answer;
	new_node->operator= operator;
	new_node->next = NULL;

	result *current_node = *head;
	while (current_node != NULL)
	{
		current_node = current_node->next;
	}

	current_node->next = new_node->next;
}

void addFirstNode(result *head, double seconds, int a, int b,
				  int user_answer, int correct_answer, char operator)
{
	head = malloc(sizeof(result));
	if (head == NULL)
	{
		printf("addResultFromTest: Invalid nullptr error.");
		exit(EXIT_FAILURE);
	}

	head->seconds = seconds;
	head->a = a, head->b = b;
	head->user_answer = user_answer, head->correct_answer = correct_answer;
	head->operator= operator;
	head->next = NULL;
}
