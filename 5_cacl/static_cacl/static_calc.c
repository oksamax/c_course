#include "libcalc.h"
#include <stdio.h>

int main(void)
{
	float first_number = 0, second_number = 1;
	int item = 0;

	do {
		printf("Calculator menu:\n1. Addition of two numbers\n2. Subtraction of two numbers\n3. Multiplication of two numbers\n4. Division of two numbers\n5. Exit\n");
		printf("Enter the item:");
		scanf("%d",&item);
		printf("\n");
		if(item == 1){
			printf("addition result = first number + second number\n\n");
			printf("Enter the first number:");
			scanf("%f",&first_number);
			printf("Enter the second number:");
			scanf("%f",&second_number);
			printf("addition result = %.1f\n\n\n",add(first_number,second_number));
		}
		else if(item == 2){
			printf("subtraction result = first number - second number\n\n");
			printf("Enter the first number:");
			scanf("%f",&first_number);
			printf("Enter the second number:");
			scanf("%f",&second_number);
			printf("subtraction result = %.1f\n\n\n",sub(first_number,second_number));
		}

		else if(item == 3){
			printf("multiplication result = first number * second number\n\n");
			printf("Enter the first number:");
			scanf("%f",&first_number);
			printf("Enter the second number:");
			scanf("%f",&second_number);
			printf("multiplication result = %.2f\n\n\n",multi(first_number,second_number));
		}

		else if(item == 4){
			printf("division result = first number / second number\n\n");
			printf("Enter the first number:");
			scanf("%f",&first_number);
			printf("Enter the second number:");
			scanf("%f",&second_number);
			printf("division result = %.2f\n\n\n",div(first_number,second_number));

		}
		else if(item != 5) printf("The entered item isn't in the menu!\n");
	} while (item !=5);

	return 0;
}
