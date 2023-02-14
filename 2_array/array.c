#include <stdio.h>

int main(void)
{
	int square_matrix[3][3] = {0}, reverse_array[5] = {0}, traingular_array[4][4] = {0}, snail_array[10][10] = {0};
	int i = 0, j = 0 , c = 1;
	
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

	c = 3;
	i = j = 0;

	int k = 1;
	//if(c%2){
	//	while(c>1)

	for(;j < c; j++){
		snail_array[i][j] = k;
                printf("el[%d][%d]=%d   ",i,j,snail_array[i][j]);
                k++;
	}
	j--;
	printf("\nj = %d\n",j);
	while(i < c){
                snail_array[i][j] = k;
		printf("el[%d][%d]=%d   ",i,j,snail_array[i][j]);
                k++;
                i++;
        }
	i--;
	printf("\ni = %d\n",i);

	j--;
	while(j > 0){
		snail_array[i][j] = k;
                k++;
                j--;
	}
	i--;
	while(i > 0)
	{
		snail_array[i][j] = k;
                k++;
                i--;
	}




	for(i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("%2d ",snail_array[i][j]);
		}
		printf("\n");
	}


	return 0;
}
