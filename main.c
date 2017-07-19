#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CONTROL_SIZE 51
#define SIZE 50

/* This program is coded by Deniz Simsek, 030120427 */

int main( void )
{	
	int ROWS = 11; // (ROWS - 1) is the number of games.
	int COLUMNS = 6; // Number of columns.
	int i, j, a, b, x; // Iterators.
	int globe[ SIZE ]; 
	int control[ CONTROL_SIZE ];
	int guessed, zero=0, one=0, two=0, three=0, four=0, five=0, six=0;
	
	srand ( time(NULL) );
	
	for( a = 0; a < SIZE; a++ ){
		globe[ a ] = a + 1;
	}
	
	int lottery[ ROWS ][ COLUMNS + 1 ];
	
	//	Open file.
	FILE *myLottery = myLottery = fopen("lotteryResults.txt","w");
	
	for( i = 0; i < ROWS; i++ ){
		
		//	Results of the week.
		if( i == 0 ){
			printf(">> The results of the week: \n");
			fprintf(myLottery, "\nThe results of the week: \n");
		}
		
		//	Control array reset.    
		for( b = 0; b < CONTROL_SIZE; b++ ){
		    control[ b ] = 0;
		}
		
		//	guessed reset.
		guessed = 0;
		   	
		for( j = 0; j < COLUMNS; j++ ){
				
			//	Filling the columns of the array with random, non-repetitive numbers.	
		    do{
		    x = rand() % 49;
		    }while( control[globe[x]] != 0 );
		
	    	++control[globe[x]];
	        lottery[i][j] = globe[x];
		    printf("%5d", lottery[i][j]);
		    fprintf(myLottery, "%5d", lottery[i][j]);
	    }
		
		//	Checking the match numbers with the results of the week (first row of the array).	
	    if( i > 0 ){
			for(a = 0; a < COLUMNS; a++){
				for(b = 0; b < COLUMNS; b++){
					if( lottery[i][a] == lottery[0][b] ){
				        guessed++;
			        }
				}
		    }
		    
		    //	Seventh elements of the rows filled with the number of correct guess.
			lottery[i][6] = guessed;
			printf("|%5d guessed in GAME # %d", guessed, i);
			fprintf( myLottery,"|%5d guessed in GAME # %d", guessed, i);
			
			//	Total for each # of matches.
			switch( guessed ){
		    	case 1:
			    	++one;
				    break;
				case 2:
					++two;
					break;
				case 3:
					++three;
					break;
				case 4:
					++four;
					break;
				case 5:
					++five;
					break;
				case 6:
					++six;
					break;
				default:
					++zero;
					break;
	    	}
		}
	    
	    //	One blank line after the first row.
	    if( i == 0){
	    	printf("\n");
	    	fprintf(myLottery,"\n");
		}
		
		//	One blank line after the all process finished.
	    fprintf(myLottery,"\n");
		printf("\n");
	}
	
	printf("\n>> Total 0: %d\n"
	       ">> Total 1: %d\n"
		   ">> Total 2: %d\n"
		   ">> Total 3: %d\n"
		   ">> Total 4: %d\n"
		   ">> Total 5: %d\n"
		   ">> Total 6: %d\n", zero, one, two, three, four, five, six);
		   
	fprintf(myLottery,
	       "\n>> Total 0: %d\n"
	       ">> Total 1: %d\n"
		   ">> Total 2: %d\n"
		   ">> Total 3: %d\n"
		   ">> Total 4: %d\n"
		   ">> Total 5: %d\n"
		   ">> Total 6: %d\n", zero, one, two, three, four, five, six);
	
	fclose( myLottery );
	
    printf("\n");
    
	system("pause");
	return 0;
}
