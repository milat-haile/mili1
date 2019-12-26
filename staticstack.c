#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 int Top=94;
# define size 100
int PushBook(int id);
void PopBook();
void display();
int main(){
	int choice,num,n;
	char tb[30];
	int arr[size];
	while(1){
		printf("\n\n\t\t Main Menu");
		printf("\n\t\t***************");
		printf("\n\n\t\t1,Add Book");
		printf("\n\n\t\t2,Delete Book");
		printf("\n\n\t\t3,Display total book and detail of the books");
	    printf("\n\n\t\t4,Exit");
		printf("\n\n\t\tEnter your choice:\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\n\n\tEnter Id of the book:\t");
				scanf("%d",&num);
				printf("\n\n\tEnter the title of the book:\t");
				scanf("%s",&tb);
				PushBook(num);
				printf("\n\n\twould you want to add another book ? press 1 to add or 0 to quit:\t");
		    	while(scanf("%d",&n)==1&& n==1){
		    	printf("\n\n\tEnter Id of the book:\t");
				scanf("%d",&num);
				printf("\n\n\t Enter the title of the book:\t");
				scanf("%s",&tb);
				PushBook(num);
				printf("\n\n\twould you want to add another book ? press 1 to add or 0 to quit:\t");
			}
				break;
		case 2:
			PopBook();
			break;
		case 3:
			Display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("No more option\n");
		}
	
			}
}
int PushBook(int id){
	int Id[size];
	//char title[size][30];
	if(Top==size-1){
		printf("\t\tStack overflow\n");
	}
   else{
		Id[++Top]=id;
	//strcpy(title[++Top],tit);
		 printf("\n\n\t\t book is added sucessfully");
		 return Id[++Top];
	}
}
void PopBook(){
	int id;
	char tit[30];
	if(Top<0){
		printf("Stack underflow");
		
	}
	else{
	//	id=Id[Top--];
		//strcpy(tit,title[--Top]);
		printf("\t\tbook deleted sucessfully\n");
	}
}
void Display(){
	int i;
	if(Top<0){
		printf("\nthere is no book");
	}
	else{
		printf("\n\n\t\tBook Id      \t BooK Name");
		for(i=Top;i>=0;i--){
		
	//s	printf("\n\n\t\t"Id[i]" \t ");
		}
	}
}
