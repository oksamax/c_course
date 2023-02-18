#include <stdio.h>
#include <string.h>


struct user_info {
	char firstname[20];
	char surname[20];
	char number[15];
};

int main(void)
{
	struct user_info user[10];
	int item = 0, start_counter = 0, end_counter = 0, i = 0;
	char find_number[20] = "0", delete_name[20] = "0";

	for (i = 0; i < 10; i++){
		strcpy(user[i].firstname,"0");
		strcpy(user[i].surname,"0");
		strcpy(user[i].number,"0");
	}

	do{
		puts("Menu:\n1.Add user\n2.Telephone directory \n3.Find user\n4.Delete user\n5.Exit\n");
		printf("Enter menu item:");
		scanf("%d",&item);
		if (item == 1){ //Add user
			if(end_counter <10){
				printf("Enter name(20 characters):");
				scanf("%s",user[start_counter].firstname);
				printf("Enter surname(20 characters):");
				scanf("%s",user[start_counter].surname);
				printf("Enter number(15 characters):");
				scanf("%s",user[start_counter].number);
				start_counter++;
				end_counter++;
			}
			else printf("****** Telephone directory is full!");

		}
		else if (item == 2){ // Telephone directory
			if (start_counter == 0) printf("****** Telephone directory is empty!");
			else{
				for(i = 0; i < start_counter; i++){
					printf("****** %d. Firstname:%s  Surname:%s  Number:%s\n",i+1,user[i].firstname, user[i].surname, user[i].number);
				}
			}

		}
		else if (item == 3){ // Find user
			if (start_counter == 0) printf("****** Telephone directory is empty!");
			else{
				printf("start_counter=%d\n",start_counter);
				printf("Enter user number:");
				scanf("%s",find_number);
				for(i = 0; i < start_counter; i++){
					printf("i=%d ",i);
				       if(!strcmp(find_number,user[i].number)){
					       printf("****** firstname:%s  surname:%s  number:%s\n",user[i].firstname, user[i].surname, user[i].number);
				       }
				}
				if (i == start_counter) printf("****** User isn't found!\n");
				i = 0;
			}

		}
		else if (item == 4){ //Delete user
			if (start_counter == 0) printf("****** Telephone directory is empty!");
			else if (start_counter == 1){
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
			else{
				printf("Enter user name:");
				scanf("%s",delete_name);
				for(i = 0; i < start_counter; i++){
					if(!strcmp(delete_name,user[i].firstname)){
						printf("****** User \'%s\' deleted!\n",user[1].firstname);
						strcpy(user[i].firstname,user[start_counter-1].firstname);
						strcpy(user[i].surname,user[start_counter-1].surname);
						strcpy(user[i].number,user[start_counter-1].number);
						start_counter--;
						i--;
					}
				}

			}
		}
		else if (item !=5) printf("****** This item isn't on the menu!!!\n");
		puts("\n");
	}while (item !=5);

	return 0;
}
