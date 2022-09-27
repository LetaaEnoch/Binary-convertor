/************************************************************************************************
 * Program name: binaryconvertor                                                                *
 * Function: This program converts a number from decimal to binary or from binary to decimal    *
 ************************************************************************************************/
#include <stdio.h>
#include <math.h>

//check it

//constants
#define SIZE 8 //maximum number of binary digits

//function prototpes
void toBinary(int x, int ans_array[]);
void binaryPrint( int ans_array[] );
int toDecimal( int x );

int main(void)
{
    //the variable to store the user's choice
    int choice = 0;
    	
    printf("\n\nBinaryconvertor\n\n");
    
    here:
    	
    printf("What would you like to do?\n");
    printf("----------------------------------\n");
    printf("\n1. Binary to decimal\n");
    printf("\n2. Decimal to Binary\n");
    printf("\n----------------------------------\n");
    printf("\n(Enter 1 or 2, 0 to quit)\n");
    
    //this do while loop recurs till a valid value is entered for 'choice'
    do{
    	printf("\n==> ");
    	scanf("%d", &choice);
    	if(choice == 0)
    	{
    		printf("\nGoodbye!\n\n\n");
    		exit(0);
		}
		else if(choice != 1 && choice != 2)
    	{
    		fprintf(stderr, "\nInvalid input\n");
		}
	}while( choice != 1 && choice != 2 && choice != 0);
    
    int nbr;
    printf("\nEnter the number: ");
    scanf("%d", &nbr);
    printf("\n\nAnswer: ");
    
    if(choice == 1)
    {
		int ans = toDecimal(nbr);
		
		//function 'toDecimal' returns -1 in case the user gives nbr a non-binary value
		if(ans == -1)
			goto here;
		
		printf("\n%d", ans);
	}
    
    else
    {
    	int binary_array[SIZE];
		toBinary(nbr, binary_array);
	}
    printf("\n\n|\n|\n|\n|\n\n");
    goto here;
    
    return 0;
}

/******************************************************************** 
 * Function name: toBinary											*
 * Purpose: toBinary converts a given binary number to decimal		*
 ********************************************************************/
 void toBinary(int x, int ans_array[])
 {
 	// y = x%2 to find the remaninder
 	int y;
 	
 	//a loop to calculate the binary of x and store digits in ans_array
 	for(int i = 0; i < SIZE; i++)
 	{
 		y = x%2;
 		if(x > 1)
 		{
 			x = x/2;
 			ans_array[i] = y;
		 }
		 
		 else if(x == 1)
		 {
		 	ans_array[i] = 1;
		 	x = 0;
		 }
		 
		 else{
		 	ans_array[i] = 0;
		 }
	 }
	 
	 //call function binaryPrint to print the answer
	 binaryPrint( ans_array );
 	
 }
 
/****************************************************************************************
 * Function name: binaryPrint															*
 * Purpose: binaryPrint prints the binary answer obtained from the function 'toBinary'	*
 ****************************************************************************************/
 void binaryPrint( int ans_array[] )
 {
 	for(int j = SIZE - 1; j>= 0; j--)
 	{
 		printf("%d", ans_array[j]);
	 }
 }
 
/*****************************************************************************************
 * Function name: toDecimal 															 *
 * Purpose: toDecimal calculates the decimal form of a given binary number	           	 *
 *****************************************************************************************/
int toDecimal( int x )
{
	int num_array[SIZE];
	int p, i;
	
	//this loop finds out the number of digits the binary number given is made up of
	for(i = 0; i < SIZE; i++)
	{
		p = x % 10;
		
		//a test to check if the given number is a binary number
		if(p != 1 && p != 0)
		{
			fprintf(stderr, "Not a binary number.\n\n");
			printf("\n\n|\n|\n|\n\n");
			return -1;
		}
		
		num_array[i] = p;
		x = x/10;
		
		if(x == 0)
			break;
	}

	int ans = 0;
	int q;
	
	//a loop to multiply each binary digit by 2 raised to the corresponding power
	for(int j = 0; j <= i; j++)
	{
		q = pow(2, j);
		ans = ans + num_array[j] * q;
	}
	
	return ans;
}