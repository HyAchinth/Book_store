#include<stdio.h>
#include<stdlib.h>
#include "main.h"

int main()
{
 	int choice;
	book name[50];
	start:	
	printf("\n1.Add\n2.Exit\n3.view\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			for(int i=0;i<5;i++){
				printf("\n%d:\nEnter the Book name:",(i+1));
				
				scanf("%s",name[i].bname);
				printf("\nEnter isbn:");
				scanf("%d",&(name[i].isbn));
			}
			break;
		case 2:exit(0);
		case 3:
			
			printf("\nBook name:%s\nisbn:%d",name[1].bname,name[1].isbn);
			break;
		default: printf("\nwrong input");
	}
	goto start;		
	return 0;
}
