#include <stdio.h>
#include <string.h>


struct user_info {
	char name[20];
	char surname[20];
	char number[15];
};

int main(void)
{
	struct user_info user[10];
	int item = 0, start_counter = 0, end_counter = 1, i = 0;
	char find_number[20] = "0", delete_name[20] = "0";

	for (i = 0; i < 10; i++){
		strcpy(user[i].name,"0");
		strcpy(user[i].surname,"0");
		strcpy(user[i].number,"0");
	}

	do{
		puts("Menu:\n1.Add user\n2.Telephone directory \n3.Find user\n4.Delete user\n5.Exit\n");
		printf("Enter menu item:");
		scanf("%d",&item);
		if (item == 1){ //Add user
			if(end_counter <=10){
				printf("Enter name(20 characters):");
				scanf("%s",user[start_counter].name);
				printf("Enter surname(20 characters):");
				scanf("%s",user[start_counter].surname);
				printf("Enter number(15 characters):");
				scanf("%s",user[start_counter].number);
				start_counter++;
				end_counter++;
			}
			else printf("telephone directory is full");

		}
		else if (item == 2){ // Telephone directory
			if (start_counter == 0) printf("telephone directory is empty");
			else{
				for(i = 0; i < start_counter; i++){
					printf("user:%s  surname:%s  number:%s\n",user[i].name, user[i].surname, user[i].number);
				}
			}

		}
		else if (item == 3){ // Find user
			if (start_counter == 0) printf("telephone directory is empty");
			else
			{
				printf("Enter user number:");
				scanf("%s",find_number);
				for(i = 0; i < start_counter; i++){
				       if(!strcmp(find_number,user[0].number)){
					       printf("user:%s  surname:%s  number:%s\n",user[i].name, user[i].surname, user[i].number);
					       break;
				       }
				}
				if (i == start_counter) printf("user isn't found!\n");
				i = 0;
			}

		}
		else if (item == 4){ //Delete user
			if (start_counter == 0) printf("telephone directory is empty");
			else if (start_counter == 1)
				{
					printf("Enter user name:");
					scanf("%s",delete_name);
					if(strcmp(delete_name,user[0].name)){
						start_counter = 0;
						strcpy(user[0].name,"0");
						strcpy(user[0].surname,"0");
						strcpy(user[0].number,"0");
					}
				}
		}
		else if (item !=5) printf("This item isn't on the menu!!!\n");
		puts("\n");
	}while (item !=5);

	return 0;
}
