#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct Node{
	int ID;
	char title[20];
	struct Node *prev;
	struct Node *next;
};
typedef struct Node *node;
node newnode;
node start;
node tmp;
void create_list(int element,char* ti){
	newnode=(node)malloc(sizeof(node));
	newnode->ID=element;
	strcpy(newnode->title,ti);

	if(start==NULL){
		newnode->prev=start;
		newnode->next=start;
		start=newnode;
	}
	else{
		tmp=start;
		while(tmp->next!=start){
			tmp=tmp->next;
		}
		tmp->next=newnode;
		newnode->prev=tmp;
		start->prev=newnode;
		newnode->next=start;
	}
	
}
display(){
	if(start==NULL){
		printf("Empty list\n");
	}
	else{
		tmp=start;
		while(tmp!=NULL){
			printf("%d  \t %s\n",tmp->ID,tmp->title);
			tmp=tmp->next;
		}
	}
}
Delete(int element){
	node hold;
	if(start->ID==element){
		tmp=start;
		start=tmp->next;
		start->prev=NULL;
		free(tmp);
		return;
	}
	hold=start;
	while(hold->next->next!=NULL){
		if(hold->next->ID==element){
			tmp=hold->next;
			hold->next=tmp->next;
			tmp->next->prev=hold;
			free(tmp);
			return;
		}
		
		hold=hold->next;
	}
	if(hold->next->ID==element){
		tmp=hold->next;
		free(tmp);
		hold->next=NULL;
		return ;
	}
}
update(int element,char* ti){
	int k=1;
	if(start==NULL){
		printf("There is no music\n");
	}
	else{
		tmp=start;
		while(tmp!=NULL){
			if(tmp->ID==element)
			  printf("%d \t %s\n",tmp->ID,tmp->title);
			   strcpy(tmp->title,ti);
			   printf("the updated music %d\t %s\n",tmp->ID,tmp->title);
			  k=k+1;
			  tmp=tmp->next;
		}
		if(tmp->ID!=element){
			printf("There is no music with this ID\n");
		}
	}
}

int main(){
	int choice,n,pos,element,i;
	char tit[20];
	while(1){
	
		printf("\n\t\tChoose Your operation you want\n");
	   printf("\t\t----------------------------\n");
	    printf("\t\t----------------------------\n");
		printf("\t\t1,Upload new music\n");
		printf("\t\t2,Delete upload music\n");
		printf("\t\t3,Update exisiting music\n");
		printf("\t\t4,play\n");
		printf("\t\t5,Forward andplay music\n");
		printf("\t\t6,Search\n");
		printf("\t\t7,Display all\n");
		printf("\t\t8,Exit\n");
		scanf("%d",&choice);
		switch(choice){
	case 1:
			printf("\n How many musics you want:\n");
            scanf("%d",&n);
           for(i=0;i<n;i++)
            {
           printf("\nEnter the Id of the music:\n");
           scanf("%d",&element);
           printf("\n Enter the title of the music with Id %d:\t\n",element);
           scanf("%s",&tit);
           create_list(element,tit);
           
           }
           printf("sucessfully added\n the music");
        break;
    case 2:
    	printf("Enter the element fo deletion\n");
   		scanf("%d",&element);
   		Delete(element);
   		break;
   	case 3:
   		printf("Enter the id of the music you want to update\n ");
   		scanf("%d",&element); 
   		printf("Enter the new title you want to update ");
   		scanf("%s",&tit);
   	    update(element,tit);
   	     break;
   	case 4:
   		printf("Enter the name of the music you want to play\n");
   		scanf("%s",&tit);
   		//play(tit);
   		
   	case 5:
   		
   	case 7:
   		display();
   		break;
   	case 8:
   		exit(0);
   		break;
   	default:
   		printf("No more opetions\n");
	}
}
	
}
