/*
 Description: <This program ask the user to choose from 3 option in a Menu, for the 
 				1st option it contains a pattern guesser which guess the 5th number of the 4 numbers series that
 				the user has input, if the users typed "-999" for the 1st input of this function it reverts back to the main menu.
 				The 2nd option is a series generator, it ask the users for values that will be needed to generate the series of numbers.
				If option 3 is choesn it just ends the whole program.>
 Programmed by: <Ford Ainstein Chung> <S13A>
 Last modified: <11/9/2022>
 Version: <1>
 [Acknowledgements: None]
*/


#include <stdio.h>


int convert_Binary(int);
int convert_Decimal(int);
int check_Prime(int);
void series_checker(int, int ,int , int, int, int, int);
void compute_pattern (int n1, int n2, int n3, int n4, 
					int* d1, int* d2, int* d3, int* d4,
					int* p1, int* p2, int* p3,
					int* p7,int* p8, int* p9);
void pattern_guesser();


//print the number series
void
inc_dec(int N, int X, int Y, int nMenu)
{
	int i, nResult = Y;
	
	printf("\n--------------------------------\n");
	printf("RESULT:\n\n");
	for (i = 1; i <= X; i++)
	{
		printf("%d ", nResult);
		switch (nMenu)
		{
			case 1:
			case 2:	nResult += N;
					break;
			case 3:	
			case 4:	nResult += 2;
					break;
			case 5:	
					nResult++;
					while (check_Prime(nResult) == 0)
					{
						nResult++;
					}
					break;
		}
		
	}
	printf("\n\n--------------------------------\n");	
}


//Prints the error sign if invalid
void
check_Valid(int nMenu, int* pX, int* pY, int* nValid)
{
	
	printf("Enter X: ");
	scanf("%d", pX);
	
	if(*pX < 2)
	{
		printf("\n--------------------------------\n");
		printf("\nERROR - X value is not greater than 2!!\n\n");
		printf("\n--------------------------------\n");
		*nValid = 0;
	}
	else
	{
		printf("Enter Y: ");
		scanf("%d", pY);
		
		switch (nMenu)
		{
			case 1:	
			case 2: break;
			case 3:	if (*pY % 2 != 0)
					{
						printf("\n--------------------------------\n");
						printf("\nERROR - Starting number is not Even\n\n");
						printf("\n--------------------------------\n");
						*nValid = 0;	
					}
					break;
			case 4:	if( *pY % 2 != 1)
					{
						printf("\n--------------------------------\n");
						printf("\nERROR - Starting number is not Odd\n\n");
						printf("\n--------------------------------\n");
						*nValid = 0;
					}
					break;
			case 5: if(check_Prime(*pY) == 0)
					{
						printf("\n--------------------------------\n");
						printf("\nERROR - Starting number is not Prime\n\n");
						printf("\n--------------------------------\n");
						*nValid = 0;
					}
		}
	}
}

//second option of the main menu
void
number_generator()
{
	int nMenu, N, X, Y;
	int nValid = 1; //if the N value is negative it gets update to 0
	
	
	
	do
	{
		printf("\n--------------------------------\n");
		printf("\nWelcome to Number Series Generator\n\n");
		printf("--------------------------------\n");
		
		printf("\nPlease Enter the Number of your choice:\n\n");
		printf("(1) Increments of N\n");
		printf("(2) Decrememts of N\n");
		printf("(3) Incrementing Even Series\n");
		printf("(4) Incrementing Odd Series\n");
		printf("(5) Incrementing Prime Series\n");
		printf("(6) Return to Menu\n");
		printf("\nEnter Number: ");
		scanf("%d", &nMenu);
		
		printf("\n--------------------------------\n");
		if(nMenu == 1 || nMenu == 2)
		{
			if(nMenu == 1)
			{
				
				printf("Increments of N\n");
				printf("--------------------------------\n");
			} 
			else 
			{
				printf("Decrements of N\n");
				printf("--------------------------------\n");
			}
			
			printf("\nInstruction:\n");
			printf("\nYou'll be asked to Input the ff:\n\n");
			if (nMenu == 1)
			{
				printf("N - Incrementing value (CANNOT NENEGATIVE)\n");
			}	
			else printf("N - Decrementing value (CANNOT NENEGATIVE)\n");
			
			printf("X - The number of values generated (SHOULD BE ATLEAST 2)\n");
			printf("Y - Starting number of the series\n\n");
			printf("\n--------------------------------\n\n");
			
			
			printf("Enter N: ");
			scanf("%d", &N);
			
			
			//test if N negative 
			if(N < 0)
			{
				// if N is negative the value of the checker is 0 
				nValid = 0;
				printf("--------------------------------\n");
				printf("\nERROR negative N value.\n\n");
				printf("--------------------------------\n");
			}
			else
			{
				check_Valid(nMenu, &X, &Y, &nValid);
				
				if (nValid == 1)
				{
					if (nMenu == 1)
					{
						inc_dec(N, X, Y, nMenu);
					}
					else
					{
						inc_dec(N * -1, X, Y, nMenu);
					}
				}
			}
		}
		else if (nMenu == 3)
		{
			
			printf("Incrementing Even Series\n");
			printf("--------------------------------\n");
			printf("\nInstruction:\n");
			printf("\nYou'll be asked to Input the ff: \n\n");
			printf("X - The number of values generated (SHOULD BE ATLEAST 2)\n");
			printf("Y - Starting number of the series (SHOULD BE EVEN)\n\n");
			printf("\n--------------------------------\n\n");
			
			
			check_Valid(nMenu, &X, &Y, &nValid);
			if (nValid == 1)
				{
					inc_dec(N, X, Y, nMenu);
				}
		}
		else if (nMenu == 4)
		{
			printf("Incrementing Odd Series\n");
			printf("--------------------------------\n");
			printf("\nInstruction:\n");
			printf("\nYou'll be asked to Input the ff: \n\n");
			printf("X - The number of values generated (SHOULD BE ATLEAST 2)\n");
			printf("Y - Starting number of the series (SHOULD BE ODD)\n\n");
			printf("\n--------------------------------\n\n");
			
	
			check_Valid(nMenu, &X, &Y, &nValid);
			if (nValid == 1)
				{
					inc_dec(N, X, Y, nMenu);
				}
				
		}
		else if(nMenu == 5)
		{
			printf("Incrementing Prime Series\n");
			printf("--------------------------------\n");
			printf("\nInstruction:\n");
			printf("\nYou'll be asked to Input the ff: \n\n");
			printf("X - The number of values generated (SHOULD BE ATLEAST 2)\n");
			printf("Y - Starting number of the series (SHOULD BE PRIME)\n\n");
			printf("\n--------------------------------\n\n");
			
			
			check_Valid(nMenu, &X, &Y, &nValid);
			if (nValid == 1)
				{
					inc_dec(N, X, Y, nMenu);
				}
				
		}
		else if(nMenu == 6)
		{
		}
		else printf("\nInvalid Input\n");
	}while (nValid == 0 || nMenu != 6 );
	
	
}


//main menu
int 
main()
{
	int nMenu;
	
	
	do
	{
		printf("--------------------------------\n");
		printf("\n%18s\n\n", "MENU");
		printf("--------------------------------\n");
		printf("\nInstruction: \n\nEnter the number of the option. \n\n");
		printf(" (1) Pattern Guesser\n");
		printf(" (2) Number Generator\n");
		printf(" (3) Exit\n");
		printf("\nEnter the number: ");
		scanf("%d", &nMenu);
		
		switch(nMenu)
		{
			case 1: pattern_guesser();
					break;
			case 2: number_generator();
					break;
			case 3: printf("\nBYE BYE!!\n");
					break;
			default: printf("Invalid Input!!\n\n");
		}
	} while (nMenu != 3);
	
	return 0;
}




//converting the decimal value to binary
int
convert_Binary(int nDec)
{
	int nBin, nFinal = 0, nResult = 1;
	
	
	while (nDec > 0)
 	{
 		nBin = nDec % 2;
 		nDec = nDec / 2;
		
		nResult = nResult * 10 + nBin; 
 	} 

	while (nResult != 0)
	{
		nBin = nResult % 10;
		nResult /= 10;

		nFinal = nFinal * 10 + nBin; 

	}
	nFinal /= 10;

	
	return nFinal;
}

//convert the binary to decimal
int
convert_Decimal(int nInput)
{
	
	int nNum, nResult;
	int i, j;
	int mod = 10, div = 1, nExp = 2, nFinal = 0;
	int nCount = nInput;
	
	
	//counts the how many numbers
	for (i = 1; nCount > 9; i++)
	{
		nCount /= 10;
	}
	

	// exp poisiton
	for (j = 0; j < i; j++)
	{
		//seperate the number from rigth to left
		nNum = nInput % mod / div;
		
		
		if(j == 0)
		{
			nResult = nNum * 1;
		}
		else
		{
			//base multiplied to 2 raised to the position of the number
			nResult = nNum * nExp;
			
			nExp *= 2;
		}
		
		//updates to get the next digit of the number
		mod *= 10;
		div *= 10;
		nFinal += nResult;
		
	}
	return nFinal;
	
}

//Prints what type of series
void
series_checker(int n1, int n2, int n3, int n4, int s1, int s2, int s3)
{
	int nPrime;
	int p1, p2, p3, p4;
	int i, nTemp = n1, nValid = 1;
	//int nTrue = 0; // to make sure condition is true
	

	
	if (n1 % 2== 0 && n2 % 2 == 0 && n3 % 2 == 0 && n4 % 2 == 0)
	{
		if(s1 && s2 && s3 == 2)
		{
			printf("\nEven Series");
		}
		
	}
	else
	{
		//returns 1 if prime, if all is == prime
		
		p1 = check_Prime(n1);
		p2 = check_Prime(n2);
		p3 = check_Prime(n3);
		p4 = check_Prime(n4);
		
		// if 0 the series is not prime
		nPrime =  p1 && p2 && p3 && p4 == 1;
		if (nPrime == 1)
		{
			//nTemp will be the next prime value, if it is not equal to the input then its not a prime series
			for (i = 1; i <= 3; i++)
			{
				nTemp++;
				while (check_Prime(nTemp) == 0)
					{
						nTemp++;
					}
					
				if(i == 1)
				{
					if (n2 != nTemp)
					{
						nValid = 0; 
					}
				}
				else if(i == 2)
				{
					if (n3 != nTemp)
					{
						nValid = 0; 
					}
				}	
				else if(i == 3)
				{
					if (n4 != nTemp)
					{
						nValid = 0; 
					
					}
				}
			}
			
			if (nValid == 1)
			{
				printf("\nPrime Series");
			}	
		}	
			
	
		
		else if (n1 % 2== 1 && n2 % 2 == 1 && n3 % 2 == 1 && n4 % 2 == 1)
		{
			if (s1 && s2 && s3 == 2)
			{
				printf("\nOdd Series");
			}
			
		} 
	}

}

//check if number is prime
int
check_Prime(int nInput)
{
	int i, nValid = 1;
	
	if (nInput == 1)
	{
		nValid = 0;
	}
	else
	{
		for (i = 2 ; i < nInput; i++)
		{
			//return nTemp as 0 if the number is not prime
			if (nInput % i == 0)
			{
				nValid = 0;
			}
		}
	}
		
	return nValid;
}

//1st option in the main menu
void
pattern_guesser()
{
	int n1, n2, n3, n4;							//users input
	int s1, s2, s3, s4, s5, s6, s7, s8, s9; 	//series outputs
	int d1, d2, d3, d4;							//binary converted to decimal
	int nBin;									//5th number binary
	
	printf("\n--------------------------------\n");
	printf("\nWelcome to Pattern Guesser!!\n");
	printf("\n--------------------------------\n");
	printf("\nInstruction:\n");
	printf("\n--------------------------------\n");
	printf("Enter any number in a series\n\nEX:\n\n2 4 6 8\n3 6 9 12\n");
	printf("\nTo exit input \"-999\" as the first input in a series\n");
	printf("\n--------------------------------\n");
	
	do
	{
		printf("\nPlease Enter 4 number in a Series:\n\n");
		printf("1st: ");
		scanf("%d", &n1);
		if(n1 != -999)
		{
			printf("2nd: ");
			scanf("%d", &n2);
			printf("3rd: ");
			scanf("%d", &n3);
			printf("4th: ");
			scanf("%d", &n4);
			
			//compute for the pattern of the series
			compute_pattern(n1, n2, n3, n4, &d1, &d2, &d3, &d4,
							&s1, &s2, &s3, &s7, &s8, &s9);
			
			printf("\n--------------------------------\n");
			
			//Test if all the sequence is the same if yes it proceed to this condition
			if (s1 == s2 && s2 == s3 && s3 == s1)
			{
				printf("\nThe 5th number is = %d", n4 + s1);
				printf("\n\nReason:\n\n");
				if (s1 < 0)
				{
					printf ("Decrements of %d", s1 * -1);
				}
				else
				{
					printf("Increments of %d", s1);
				} 
				
				series_checker(n1, n2, n3, n4, s1, s2, s3);
				
			}
			//for the  M N series
			else if(s1 == s3 && s2 != s3)
			{
				printf("\nThe 5th number is = %d", n4 + s2);
				printf("\n\nReason:\n\n");
				printf("%+d %+d sequence", s1, s2);
				series_checker(n1, n2, n3, n4, s1, s2, s3);
			}
			//*N series
			else if (n2 % n1 == 0 &&  n3 % n2 == 0 && n4 % n3 == 0)
			{
				//why its in here,, because there will be a bug if it is not placed inside
				s4 = n2 / n1;
				s5 = n3 / n2;
				s6 = n4 / n3;
				
				if (s4 == s5 && s5 == s6 && s6 == s4)
				{
					printf("\nThe 5th number is = %d", n4 * s4);
					printf("\n\nReason:\n\n");
					printf ("*%d sequence", s4);
				}
				//additional feature, M N series but for the *N series
				else if(s4 == s6 && s5 != s6)
				{
					printf("\nThe 5th number is = %d", n4 * s5);
					printf("\n\nReason:\n\n");
					printf("*%d *%d sequence", s4, s5);
				}
				else printf("\nNo relation!\n");
			}
			//binary series
			else if(s7 == s8 && s8 == s9 && s9 == s7)
			{
				nBin = convert_Binary(d4 + s7);
				printf("\nThe 5th number is = %d", nBin);
				printf("\nBinary Series");
			}
			else printf("\nNo relation!\n");
			printf("\n--------------------------------\n");
		}
			
	}while(n1 != -999);
	
}

//computes for the difference of each pairs in a series
void
compute_pattern (int n1, int n2, int n3, int n4, 
				int* d1, int* d2, int* d3, int* d4,
				int* p1, int* p2, int* p3,
				int* p7,int* p8, int* p9)
{
	//addition and subtraction
	*p1 = n2 - n1;
	*p2 = n3 - n2;
	*p3 = n4 - n3;
	
	//Binary series
	*d1 = convert_Decimal(n1);
	*d2 = convert_Decimal(n2);
	*d3 = convert_Decimal(n3);
	*d4 = convert_Decimal(n4);
	
	//converts the binary to decimal if any for checking the pattern
	
	*p7 = *d2 - *d1;
	*p8 = *d3 - *d2;
	*p9 = *d4 - *d3;
	
}




