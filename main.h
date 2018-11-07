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
	int number_of_receipts;
}receipt_list_s;

void search_books();



int load_library();


int save_library();




int if_exists(char*);
int make_library();
int load_ibrary();
int save_library();
void print_slice();
int load_receipt_list();
int save_receipt();
int slices_len();
int slices_insert_end(int);
int slices_remove(int);
void slices_reset();