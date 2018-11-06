#include<stdio.h>
#include<stdlib.h>
#include "main.h"


library_s library;
receipt_list_s receipt_list;



int main()
{
int choice,input;
char name[50];

printf("Welcome to XYZ bookstore!\n");
printf("Enter your choice:\n1.Buy books /. /\n2.Exit\n");
scanf("%d",&choice};
switch choice{
	case 1: printf("Enter mode of search:\n1.Book Title\n2.Author\n3.Publisher\n4.Category\n");
			scanf("%d",&input);
			switch input{
				case 1: printf("Enter name of the Book:");
						scanf("%s",name);
						break;
				case 2: printf("Enter name of the Author:");
						scanf("%s",name);
						break;
				case 3: printf("Enter name of the Publisher\n4:");
						scanf("%s",name);
						break;
				case 4: printf("Enter Category of the book:\n1)Chemistry\n2)Math\n3)Physics");
						scanf("%s",name);
						break;
				default : printf("Wrong input!");
			}
			search(name);
			
