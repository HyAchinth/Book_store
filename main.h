#define BOOK_MAX 128
#define STR_LENGTH 64
typedef struct{
	int isbn,status;
	char bname[STR_LENGTH],aname[STR_LENGTH],pname[STR_LENGTH],category[STR_LENGTH];
	float cost;
}book_s;

typedef struct{
	book_s books[BOOK_MAX];
	int quanitity[BOOK_MAX];
	int number_of_books;
}library_s;

typedef struct{
	char cname[STR_LENGTH];
	int menu_indices[BOOK_MAX][2];
}receipt_s;


typedef struct{
	char bill_names[STR_LENGTH][STR_LENGTH];

}receipt_list_s;



