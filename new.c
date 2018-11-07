#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	int n;int b;
	int i=1;
	while(1){
		printf("Book %d\n",i);
		printf("Enter book name\n:");
		scanf("%s",library.books[i-1].bname);
		printf("Enter book price\n:");
		scanf("%f",&(library.books[i-1].cost) );


		printf("Continue? (n=1,y=0)");
		fflush(stdin);
		scanf("%d",&b);
		if(b){
			library.number_of_books = i;
			break;
		}
		i++;
	}
	slices_reset();
	return 0;
}


int load_library(){
	if(if_exists("library.dat")){
		FILE *fp = fopen("library.dat","rb");
		fread(&library,sizeof(library_s),1,fp);
		fclose(fp);

		slices_reset();

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

int slices_insert_end(int element){
	if(slices_len()==BOOK_MAX-1)
		return 1;
	else{
		library_slice[slices_len()+1] = -1;
		library_slice[slices_len()] = element;

	}

}

int slices_remove(int pos){
	if(slices_len()>0){
		for(int i=pos+1;i<=slices_len();i++)
			library_slice[i-1] = library_slice[i];
	}
	else
		return 0;
}


void slices_reset(){
	int i;
	for(i=0;i<library.number_of_books;i++)
		library_slice[i] = i;
	library_slice[i] = -1;
}


int slices_search_price(float ub,float lb){
	float buffer;
	int i=0;
	while(library_slice[i]!=-1){
		buffer = library.books[ library_slice[i] ].cost;
		if(buffer>ub || buffer<lb)
			slices_remove(i);
		i++;
	}
	return 1;
}

int slices_search_name(char a[STR_LENGTH]){
	char buffer[STR_LENGTH];
	int i=0;
	while(library_slice[i]!=-1){
		strcpy(buffer,library.books[ library_slice[i] ].bname);
		if(buffer != a)
			slices_remove(i);
		i++;
	}
	return 1;
}


int slices_search_string(char* term,int choice){
	int i=0;
	while(library_slice[i]!=-1){
		int flag=0;
		// Check if it warrants removal, as it is not present
		switch(choice){
			case 1:
				//bname
				flag = strstr(library.books[ library_slice[i] ].bname , term) == NULL;
			break;
			case 2:
				//aname
				flag = strstr(library.books[ library_slice[i] ].aname , term) == NULL;
			break;
			case 3:
				//pname
				flag = strstr(library.books[ library_slice[i] ].pname , term) == NULL;
			break;
			case 4:
				//category
				flag = strstr(library.books[ library_slice[i] ].category , term) == NULL;
			break;
		}
		if(flag)
			slices_remove(i);
		i++;
	}
	return 1;
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
	load_receipt_list();int choice,input;
char name[STR_LENGTH];


	while(1){
		printf("1. Save\n2. Load\n3. Make\n4. Print Selection\n5. Search\n6. Reset\n8. Exit\n9. Search by name\n");
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
			case 5:
				slices_search_price(16,25);
				break;
			case 6:
				slices_reset();
				break;
			case 7:
				//sort();
				break;
			case 8:
				exit(0);
			case 9:
                printf("Enter name,search method:\n1. Book name\n2. Author name\n3. Publisher\n4. Category\n");
				scanf("%s %d",name,input);
				slices_search_string(name,input);
				break;
			default:
				printf("How did you get here");
		}
	}


	return 0;
}
