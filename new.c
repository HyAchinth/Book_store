
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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
	int n,b,i=1;
	while(1){
		printf("Book %d\n",i);
		fflush(stdin);
		printf("Enter book name\n:");
		gets(library.books[i-1].bname);
		printf("Enter author name\n:");
		gets(library.books[i-1].aname);
		printf("Enter publisher name\n:");
		gets(library.books[i-1].pname);
		printf("Enter the category\n:");
		gets(library.books[i-1].category);
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
	if(if_exists("receipt_list.dat")){
		FILE *fp = fopen("receipt_list.dat","rb");
		fread(&receipt_list,sizeof(receipt_list_s),1,fp);
		fclose(fp);
		return 1;
	}
	else{
		receipt_list.number_of_receipts = 0;
		return 0;
	}
}

int save_receipt_list(){
	FILE *fp = fopen("receipt_list.dat","wb+");
	if(fwrite(&receipt_list,sizeof(receipt_list_s),1,fp)) printf("Reciept  Created.\n");
	fclose(fp);
	return 1;
}

void reset_receipt_list(){
	receipt_list.number_of_receipts = 0;
}

int add_receipt(char * fn){
	for(int i=0;i<strlen(fn);i++) receipt_list.bill_names[ receipt_list.number_of_receipts ] [i] = fn[i];
	receipt_list.number_of_receipts+=1;
	return 1;
}

int load_receipt(char *name){
	if(if_exists(name)){
		FILE *fp = fopen(name,"rb");
		fread(&receipt_temp,sizeof(receipt_s),1,fp);
		fclose(fp);
		return 1;
	}else{
		return 0;
	}
}


int save_receipt(char *name){
	FILE *fp = fopen(name,"wb+");
	fwrite(&receipt_temp,sizeof(receipt_s),1,fp);
	fclose(fp);
	load_receipt_list();
	add_receipt(name);
	save_receipt_list();
	return 1;
}


int print_receipt_list(){
	load_receipt_list();		// Use functions as required
	for(int i=0; i< receipt_list.number_of_receipts; i++){
	printf("%d	",i+1);
	printf("%s\n",receipt_list.bill_names[i]);
	}
	return 1;
}

int print_receipt(int pos){

	if(load_receipt(receipt_list.bill_names[pos]))
		printf("Recipient: %s", receipt_temp.cname);
	else
		printf("Bill does not exist");
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

void slices_remove(int pos){
	if(slices_len()>0){
		for(int i=pos+1;i<=slices_len();i++)
			library_slice[i-1] = library_slice[i];
	}
}


void slices_reset(){
	int i;
	for(i=0;i<library.number_of_books;i++)
		library_slice[i] = i;
	library_slice[i] = -1;
}


void slices_search_price(float lb,float ub){
	float buffer;
	int i=0;
	while(library_slice[i]!=-1){
		buffer = library.books[ library_slice[i] ].cost;
		if(buffer>ub || buffer<lb)
			slices_remove(i);
		else
		i++;
	}
}


int sort(){
	int temp,buf;
	float cost;int x;
	char name[STR_LENGTH];
	printf("Sort by? \n(1) Book name\n(2) Price\n");
	scanf("%d",&x);
	for(int i=0; i<slices_len()-1 ; i++)
	{
		for(int j=0 ; j<slices_len()-i-1; j++)
		{
			if(x==1) buf = strcmp(library.books[ library_slice[j] ].bname , library.books[ library_slice[j + 1] ].bname) > 0;
			else buf = library.books[ library_slice[j] ].cost > library.books[ library_slice[j+1] ].cost;
			if( buf )
			{
				temp = library_slice[j+1];
				library_slice[j + 1] = library_slice[j];
				library_slice[j] = temp;
			}
		}
	}
	return 0;
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
 		else
		i++;
		printf("%d",i);
	}
	return 1;
}


int order(){
	int x=1,in,no,i=0;
	char fn[STR_LENGTH];
	time_t t = time(NULL);
	sprintf(fn,"%d.bill",t);
	while(x == 1)
	{
		printf("Enter the book you want to order(index):\n");
		scanf("%d",&in);
		printf("Enter the quantity:\n");
		scanf("%d", &no);
		receipt_temp.menu_indices[0][i] = library_slice[in - 1];
		receipt_temp.menu_indices[1][i] = no;
		printf("Continue to order?[Y=1]");
		scanf("%d", &x);
		i++;
	}
	printf("Enter the name of the user:\n");
	scanf("%s",receipt_temp.cname);
	save_receipt(fn);
	return 1;

}


int main(){
	load_receipt_list();int choice;
	char name[STR_LENGTH]; int input;
	int low,up,x;

	while(1){
		printf("1. Save\n2. Load\n3. Make\n4. Print Selection\n5. Search\n6. Reset\n7. Sort\n8. Order\n9. Search\n10. Load Reciept List\n11. View receipt list\n12. View Reciept\n13. Reset Receipt list\n0. Exit\n:");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				exit(0);
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
				printf("Enter the lower and upper price limit:\n");
				scanf("%d %d", &low,&up);
				slices_search_price(low,up);
				break;
			case 6:
				slices_reset();
				break;
			case 7:
				sort();
				break;
			case 8:
				order();
				break;
			case 9:
                fflush(stdin);
				printf("Enter search method:\n1. Book name\n2. Author name\n3. Publisher\n4. Category\n");
				scanf("%d",&input);
				fflush(stdin);
				printf("\nEnter the search term:\n");
				gets(name);
				slices_search_string(name,input);
				break;
			case 10:
				load_receipt_list();
				break;
			case 11:
				print_receipt_list();
				break;
			case 12:
				printf("Enter the index of the bill you want to access:\n");
				scanf("%d",x);
				print_receipt(x-1);
				break;
			case 13:
				reset_receipt_list();
				printf("Reset\n");
				break;
			default:
				printf("How did you get here");
		}
	}
return 0;
}
