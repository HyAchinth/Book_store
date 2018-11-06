#include<stdio.h>
#include<stdlib.h>
#include "main.h"


library_s library;
receipt_list_s receipt_list;
receipt_s receipt_temp;


int if_exists(const char *fname){
	FILE *file;
	if ((file = fopen(fname, "r")))
	{
		fclose(file);
		return 1;
    }
    return 0;
}




int load_library(){
	if(exists("library.dat")){
		FILE *fp = fopen("library.dat","rb");
		fread(&library,sizeof(library_s),1,fp);
		fclose(fp);
		return 1;
	}
	else return 0;
}


int save_library(){
	FILE *fp = fopen("company.details","wb+");
	fwrite(&library,sizeof(library_s),1,fp);
	fclose(fp);
	return 1;
}


int load_receipt_list(){
	if(exists("receipt.list.dat")){
		FILE *fp = fopen("receipt.list.dat","rb");
		fread(&receipt_list,sizeof(receipt_list_s),1,fp);
		fclose(fp);
		return 1;
	}
	else{
		receipt_list.number_of_receipts = 0;
		return 0;
	}
}

int save_receipt(char *name){
	FILE *fp = fopen(name,"wb+");
	fwrite(&receipt_temp,sizeof(receipt_s),1,fp);
	fclose(fp);
	return 1;
}




int main()
{
int choice,input;
char name[50];
load_receipt_list();
printf("Welcome to XYZ bookstore!\n");
printf("Enter your choice:\n1.Buy books /. /\n2.Exit\n");
scanf("%d",&choice};
switch(choice){
	case 1: printf("Enter mode of search:\n1.Book Title\n2.Author\n3.Publisher\n4.Category\n");
			scanf("%d",&input);
			switch(input){
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
			
