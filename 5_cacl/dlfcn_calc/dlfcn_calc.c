#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(void)
{
	void *library;
	float (*func)(float a, float b);
	char calc_func_name[4][20] = {'0','0','0','0'};
	char menu[4][20] = {"Additional","Subtraction","Multiplication","Division"};
	int menu_counter = 4, menu_item = 0, counter = 0;
	int calc_item = 0;
	int i = 0;

	do{
		if(menu_counter != 0)
		{
			printf("Select calculator functions:\n+-----+----------------+\n|item |Function name:  |\n");
			for(i = 0; i < menu_counter; i++)
				printf("|%-5d|.%-15s|\n",i+1,menu[i]);
			printf("|%-5d|.%-15s|\n",i+1,"Exit");
			printf("+-----+----------------+\n\n");
			printf("Select the item:");
			scanf("%d",&menu_item);
			menu_item--;
		}

		if((menu_item >= 0)&&(menu_item <= (menu_counter-1))){
			strcpy(calc_func_name[counter],menu[menu_item]);
			counter++;
			strcpy(menu[menu_item],menu[i-1]);
			if(menu_counter != 0) menu_counter--;
			else break;
		}
		else if(menu_item == 0){
			strcpy(calc_func_name[counter],menu[menu_item]);
			break;
		}
		else if((menu_item < 0)||(menu_item > i))
			printf("You entered an invalid item!\n");	
	} while(menu_item != i);

	if (menu_counter == 4) exit(0);

	counter = 4 - menu_counter;
//	do{
		printf("Calculator menu:\n");
		for(i = 0; i < counter; i++)
		       printf("%d.%s of two numbers\n",i+1,calc_func_name[i]);
	//}




/*

	library = dlopen("/home/user/Desktop/c/git_hub/c_course/5_cacl/dlfcn_calc/libadd.so",RTLD_LAZY);
	if(!library){
		printf("dlopen ERROR!\n");
		exit(EXIT_FAILURE);
	}

	func = dlsym(library,"add");
	printf("10 + 20 = %.1f\n",func(10,20));
*/
	return 0;
}
