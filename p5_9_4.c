#include <stdio.h>

#define S_VOL 8 

unsigned char *set_bit(unsigned char bit_array[], unsigned int bit_number ){
	unsigned char fetch_len[S_VOL];
	int len = sizeof(fetch_len) / sizeof(bit_array[0]);
	int sel_pt = bit_number / 8;
	int sel_bit = bit_number % 8;

	if( sel_bit == 0 && sel_pt != 0 ){
		sel_pt--;
		sel_bit = 8;
	}
	else{
		;
	}

	bit_array[len - 1 - sel_pt] |= (1 << (sel_bit - 1));

	return bit_array;	
}


unsigned char *clear_bit(unsigned char bit_array[], unsigned int bit_number ){
	//int i = 0;
	unsigned char fetch_len[S_VOL];
	int len = sizeof(fetch_len) / sizeof(bit_array[0]);
	int sel_pt = bit_number / 8;
	int sel_bit = bit_number % 8;

	if( sel_bit == 0 && sel_pt != 0 ){
		sel_pt--;
		sel_bit = 8;
	}
	else{
		;
	}

	bit_array[len - 1 - sel_pt] &= ~(1 << (sel_bit - 1));

	return bit_array;	
}


unsigned char *assign_bit(unsigned char bit_array[], unsigned int bit_number, int value ){
	unsigned char fetch_len[S_VOL];
	int len = sizeof(fetch_len) / sizeof(bit_array[0]);
	int sel_pt = bit_number / 8;
	int sel_bit = bit_number % 8;

	if( sel_bit == 0 && sel_pt != 0 ){
		sel_pt--;
		sel_bit = 8;
	}
	else{
		;
	}
	
	if( !value ){
		bit_array[len - 1 - sel_pt] &= ~(1 << (sel_bit - 1));
	}
	else{
		bit_array[len - 1 - sel_pt] |= (1 << (sel_bit - 1));
	}

	return bit_array;	
}


int test_bit(unsigned char bit_array[], unsigned int bit_number ){
	int ret_val;
	unsigned char fetch_len[S_VOL];
	int len = sizeof(fetch_len) / sizeof(bit_array[0]);
	int sel_pt = bit_number / 8;
	int sel_bit = bit_number % 8;

	if( sel_bit == 0 && sel_pt != 0 ){
		sel_pt--;
		sel_bit = 8;
	}
	else{
		;
	}

	if (bit_array[len - 1 - sel_pt] &  (1 << (sel_bit - 1))){
		ret_val = 1;
	}
	else{
		ret_val = 0;
	}

	return ret_val;	
}


typedef union{
	unsigned char space[S_VOL];
}space_allo;



int main(void){
	unsigned int bit_num;
	unsigned char *ret_val_pt;
	int i;
	int value;
	int bit_val_test;

	space_allo set_bit_array = {0x0};

	/*space_allo clear_bit_array;
	for( i = 0; i < S_VOL; i++ ){
		clear_bit_array.space[i] = 0xFF;
	}
		
	space_allo assign_bit_array;
	for( i = 0; i < S_VOL; i++ ){
		assign_bit_array.space[i] = 0xFF;
	}
	*/

	space_allo test_bit_array;
	for( i = 0; i < S_VOL; i++ ){
		test_bit_array.space[i] = 0xFF;
	}

	printf("Select bit number(1~64):");
	scanf("%d", &bit_num);

	//printf("Select Value! (0 or 1):");
	//scanf("%d", &value);

	bit_val_test = test_bit(test_bit_array.space, bit_num);
	
	printf("The %d(st/nd/rd/th) bit is %d.\n", bit_num, bit_val_test);

	/*for( i = 0; i < S_VOL; i++ ){
		printf("%d\n", *(ret_val_pt + i));
	}
	*/
	

	return 0;
}
