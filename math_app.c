#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "math_app_macros.h"
#include "math_app_prototypes.h"
#include "math_app_structs.h"

int main(void)
{
	runApplication();
	return 0;
}

void runApplication()
{

	bool isRunning = true, initialized = false;

	Addition add;
	Subtraction Sub;
	Multiplication Mult;
	Division Div;

	while(isRunning)
	{
		if(!initialized)
		{
			add = setUpAddition(); 
			//setUpSubtraction();
			//setUpDivision();
			//setUpMultiplication(); 
		}
		/* Test */
		isRunning = false;
	}
	/* Test */
	printf("%d\n", add.min_range);
	printf("%d\n", add.max_range);
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

	while(initializing)
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

/*
Subtraction setUpSubtraction(void)
{

}


Multiplication setUpMultiplication(void)
{

}


Division setUpDivision(void)
{

}
*/




