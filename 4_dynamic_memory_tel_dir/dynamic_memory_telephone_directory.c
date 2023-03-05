#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct user_info {
	char firstname[20];
	char surname[20];
	char number[15];
};

int main(void)
{
	struct user_info *user = NULL;
	int item = 0, start_counter = 0, end_counter = 0, i = 0, find_counter = 0, delete_counter = 0;
	char find_number[15] = "0", delete_name[20] = "0";

	do{
		puts("Menu:\n1.Add user\n2.Telephone directory \n3.Find user\n4.Delete user\n5.Exit\n");
		printf("Enter menu item:");
		scanf("%d",&item);
		if (item == 1){ //Add user
			if(end_counter<10){
				user = realloc(user,(start_counter+1)*sizeof(struct user_info));
				if(user == NULL){
					printf("Dynamic memory not allocated!\n");
					exit(EXIT_FAILURE);
				}
				printf("Enter name(20 characters):");
				scanf("%s",(user + start_counter) -> firstname);
				while(strlen((user + start_counter) -> firstname)>20){
					printf("You have entered more than 20 characters!\n");
					printf("Enter name(20 characters):");
					scanf("%s",(user + start_counter) -> firstname);
                                }
				printf("Enter surname(20 characters):");
				scanf("%s",(user + start_counter) -> surname);
				while(strlen((user + start_counter) -> surname)>20){
					printf("You have entered more than 20 characters!\n");
					printf("Enter surname(20 characters):");
					scanf("%s",(user + start_counter) -> surname);
				}

				printf("Enter number(15 characters):");
				scanf("%s",(user + start_counter) -> number);
				while(strlen((user + start_counter) -> number)>15){
					printf("You have entered more than 15 characters!\n");
					printf("Enter number(15 characters):");
					scanf("%s",(user + start_counter) -> number);
				}
				start_counter++;
				end_counter++;
			}
			else printf("****** Telephone directory is full!");
		}
		else if (item == 2){ // Telephone directory
			if (start_counter == 0) printf("****** Telephone directory is empty!");
			else{
				for(i = 0; i < start_counter; i++){
					printf("****** %d. Firstname:%s  Surname:%s  Number:%s\n",i+1,(user + i) -> firstname, (user + i) -> surname, (user + i) -> number);
				}
			}
		}
		else if (item == 3){ // Find user
		if (start_counter == 0) printf("****** Telephone directory is empty!");
			else{
				printf("Enter user number(15 characters):");
                                scanf("%s",find_number);
				while(strlen(find_number) > 15){
					printf("You have entered more than 15 characters!\n");
					printf("Enter user number(15 characters):");
					scanf("%s",find_number);
				}
				for(i = 0; i < start_counter; i++){
					if(!strcmp(find_number, (user +i) -> number)){
						printf("****** firstname:%s  surname:%s  number:%s\n", (user + i) -> firstname, (user + i) -> surname, (user + i) ->  number);
						find_counter = 1;
					}
				}
				if (find_counter == 0) printf("****** User isn't found!\n");
				find_counter = 0;
			}
		}
		else if (item == 4){ //Delete user
			if (start_counter == 0) printf("****** Telephone directory is empty!");
/*			else if (start_counter == 1){
				printf("Enter user name:");
				scanf("%s",delete_name);
				if(!strcmp(delete_name,user[0].firstname)){
					start_counter = 0;
					printf("****** User \'%s\' deleted!\n",user[0].firstname);
                                                strcpy(user[0].firstname,"0");
                                                strcpy(user[0].surname,"0");
                                                strcpy(user[0].number,"0");
                                        }
                                }
			*/
			else{
				printf("Enter user firstname (20 characters):");
				scanf("%s",delete_name);
				if(strlen(delete_name) > 20){
					printf("You have entered more than 20 characters!\n");
					printf("Enter user firstname (20 characters):");
					scanf("%s",delete_name);
				}

				for(i = 0; i < start_counter; i++){
					if(!strcmp(delete_name, (user + i) -> firstname)){
						printf("****** User \'%s\' deleted!\n",(user + i) -> firstname);
						strcpy((user + i) -> firstname, (user + start_counter - 1) -> firstname);
						strcpy((user + i) -> surname, (user + start_counter - 1) -> surname);
						strcpy((user + i) -> number, (user + start_counter - 1) -> number);
						start_counter--;
						i--;
						delete_counter = 1;
					}
				if (delete_counter == 1) user = realloc(user, (start_counter + 1) * sizeof(struct user_info));
				}
			}
                }
		else if (item !=5) printf("****** This item isn't on the menu!!!\n");
		puts("\n");
	}while (item !=5);

	free(user);

        return 0;
}


