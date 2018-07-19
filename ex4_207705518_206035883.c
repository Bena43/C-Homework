#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOOK_NUM 50
#define NAME_LENGTH 200
#define AUTHOR_NAME_LENGTH 100
#define PUBLISHER_NAME_LENGTH 50
#define GENRE_LENGTH 50

typedef struct book {
char name[NAME_LENGTH];
char author[AUTHOR_NAME_LENGTH];
char publisher[PUBLISHER_NAME_LENGTH];
char genre[GENRE_LENGTH];
int year;
int num_pages;
int copies;
} Book;

typedef struct library{    //object library contains array of book pointers and how many books are in the array in a given moment
	Book* books_arr[BOOK_NUM];
	int counter;
	}Library;

int exists (Library * lbr, char to_check[]){    //if book exists in lbr return location(i) else -1
	int i=0, end = lbr->counter;
	char *book_ptr, *to_check_ptr=to_check;

	for(i; i<end ; i++){
		book_ptr = lbr -> books_arr[i] -> name;
		if(strcmp(to_check_ptr,book_ptr)==0){
			return i;
			}
		}
	return -1;
}

void book_info(Library * lbr,Book * book_ptr){
	char b_author[AUTHOR_NAME_LENGTH], b_publisher[PUBLISHER_NAME_LENGTH], b_genre[GENRE_LENGTH];
	int b_copies, b_year, b_num_pages;
	printf("Please enter author name: "); 
	scanf("\n%[^\n]s", b_author);
	strcpy(book_ptr->author,b_author);
	
	printf("Please enter publisher name: ");
	scanf("\n%[^\n]s", b_publisher);
	strcpy(book_ptr->publisher,b_publisher);

	printf("Please enter book genre: ");
	scanf("\n%[^\n]s", b_genre);
	strcpy(book_ptr->genre,b_genre);
	
	printf("Please enter the year of publishing: ");
	scanf("%d",&b_year);
	book_ptr->year = b_year;
	
	printf("Please enter the number of pages: ");
	scanf("%d",&b_num_pages);	
	book_ptr->num_pages = b_num_pages;

	printf("Please enter the number of copies: ");
	scanf("%d",&b_copies);
	book_ptr->copies = b_copies;
}


void add_book(Library * lbr){
	char b_name[NAME_LENGTH], b_author[AUTHOR_NAME_LENGTH], b_publisher[PUBLISHER_NAME_LENGTH], b_genre[GENRE_LENGTH];
	int b_copies=0, b_year, b_num_pages, b_exists;
	Book new_book={"","","","",0,0,0}, * book_ptr;

	if(lbr->counter>=BOOK_NUM){
		printf("Can't add more books\n");
		return;
		}
		
	printf("Please enter book name: ");
	scanf("\n%[^\n]s", b_name);
	b_exists = exists(lbr,b_name);
	if(b_exists!=-1){
		printf("The book already exists. Please enter the number of copies to add: ");
		scanf("%d", &b_copies);

		lbr->books_arr[b_exists]->copies+=(b_copies);

		printf("\nAdditional copies (%d) of book %s were successfully added!\n\n",b_copies,b_name);
		return;
	}
	
	book_ptr = (Book *)malloc(sizeof(Book));
	if(book_ptr == NULL){
		printf("error - memory allocation failed!");
		exit(1);
		return;
	}
	strcpy(book_ptr->name,b_name);
	book_info(lbr,book_ptr);
	
	lbr->books_arr[lbr->counter] = book_ptr;
	lbr->counter++;
	printf("The book %s was successfully added!\n\n",b_name);
	return;
}



	
void take_book(Library * lbr){
	char b_name[NAME_LENGTH];
	int b_copies, b_exists;
	
	printf("Please enter book name: ");
	scanf("\n%[^\n]s", b_name);

	b_exists = exists(lbr,b_name);

	if(b_exists==-1){
		printf("book doesnt exists in the library\n");
		return;
		}

	printf("Please enter the desired number of copies: ");
	scanf("%d",&b_copies);

	if(b_copies>lbr->books_arr[b_exists]->copies){
		printf("not enough copies of desired book\n");
		return;
		}

	lbr->books_arr[b_exists]->copies-=b_copies;
	printf("%d copies of %s were successfully taken!\n\n", b_copies, b_name);
	return;
	}

void return_book(Library * lbr){
	char b_name[NAME_LENGTH];
	int b_copies, b_exists;
	
	printf("Please enter book name: ");
	scanf("\n%[^\n]s", b_name);

	b_exists = exists(lbr,b_name);

	if(b_exists==-1){
		printf("book doesnt exists in the library\n");
		return;
		}

	printf("Please enter the number of copies to return: ");
	scanf("%d",&b_copies);

	lbr->books_arr[b_exists]->copies+=b_copies;
	printf("%d copies of %s successfully returned!\n\n", b_copies, b_name);
	return;
	}

void printall_books(Library * lbr){
	int i=0;
	
	printf("Books available\n---------------\n");
	for(i; i<lbr->counter; i++){
		if(lbr->books_arr[i]->copies!=0){
			printf("Name: %s\nAuthor: %s\nPublisher: %s\nGenre: %s\nYear: %d\nNumber of pages: %d\nNumber of copies: %d\n---------------\n",lbr->books_arr[i]->name,lbr->books_arr[i]->author,lbr->books_arr[i]->publisher,lbr->books_arr[i]->genre,lbr->books_arr[i]->year,lbr->books_arr[i]->num_pages,lbr->books_arr[i]->copies);
			}
		}
	return;
	}

void quit (Library *lbr){
	int i=0;
	
	printall_books(lbr);   // print all books in library
	for(i; i<lbr->counter; i++){   //free
		free(lbr->books_arr[i]);
		}
	printf("\nThank you for using our library's user friendly interface!\nSee you next time!\n");
	return;
	}



int main(){
	int check = 1, option;  //check - for running the while(default 1,exit 0) , option = input by user to activae wanted option(1-5)
	Library lbr,*lbr_ptr=&lbr;

	lbr_ptr->counter=0; //set number of book in library to 0

	while(check){
		printf("*********************************************\n");
		printf("Welcome to BURLAND national library!\n");
		printf("*********************************************\n");
		printf("Library menu:\n");
		printf("1. Add a book\n");
		printf("2. Take a book\n");
		printf("3. Return a book\n");
		printf("4. Print all library books\n");
		printf("5. Quit\n");
		printf("Please choose the desired option [1-5]: ");

		scanf("%d",&option);

		switch(option){
		case 1:
			add_book(lbr_ptr);
			break;
		case 2:
			take_book(lbr_ptr);
			break;
		case 3:
			return_book(lbr_ptr);
			break;
		case 4:
			printall_books(lbr_ptr);
			break;
		case 5:
			quit(lbr_ptr);
			check = 0;
			break;
			}
		}
	return 0;
	}