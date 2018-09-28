#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int isbn,status;
	char bname[30],aname[30];
}book;

int main()
{
 	int choice;
start:	printf("\n1.Add\n2.Exit\n3.view\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("\nEnter the Book name:");
			book name;
			scanf("%s",name.bname);
			printf("\nEnter isbn:");
			scanf("%d",&(name.isbn));			
			break;
		case 2:exit(0);
		case 3:printf("\nBook name:%s\nisbn:%d",name.bname,name.isbn);
			break;
		default: printf("\nwrong input");
	}
	goto start;		
	return 0;
}
