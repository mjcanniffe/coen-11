#include <stdlib.h>
#include <stdio.h>
#include "string.h"

	
	typedef struct node { 

	char lessons[20];
	int size;
	struct node *next;
	
	}NODE;

	

	
	
	NODE *head;
	NODE *tail;



	void request();
	void cancel();
	void output();
	void searchSize();
    int duplicate();	
	
int main() {
    head = NULL;
	tail = NULL;
		while(1){
				printf("\ntype 1 to request a class, type 2 to cancel a class, type 3 to see the available schedule, type 4 to see classes smaller than a certain size,  type 0 to quit \n  ");
  
		int userInput;
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
		
		printf("how many in your group\n");	
		scanf("%d",&groupsize);	

		NODE *temp1;                         // create a temporary node
 		temp1 = (NODE*)malloc(sizeof(NODE));
		
		temp1->size=groupsize;
		strcpy(temp1->lessons,name);
		temp1->next = NULL;
		
		if(head==NULL){
			head=temp1;
			tail = head;	
		}
		else{
			tail->next=temp1;
			tail = temp1;
		}
		
	
		return;
}



//checks for repeat names
int duplicate(char a[20]){

		NODE *temp;
		temp=head;
		while(temp!=NULL){
			if (strcmp(temp->lessons,a)==0){
				return 1;
			}
			temp = temp->next;
		}
		return 0;
		
}

	   




//cancels a chunk of lessons associated with the name entered

void cancel(){
	
	
	int groupsize;
	NODE *temp = NULL;
	NODE *temp1 = NULL;
	temp = head;
	temp1 = temp->next;




   if(head== NULL){
       printf("%s","No one has scheduled a lesson yet \n");
   	return;
   }

	printf ( "enter the number of available surfboards \n");  
	scanf("%d", &groupsize);
	int counter = groupsize;


//this for loop cycles through the list and if the size is smaller than the number of remaining surfboards, the lesson gets removed
 if(temp1 == NULL){
 	free(temp);
	head = NULL;
	tail = NULL;
 }
	while(temp1 !=NULL){

		if (counter >= head->size){
			head=temp1;
		    counter -=temp->size;
			printf("%s's  class was removed and the group size is %d \n",temp->lessons,temp->size);
			free(temp);
		    	
		    temp = temp1;
			temp1 = temp1->next;
		}	
		else if(temp1== tail && counter >= tail->size){
			tail = temp;
	 		printf("%s's  class was removed and the group size is %d \n",temp1->lessons,temp1->size);
			free(temp1);
			temp->next=NULL;
			return;
		}
		else if(counter>=temp1->size){
		   
		    counter -=temp1->size;
	 		printf("%s's  class was removed and the group size is %d \n",temp1->lessons,temp1->size);
		
	   		temp->next = temp1->next;
			free(temp1);
			temp1 = temp->next;
		}
		else{ 
		    temp = temp1;
			temp1 = temp1->next;
		}
	   
	   
	}   
	return;
}









//lists out all of the classes scheduled
void output(){

		NODE *p;
		p = head;


//this for loop cycles through the list and prints out everyone names

     while(p != NULL){
	 	
	 	printf("%s has a group of %d people\n", p->lessons,p->size);
	
	 	p=p->next;
	 }
		return;
}




void searchSize(){
	
		NODE *p;
		p = head;


	printf ( "enter the maximum group size that you want to see \n");  
	int groupsize=0;
	scanf("%d", &groupsize);
//this for loop cycles through the list and prints out everyone names

     while(p != NULL){
	 	
		if(p->size<=groupsize) {
        	  printf("%s has a lesson\n",p->lessons );
       		  printf("the groupsize is %d\n",p->size);
		 }
	
	 	p=p->next;
	 }
		return;
}


		

















