#ifndef UTILS_H_  
#define UTILS_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NAME_LENGTH 200
#define MAX_LINE_LENGTH 256
#define COMMAND_LENGTH 46 //MAX_LINE_LENGTH - NAME_LENGTH - " $$$ "*2



//define struct book
typedef struct book {
	char name[NAME_LENGTH];
	int copies;
	struct book *next;
} Book;


//looks for book's place in  a given list(first) and returns pointer to previous book
Book* book_location(Book **first, char * sort_by);

//add new book 
void add_book(Book **first, char * name, int copies, Book *pre_book);

//return a book   
void returnBook(Book **first, char *name, int copies);

//read books file and add books
void initBooksList (Book **first, FILE *file);

//take a book
void borrowBook(Book **first, char *name, int copies);

//get books from file
void readCommands(Book **first, FILE *file);

//put books in a new file 
void storeBooks(Book **first, FILE *file);

//generate a book from parameters
Book* GenerateBook(char name[NAME_LENGTH], int copies);

//splits string to before and after $$$
char* split_str(char str1[NAME_LENGTH],char str2[NAME_LENGTH]);

//free all used location
void free_all(Book **first);

#endif
