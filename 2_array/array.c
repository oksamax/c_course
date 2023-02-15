#include <stdio.h>

int main(void)
{
	int square_matrix[3][3] = {0}, reverse_array[5] = {0}, traingular_array[4][4] = {0}, snail_array[10][10] = {0};
	int i = 0, j = 0 , c = 1, counter_0 = 0, counter_n = 0, counter_c = 0, k = 1;
	
	//1
	printf("\n1.square_matrix[3][3]\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			square_matrix[i][j] = c;
			printf("%d ",square_matrix[i][j]);
			c++;
		}
		printf("\n");
	}

	//2
	printf("\n2.reverse_array[5]\n");
	printf("Specify a value for an array element\n");
	for(i = 0; i < 5; i++){
		printf("element[%d]=",i+1);
		scanf("%d",&reverse_array[i]);
	}
	for(i = 0; i < 5; i++)
		printf("%d ",reverse_array[4-i]);
	printf("\n");

	//3
	printf("\n3.traingular_array[4][4]\n");
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			traingular_array[i][j] = (i+j<3)?0:1;
			printf("%d ",traingular_array[i][j]);
		}
		printf("\n");
	}

	//4
	printf("\n4.snail_array\n");
	printf("Enter snail size:\n n=");
	scanf("%d",&c);
	counter_0 = 0;
	counter_n = c;
	counter_c = c;
	i = 0;
	j = 0;

	if(c == 1){
		snail_array[0][0] = k;
	}
	else if(c > 1){
		while(counter_c >1){
			i = counter_0;
			j = counter_0;
			while(j < counter_n){
				snail_array[i][j] = k;
				k++;
				j++;
			}
			j--;
			i++;
			while(i < counter_n){
				snail_array[i][j] = k;
				k++;
				i++;
                        }
                        i--;
			j--;
			while(j > counter_0-1){
				snail_array[i][j] = k;
				k++;
				j--;
			}
			j++;
			i--;
			while(i > counter_0){
				snail_array[i][j] = k;
				k++;
				i--;
			}
			++counter_0;
			--counter_n;
			counter_c-=2;

		}
	}

	if (c % 2 != 0)
		snail_array[c/2][c/2] = k;



	for(i = 0; i < c; i++){
		for (j = 0; j < c; j++){
			printf("%3d ",snail_array[i][j]);
		}
		printf("\n");
	}


	return 0;
}
