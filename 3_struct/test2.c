#include <stdio.h>

struct struct2 {
	char a;
	int b;
}__attribute__((packed));

int main(void)
{
	struct struct2 *ptr_str2 = NULL;
	char str[10] = {'A',0,0,0,0,'B',0,0,0,0};
	
	for(int i = 0; i < 10000000; i++){
	ptr_str2 = (struct struct2*)&str;
	printf("%c %d\n",ptr_str2->a,ptr_str2->b);
	}
	ptr_str2++;
	printf("%c %d\n",ptr_str2->a,ptr_str2->b);


	

	return 0;
}
