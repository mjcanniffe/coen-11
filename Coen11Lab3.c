
#include <stdio.h>
#include "string.h"

	
	typedef struct entry { 

	char lessons[20];
	int size;
	
	}ENTRY;

	

	ENTRY list[10];

	int total = 0; 	
	int counter;
	int userInput;
	void request();
	void cancel();
	void output();
	void searchSize();
    int duplicate();	
	
int main() {
    
		while(1){
				printf("%s","type 1 to request a class, type 2 to cancel a class, type 3 to see the available schedule, type 4 to see classes smaller than a certain size,  type 0 to quit \n  ");
  
       scanf("%d",&userInput);
       switch (userInput){
      
		   case 1 :
			request();   
			break;
		   
		   case 2 :         
			 cancel();				
	         break;
		   
		   case 3 :
    		 output();
			 break;

		   case 4 :
			 searchSize();
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

		if(duplicate(name)==1){
			
					printf("name is already taken\n ");
		return;	
		}
			;
//copies the inputs into the arrays
				strcpy(list[total].lessons,name);
				printf("how many in your group\n");	
				scanf("%d",&groupsize);	
				list[total].size=groupsize;
				total++;	
		


	
		return;
}


int duplicate(char a[20]){


		//checks for repeats in names
	    for(int i=0; i<total; i++){
			
		   if(strcmp(list[i].lessons,a)==0 ){
		   			return 1;
			}
		}
			   return 0;
		   
	   
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
    
	   if (counter>=list[i].size){
		   counter -=list[i].size;

	   	  
	 	printf("%s's  class was removed and the group size is %d \n",list[i].lessons,list[i].size);
		
//this for loop goes through the 2D array and shifts everything up one place		
			  
		for(int j=i; j<total-1 ; j++){
	
		
			list[j]=list[j+1];
			   printf("%s was moved up\n ", list[j+1].lessons ) ;
		 	  
		 }	
//after it has been shifted up we need to decrement total and i to account for the element that was just lost
			total--;			
     		i--;
	   }
   }
	return;
}

//lists out all of the classes scheduled
void output(){

		ENTRY *p;
		p = list;

	    if (total==0){
	        printf("No lessons have been requested yet\n");
          	return;
        }

//this for loop cycles through the list and prints out everyone names

		for (int i = 0; i < total; i++, p++){
        	
        		  printf("%s has a lesson\n",p->lessons);
       		  	printf("the groupsize is %d\n",p->size);
		 	
     	}
		return;
}

void searchSize(){
	
		ENTRY *p;
		p = list;

	printf ( "enter the maximum group size that you want to see \n");  
	int groupsize=0;
	scanf("%d", &groupsize);

	//this for loop cycles through the list and prints out everyone names
	for (int i = 0; i < total; i++,p++){
	    if (total==0){
	        printf("No lessons have been requested yet\n");
          	break;
        }
		else if(p->size<=groupsize) {
        	  printf("%s has a lesson\n",p->lessons );
       		  printf("the groupsize is %d\n",p->size);
		 }
     }
		return;



}














