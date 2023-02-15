#include <stdio.h>

struct struct1 {
	char a;
	int b;
};

int main(void)
{
	struct struct1 *ptr_str1 = NULL;
	char str[10] = {'A',0,0,0,0,'B',0,0,0,0};
	
	for(int i = 0; i < 10000000; i++){
		ptr_str1 = (struct struct1*)&str;
		printf("%c %d\n   ",ptr_str1->a,ptr_str1->b);
	}

	return 0;
}
