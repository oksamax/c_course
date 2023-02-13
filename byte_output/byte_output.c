#include <stdio.h>

void byte_output(unsigned int a);

int main(void)
{
	unsigned int a = 0xFAB90324;

	printf("a = %08X\n",a);

	byte_output(a);

	a = a & 0xFF00FFFF;
	a = a | 0x00CC0000;
	printf("3 byte change (CC). a = %08X\n",a);

	return 0;
}

void byte_output(unsigned int a)
{
	int i = 0;
	while(i<4)
	{	
		printf("%d byte = %02X\n",i+1,(a>>i*8)&0xFF);
		i++;
	}
}
