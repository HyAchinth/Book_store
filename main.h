#define BOOK_MAX 128
#define STR_LENGTH 64
#define STORE_NAME "XYZ Bookstore"
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
	int menu_indices[2][BOOK_MAX],num_books;
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
int save_receipt_list();
void reset_receipt_list();
int save_receipt();
int slices_len();
int slices_insert_end(int);
void slices_remove(int);
void slices_reset();
void slices_search_price(float,float);
int slices_search_name(char);
int add_receipt(char*);
int load_receipt(char*);
int save_receipt_list();
int save_receipt(char*);
int load_receipt_list();
int print_receipt_list();
int print_receipt(int);
