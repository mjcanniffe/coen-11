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


	void request(char *name, int groupsize);
	void cancel();
	void output();
	void searchSize();
    int duplicate();	
	void delete_list();
	void read_all(char *filename);
	void save_all(char *filename);
	void helperfunction(NODE *p, char *q );
	void classes_backwards(NODE *p);
	void name_backwards(char *q);


int main(int argc,char *argv[])
{
	
	if (argc == 1)
	{
			printf("The name of the file is missing!\n");
			return 1;
	}
	
	read_all (argv[1]);

	char name[20];
	int groupsize=0 ;
	
	
	while(1){
			printf("\ntype 1 to request a class, type 2 to cancel a class, type 3 to see the available schedule, type 4 to see classes smaller than a certain size, case 5 to flip the order of the names, case 6 to flip the spelling of the names,  type 0 to quit \n  ");
  
		int userInput;
       scanf("%d",&userInput);
       switch (userInput){
      
		    case 1 :

			printf("print the name\n");
			scanf("%s",name);
			printf("how many in the group?\n");
			scanf("%d",&groupsize);
			request(name, groupsize );   
			
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
		    
			case 5 :
				for(int i = 3; i>=0; i--){
					NODE *p = A[i].head;
					classes_backwards(p);
				}
				break;
			case 6 : 
				for(int i = 0; i<4; i++){
					NODE *p = A[i].head;
					
					while(p!=NULL){
						name_backwards(p->lessons);
						printf("\n");
						p=p->next;
					}
				}

				break;
		    case 0 : 
				save_all(argv[1]);
				for(int i=0; i<4;i++){
					NODE *p=A[i].head;
		   			delete_list(p );
				}
			return 1;
	
		   default : printf( "Bad option\n" ); break;
		}
	}
}






//takes input for name, group size
void  request(char *name, int groupsize){
		
	


		if(duplicate(name)==1){	
			
			printf("name is already taken\n ");
			return;	
		}


		int i;

	
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


		

void delete_list(NODE *p ){
	if(p==NULL){	
		return;
	}
		
		delete_list(p->next );
		free(p);
	
	
}


void read_all(char *filename){
	char name[20];
	int groupsize;

	FILE *fp=fopen(filename, "r");
	if(fp==NULL){
		return;
	}
	
	fseek(fp,50, SEEK_SET);
	
	while(fscanf(fp, "%s \t %d", name,&groupsize)==2){
			request(name,groupsize);
	}
	
	fclose(fp);	
	return;
}





void save_all(char *filename){
		FILE *fp=fopen(filename, "w");
			
		NODE *p;
		
		if(fp==NULL){
			return;
		}
		fprintf(fp,"name \t \t Groupsize \n --------------------------- \n");
	
		for( int i = 0; i < 4; i++){
			p = A[i].head;
			while (p != NULL){
				printf("\n");
				fprintf(fp, "%s \t %d\n ", p->lessons,p->size);
				p=p->next;
			}
		}
		fclose(fp);
		return;
}



void classes_backwards(NODE *p)
{
	if(p==NULL){
		return;
	}
	classes_backwards(p->next);
	printf("%s\n",p->lessons);
	return;
}


void name_backwards(char *q)
{
	if(*q=='\0'){
		return;
	}
	
	name_backwards(q+1);
	printf("%c",*q);
	return;
}

















