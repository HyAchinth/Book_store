#include<stdio.h>
#include<stdlib.h>
#include "main.h"


library_s library;
receipt_list_s receipt_list;
receipt_s receipt_temp;
int library_slice[BOOK_MAX];

int if_exists(char *fname){
	FILE *file;
	if ((file = fopen(fname, "r")))
	{
		fclose(file);
		return 1;
    }
    return 0;
}


int make_library(){
	int n;char b;
	int i=1;
	while(1){
		printf("Book %d\n",i);
		printf("Enter book name\n:");
		scanf("%s",library.books[i-1].bname);
		printf("Enter book price\n:");
		scanf("%f",&(library.books[i-1].cost) ); 
		
		
		printf("Continue? (Y/N)");
		fflush(stdin);
		scanf("%c",&b);
		if(b=='N'){
			library.number_of_books = i;
			break;
		}
		i++;
	}
	return 0;
}


int load_library(){
	if(if_exists("library.dat")){
		FILE *fp = fopen("library.dat","rb");
		fread(&library,sizeof(library_s),1,fp);
		fclose(fp);
		
		int i;
		for(i=0;i<library.number_of_books;i++)
			library_slice[i] = i;
		library_slice[i] = -1;
		return 1;
	}
	else return 0;
}


int save_library(){
	FILE *fp = fopen("library.dat","wb+");
	fwrite(&library,sizeof(library_s),1,fp);
	fclose(fp);
	return 1;
}


void print_slice(){
	for(int i=0;i<slices_len();i++){
		printf("%d %s %f \n",i+1,library.books[ library_slice[i] ].bname, library.books[ library_slice[i] ].cost );
	}
}

int load_receipt_list(){
	if(if_exists("receipt.list.dat")){
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



int slices_len(){
	int i;
	for(i=0;i[library_slice]!=-1;i++);
	return i;
}

int slices_insert(int *slice_array, int element){
	if(slices_len(slice_array)==BOOK_MAX-1)
		return 1;
	else{
		slice_array[slices_len(slice_array)+1] = -1;
		slice_array[slices_len(slice_array)] = element;
		
	}
		
}

int slices_remove(int *slice_array){
	if(slices_len(slice_array)>0){
	}
}


/*int main()
{
	int choice,input;
	char name[STR_LENGTH];
	load_receipt_list();
	int library_slice[BOOK_MAX];
	
	
	printf("Welcome to XYZ bookstore!\n");
	printf("Enter your choice:\n1.Buy books /. /\n2.Exit\n");
	scanf("%d",&choice};
	
	
	switch(choice){
		case 1: 
			printf("Enter mode of search:\n1.Book Title\n2.Author\n3.Publisher\n4.Category\n");
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
			

			*/
			
int main(){
	load_receipt_list();int choice;
	
	
	
	
	printf("1. Save 2. Load 3. Make 4. Print");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			save_library();
			break;
		case 2:
			load_library();
			break;
		case 3:
			make_library();
			break;
		case 4:
			print_slice();
			break;
		default:
			printf("How did you get here");
	}
	
	
	
	
	
	
	
	return 0;
}