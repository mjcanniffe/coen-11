#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CONSTANT constant_value

int division(int num1, int num2, int num3);
int  main(){
	int count = 0;
	srand ((int) time (NULL));

	for (int i = 0; i < 10; i++){

		int number1 = rand()%12 + 1;
		int number2 = rand()%13;	
		int number3 = (number1 * number2);
		if(division(number1, number2, number3 )){
			count ++;
		}
		
	}

	printf("you got %d correct\n",count );

}

int division(int num1, int num2, int num3 ){

	int number3 = 0;

	printf("Solve for X \n");
	
	


	printf("%d", num3);
	printf("/" );
	printf("%d",  num1 );
	printf("=" );
	printf("X\n");

	scanf("%d", &number3);

	if (number3 == (num3/num1) ){
		printf("correct \n");
		return 1;
	}

	else{
		printf("incorrect \n" );
		return 0;
	}
	
}






