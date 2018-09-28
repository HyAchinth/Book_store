#include <stdio.h>
int main()
{
 	int choice;
	typedef struct{
			int isbnstatus;
			char bname[30],aname[30];
	}book;
	
	printf("Enter your choice:");
	scanf("%d",choice);
	switch choice
	{
		case 1:printf("\ngood");
	}		
	return 0;
}