#include <stdio.h>


//backtracking approach for eight-queens problem 


void Eight_Queens(int Q_row, int status[][8]){
	int i = Q_row; 
	int	j = 0;
	int Q_col;
	int j_posi;
	int flag = 0;
	int n = 0;
	int k, l;
	static int counter = 0;

	// Checking the very starting position for checking, when recursive func returns to upper layer.
	while( n < 8 ){
		if( status[Q_row][n] == 1 ){
			j = n;
			status[Q_row][n] = 0;
			break;
		}
		else{
			;
		}
		n++;
	}
	//Debugging MSG:printf("When func returns. Q_row = %d\n", Q_row );
	//printf("#1 new row init status: j:%d i:%d\n", j, i);
	
	//Checking if the current position is attacked by any pre-existing Queen, column coordinate +1 each time.
	while( j < 8 ){

	//Checking if Attacking Route exists in the vertical line. 
		i = 0;
		while( i < 8 ){
			if( status[i][j] != 1 ){
				flag = 1;
			}
			else{
				flag = 0;
				break;
			}
			i++;
		}
	//Debugging MSG: printf("col check flag: %d  j: %d\n", flag, j);
	
	//Based on vertical route checking result, return to checking next coordinate or GO ON.
		if( flag ){
			;
		}
		else{
			j++;
			continue;
		}

	//assigning 'i' back to the value of current row, because we moved it previously when did vertical checking
	//assinging value of 'j' to 'Q_col' to hold the value of current coordinate, followed by steps required to operate on 'j' 
		i = Q_row;	
		j_posi = j;

	//Debugging MSG: printf("start slope check flag:%d i:%d j:%d\n", flag, i, j);
		while( j >= 0 && i >= 0 ){
			if( status[i][j] != 1 ){
				flag = 1;
			}	
			else{
				flag = 0;
				break;
			}
			j--;
			i--;
		}

	//Debugging MSG: printf("No.1 slope flag(North_West):%d\n", flag);
	//if slope check passed, program goes on, if NOT, we go back to vertical check. 
		if( flag ){
			i = Q_row;
			j = j_posi;
		}
		else{
			j = j_posi;
			j++;
			continue;
		}

		while( j <= 7 && i >= 0 ){
			if( status[i][j] != 1 ){
				flag = 1;
			}	
			else{
				flag = 0;
				break;
			}
			i--;
			j++;
		}
				
	//Debugging MSG: printf("No.2 slope flag(North_East):%d\n", flag);
	//Debugging MSG: printf("slope check reslut flag: %d	i: %d j: %d\n ", flag, i, j);
		if( flag ){
			break;
		}
		else{
			j = j_posi;
			j++;
		}
	}

	Q_col = j_posi;

	//if no attacking route exists, setting the current position value to 1, mark Queen; printing current status of chessboard 
	if( flag ){
	//Debugging MSG:  printf("#-1 Qr:%d Qc:%d flag:%d\n", Q_row, Q_col, flag);
		status[Q_row][Q_col] = 1;
		
		for( k = 0; k < 8; k++ ){
			for(l = 0; l < 8; l++ ){
				printf("%d  ", status[k][l]);
			}
			printf("\n");	
		}	
		
	//if one Solution achieved, we increment the counter by 1.
		if( flag && Q_row == 7 ){
			counter += 1;
		}
		printf("solution number = %d\n", counter); 
		
		//Calling the function itself recursively, increment Q_row argument by 1, pass it to callee func, save and pass the status	
		//when the callee returns, we remove the Queen of last row, due to no solution for next row and need to go back.
	
		Eight_Queens(Q_row + 1, status);
		status[Q_row][Q_col] = 0;

	//if the callee func returns, moving the current Queen to next column cooridnate, and checking if it arrived at the last column coordinate. say, no further position to go. Base on this we have to return to upper layer one more time.
	//Base on that no solution when Queen at previous possible position, we move to next coordinate and start checking alternative solution for this( = last row from the callee's perspective ) row, by calling function itself recursively.
		
		if( Q_col >= 7 ){
			return;
		}
		else{
			status[Q_row][Q_col + 1] = 1;
			Eight_Queens(Q_row, status);
		}		
	}

	//if NO solution at all for this row, function returns.
	else{	
		return;		
	}
	
}



int main(void){
	//starting checking process from row #1(0 of array sub in C language)
	//here we choose 8X8-size two dimension array for storing status of chessboard 
	int Q_row = 0;
	int status[8][8];
	int i, j;
	
	//initializing the chessboard, a clear one.
	for( i = 0; i < 8; i++ ){
		for( j = 0; j < 8; j++ ){
			status[i][j] = 0;
		}	
	}

	Eight_Queens(Q_row, status);

	return 0;
}
