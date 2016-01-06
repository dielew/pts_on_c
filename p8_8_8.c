#include <stdio.h>


//backtracking approach for eight-queens problem 


void valid_solution_count( int status[][8] ){
	int m, n;
	static int counter = 0;
	counter += 1;
	printf("Solution No. %d, details as followed:\n", counter); 
	for( m = 0; m < 8; m++ ){
		for(n = 0; n < 8; n++ ){
			printf("%d  ", status[m][n]);
		}
		printf("\n");	
	}	
	printf("\n");	
}    // this func is aimed to counting total number of valid solutions, and printing the solution details. 

int pre_row_queen_reset( int row, int col, int status[][8] ){
	for( ; col < 8 && (status[row][col] != 1); col += 1 ){
		;
	}	
	if( col >= 8 ){
		col = 0;
	}
	else{
		;
	}
	status[row][col] = 0;
	return col;   //return col value (col of outter layer queen inc by 1). If no queen at all, we set col to 0.
}

int vertical_route_detect( int col, int status[][8] ){
	int flag;
	int row;

	for( row = 0; row < 8 && status[row][col] != 1; row += 1 ){
		;
	}
	if( row > 7	){
		flag = 1;	
	}
	else{
		flag = 0;
	}
	return flag;
}    //to detect if any queen in vertical route, for current column value. Return T if clear route, F if not.


int slopeNW_route_detect( int row, int col, int status[][8] ){
	int flag;
	
	for( ;col >= 0 && row >= 0 && status[row][col] != 1; row -= 1, col -= 1){
		;
	}
	if( col < 0 || row < 0 ){
		flag = 1;
	}
	else{
		flag = 0;
	}
	return flag;
}

int slopeNE_route_detect( int row, int col, int status[][8] ){
	int flag;
	
	for( ;col < 8 && row >= 0 && status[row][col] != 1; row -= 1, col += 1){
		;
	}
	if( col >= 8 || row < 0 ){
		flag = 1;
	}
	else{
		flag = 0;
	}
	return flag;
}


void Eight_Queens(int current_row, int status[][8]){
	int	checking_col = 0;
	int flag;
	int flagV = 0;
	int flagNW = 0;
	int flagNE = 0;


	checking_col = pre_row_queen_reset(current_row, 0, status);
			
	//to check if current position being attacked by pre-existing Queens. If yes, column to be checked incremented by 1.
	flagV  = vertical_route_detect(checking_col, status);	
	flagNW = slopeNW_route_detect(current_row, checking_col, status);
	flagNE = slopeNE_route_detect(current_row, checking_col, status);
	while( checking_col < 8 && (!(flagV && flagNW && flagNE)) ){
		checking_col++;
		flagV  = vertical_route_detect(checking_col, status);	
		flagNW = slopeNW_route_detect(current_row, checking_col, status);
		flagNE = slopeNE_route_detect(current_row, checking_col, status);
	}
	if( checking_col >= 8 ){
		flag = 0;
	}
	else{
		flag = 1;
	}

	if( flag ){
		status[current_row][checking_col] = 1;
			//    obviously, if all tests OK, we mark the Queen in col we got finally.

		if( flag && current_row == 7 ){
			valid_solution_count(status);
		}
		else{
			;
		}   //    valid solution counting and 'chessboard' printing.

	
		Eight_Queens(current_row + 1, status);
		status[current_row][checking_col] = 0;
		//to call this function recursively, if it could find a solution for current row, save the status, recursively call itself for next row.	
		//If callee returns, which means unfortunately it failed to find a valid position for queen in current row, so we should remove the Queen of previous(outter layer) row. 

		//if the callee func returns, moving the current Queen to next column cooridnate, and checking if it arrived at the last column coordinate. say, no further position to go. Base on this we have to return to upper layer one more time.		
		if( checking_col >= 7 ){
			return;
		}
		else{
			status[current_row][checking_col + 1] = 1;
			Eight_Queens(current_row, status);
		}		
	}

	else{	
		return;		
	}   //      if NO solution at all for this row, function returns.
	
}


int main(void){
	//here we choose 8X8-size two dimension array for storing status of chessboard 
	int status[8][8];
	int i, j;	
	//initializing the chessboard, a clear one.
	for( i = 0; i < 8; i++ ){
		for( j = 0; j < 8; j++ ){
			status[i][j] = 0;
		}	
	}

	Eight_Queens(0, status);

	return 0;
}
