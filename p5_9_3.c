#include <stdio.h>


unsigned int reverse_bits(unsigned int value, int bit_len){
	unsigned int rev_val;
	int bit_num;
	for(bit_num = 0; bit_num < bit_len; bit_num++){
		if(value & 1 << bit_num)
			rev_val |= (1 << (bit_len - 1 - bit_num));
		else
			rev_val &= (~(1 << (bit_len - 1 - bit_num)));
	}
	return rev_val; 
}


int main(void){
	unsigned int value;
	int bit_len = (sizeof(unsigned int) * 8);
	printf("Please enter an unsigned integer: ");
	scanf( "%u", &value);
	printf("The reverse bits value of %d is: %u\n", value, reverse_bits(value, bit_len));
	return 0;
}
