#include "Utils.h"


int main(int argc, char *argv[]){


	Book *first = NULL; 
	FILE *books_file,*orders_file,*updated_books_file;
	
	if (argc!= 4){
		printf("Error: invalid number of arguments (%d out of 3)", argc-1);
		exit(1);
	}
	books_file = fopen(argv[1],"r");
	if (books_file==NULL){
		printf("Error: opening %s failed",argv[1]);
		exit(1);
		
	}

	orders_file = fopen(argv[2],"r");
	if (orders_file==NULL){
		printf("Error: opening %s failed",argv[2]);
		exit(1);
		fclose(books_file);
	}
	
	updated_books_file = fopen(argv[3],"w");
	if (updated_books_file==NULL)
	{	
		printf("Error: opening %s failed",argv[3]);
		exit(1);
		fclose(books_file);
		fclose(orders_file);
	}

	initBooksList(&first,books_file);

	readCommands(&first,orders_file);

	storeBooks(&first,updated_books_file);

	
	
	fclose(books_file);
	fclose(orders_file);
	fclose(updated_books_file);

	free_all(&first);

	return 0;
	}