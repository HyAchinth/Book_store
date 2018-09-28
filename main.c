#include <stdio.h>
/*typedef struct{
	int isbnstatus;
	char bname[30],aname[30];
}book;*/

int main()
{
 	int choice;
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("\ngood");
			break;
		default: printf("\nbad");
	}		
	return 0;
}
