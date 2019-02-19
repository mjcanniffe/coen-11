
#include <stdio.h>
#include "string.h"

	
	 
	char lessons[10][20];
	int size[20];
	
	int total = 0; 	
	int userInput;
	void request();
	void cancel();
	void list();
	
	
	
int main() {
    
		while(1){
				printf("%s","type 1 to request a class, type 2 to cancel a class, type 3 to see the available schedule, type 0 to quit \n  ");
  
       scanf("%d",&userInput);
       switch (userInput){
      
		   case 1 :
			request();   
			break;
		   
		   case 2 :         
			 cancel();				
	         break;
		   
		   case 3 :
    		 list();
			 break; 
		   
			case  0 : 
				return 1;
				break;
	
		   default : printf( "Bad option\n" ); break;
		}
	}
}

//takes input for name, group size
void  request(){
		int groupsize;
		char name[20];

    	 printf("whats your name\n");
		
		  scanf("%s", name);
//checks for repeats in names
	   for(int i=0; i<total; i++){
			
		   if(strcmp(lessons[i],name)==0 ){
					printf("name is already taken\n ");
		   			return;
			}
	   }
//copies the inputs into the arrays
				strcpy(lessons[total],name);
				printf("how many in your group\n");	
				scanf("%d",&groupsize);	
				size[total]=groupsize;
				total++;	
		


	
		return;
}
		
//cancels a chunk of lessons associated with the name entered

void cancel(){
	int groupsize;
	printf ( "enter the number of available surfboards \n");  

   if(total== 0){
       printf("%s","No one has scheduled a lesson yet \n");
   }

	scanf("%d", &groupsize);
	int counter = groupsize;


//this for loop cycles through the list and if the size is smaller than the number of remaining surfboards, the lesson gets removed
   for (int i = 0; i < total; i++){
    
	   if (counter>=size[i]){
		   counter -=size[i];

	   	  
	 	printf("%s's  class was removed and the group size is %d \n",lessons[i],size[i]);
		
//this for loop goes through the 2D array and shifts everything up one place		
			  
		for(int j=i; j<total-1 ; j++){
	
			   strcpy(lessons[j],lessons[j+1]);
		   	   size[j]=size[j+1];	
			   printf("%s was moved up\n ", lessons[j+1] ) ;
		 	  
		 }	
//after it has been shifted up we need to decrement total and i to account for the element that was just lost
			lessons[total-1][0]='\0';
			total--;			
     		i--;
	   }
   }
	return;
}

//lists out all of the classes scheduled
void list(){
	

//this for loop cycles through the list and prints out everyone names
	for (int i = 0; i < total; i++){
	    if (total==0){
	        printf("No lessons have been requested yet\n");
          	break;
        }			 
        else {
        	  printf("%s has a lesson\n",lessons[i] );
       		  printf("the groupsize is %d\n",size[i]);
		 }
     }
		return;
}

















