#include <stdlib.h>
#include <stdio.h>
#include "string.h"

	
	typedef struct node { 

	char lessons[20];
	int size;
	struct node *next;

	}NODE;

	typedef struct list {
		NODE *head;
		NODE *tail;
	}LIST;
	
	LIST A[4]; 


	void request();
	void cancel();
	void output();
	void searchSize();
    int duplicate();	
	void delete_all();

int main() {
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
				delete_all();				
				return 1;
	
		   default : printf( "Bad option\n" ); break;
		}
	}
}

//takes input for name, group size
void  request(){
		
		int i;
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





		if(groupsize<3 && groupsize>0 ){
			i=0;
		}
		else if(groupsize<5){
			i=1;
		}
		else if(groupsize<7){
			i=2;
		}
		else if(groupsize>6){
			i=3;
		}
		else{
			printf("invalid groupsize");
		}
	
		NODE * current = (NODE*)malloc(sizeof(NODE)); // allocate memory for node 
		current->size=groupsize;
		strcpy(current->lessons,name);
		current->next=NULL;
	
		if(A[i].head==NULL){
			A[i].head=current;
			A[i].tail=A[i].head;
		}
		else{
		A[i].tail->next=current;
		A[i].tail=current;
		}

		return;

}




//checks for repeat names
int duplicate(char a[20]){

	for(int i=0;i<4;i++){	
		NODE *temp;
		temp=A[i].head;
		while(temp!=NULL){
			if (strcmp(temp->lessons,a)==0){
				return 1;
			}
			temp = temp->next;
		}
	}
		return 0;
		
}

	   




//cancels a chunk of lessons associated with the name entered

void cancel(){
	
	
		int groupsize;
		int count;
		
		printf ( "enter the number of available surfboards \n");  
		scanf("%d", &groupsize);
	
		int counter = groupsize;
		
		if(groupsize<3 && groupsize>0 ){
			count=0;
		}
		else if(groupsize<5){
			count=1;
		}
		else if(groupsize<7){
			count=2;
		}
		else if(groupsize>6){
			count=3;
		}
		else{
			printf("invalid groupsize");
		}
		for( int i = 0; i < count+1; i++){
	
			NODE *temp;
			NODE *temp1;
			temp =A[i].head;
			temp1 =A[i].head;




			//this for loop cycles through the list and if the size is smaller than the number of remaining surfboards, the lesson gets removed
 		
			while(temp1 !=NULL){
				if (counter >= A[i].head->size){
			    	counter -=temp->size;
					printf("%s's  class was removed and the group size is %d \n",temp->lessons,temp->size);
					temp1 = temp1->next;
					free(temp);	
			    	temp = temp1;
					A[i].head = temp;
				}	
				else if(temp1== A[i].tail && counter >= A[i].tail->size){
	 				printf("%s's  class was removed and the group size is %d \n",temp1->lessons,temp1->size);
					free(temp1);
					temp->next=NULL;
					A[i].tail = temp;
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
		}
		return;

}








//lists out all of the classes scheduled
void output(){
	for(int i=0; i<4;i++){
		NODE *p;
		p = A[i].head;


//this for loop cycles through the list and prints out everyone names

     while(p != NULL){
	 	
	 	printf("%s has a group of %d people\n", p->lessons,p->size);
	
	 	p=p->next;
	 }
	}
		return;
}




void searchSize(){
	int count;
	printf ( "enter the maximum group size that you want to see \n");  
	int groupsize=0;
	scanf("%d", &groupsize);
	
		if(groupsize<3 && groupsize>0 ){
			count=0;
		}
		else if(groupsize<5){
			count=1;
		}
		else if(groupsize<7){
			count=2;
		}
		else if(groupsize>6){
			count=3;
		}
		else{
			printf("invalid groupsize");
		}
	for( int i = 0; i <= count; i++){
	
		NODE *p;
		p = A[i].head;


//this for loop cycles through the list and prints out everyone names

     while(p != NULL){
	 	
		if(p->size<=groupsize) {
        	  printf("%s has a lesson\n",p->lessons );
			  
       		  printf("the groupsize is %d\n",p->size);
		 }
	
	 	p=p->next;
	 }
	}
		return;
}


		

void delete_all(){
	for(int i=0; i<4;i++)
	{
	NODE *p=A[i].head;
	NODE *q=A[i].head;
	q=q->next;
		while(p!=NULL){
			free(p);
			p = q;
		
			if(q!=NULL){
				q = q->next;
			}
		}
	}
return;
}















