#include "Utils.h"

void free_all(Book **first){
	Book *temp_book,*pre_book=*first;
	while(pre_book!=NULL){
		temp_book=pre_book->next;
		free(pre_book);
		pre_book=temp_book;
	}
}

Book* book_location(Book **first, char * sort_by){
	Book *temp_ptr = *first,*last_ptr = NULL;
	if(temp_ptr == NULL || strcmp(sort_by,temp_ptr->name) ==0)
		return NULL;
	while(temp_ptr != NULL && strcmp(sort_by,temp_ptr->name) >0)
		{
		last_ptr = temp_ptr;
		temp_ptr = temp_ptr->next;
		}
	
		return last_ptr;
	}

Book* GenerateBook(char name[NAME_LENGTH], int copies,Book **first)
{
	Book *temp_book_ptr;
	
	Book temp_book = {"",0,NULL};
	temp_book_ptr = (Book*) malloc(sizeof(Book));        
	if (temp_book_ptr == NULL) {
		printf("error: memory allocation failed!\n");
		free_all(first);
		exit(1);
		}
	*temp_book_ptr = temp_book;


	strcpy(temp_book_ptr->name,name);
	temp_book_ptr->copies = copies;

	return temp_book_ptr;
}

char* split_str(char str1[NAME_LENGTH],char str2[NAME_LENGTH])
	{
	char* seperator_pointer;
	int command_length;
	seperator_pointer = strstr(str1," $$$ ");
	command_length = (int)(seperator_pointer-str1);
	strncpy(str2, str1, command_length);
	str2[command_length] = '\0';
	return seperator_pointer;
	}

void returnBook(Book **first, char *name, int copies)
	{
	Book *temp_book,*pre_book = book_location(first,name);
	if (copies <=0){return;}
	if(*first==NULL)//first book added
		{
		temp_book = GenerateBook(name,copies,first);
		*first = temp_book;
		return;
		}
	if(pre_book==NULL && strcmp(name,(*first)->name) == 0)//the book is the first element
		{
		(*first)->copies += copies;
		return;
		}
	if(pre_book==NULL)//the book is before the first element
		{
		temp_book = GenerateBook(name,copies,first);	
		temp_book->next = (*first);
		*first = temp_book;
		return;
		}
	if(pre_book->next == NULL && strcmp(name,pre_book->name) == 0)//last element, and same book
		{
		pre_book->copies += copies;
		return;
		}
	if(pre_book != NULL && strcmp(name,pre_book->name) == 0)//some element, and same book
		{
		pre_book->copies += copies;
		return;
		}
	if(pre_book != NULL && pre_book->next != NULL)//some element, and same book
		{
			if (strcmp(name,pre_book->next->name) == 0)
				{pre_book->next->copies += copies;
				return;}
		}
		temp_book = GenerateBook(name,copies,first);
		temp_book->next = pre_book->next;
		pre_book->next = temp_book;
	}

void initBooksList (Book **first, FILE *file){
	char str[MAX_LINE_LENGTH];
	char book_name[NAME_LENGTH];
	int copies, name_length;
	char* seperator_pointer;
	Book *pre_book;
	

	while(fgets(str,MAX_LINE_LENGTH,file) != NULL){
		
		seperator_pointer = strstr(str," $$$ ");
		name_length = (int)(seperator_pointer-str);
		strncpy(book_name,str,name_length);
		book_name[name_length] = '\0';

		sscanf(seperator_pointer+5,"%d",&copies);


		returnBook(first, book_name, copies);
		
	}
	
	return;
}

void borrowBook(Book **first, char *name, int copies){
	Book *temp_book, *pre_book = book_location(first,name);
	if (copies<=0){return;}
	if(*first == NULL)
		return;
	if(pre_book==NULL && strcmp(name,(*first)->name) == 0){//the book is the first element
		if((*first)->copies > copies) //its the first element, and borrowing is smaller
		(*first)->copies -= copies; else{ 
		temp_book = (*first)->next;//its the first element, but borrowing is bigger so first should be replaced
		free(*first);
		*first = temp_book;
		}}
	else if(pre_book->next != NULL && strcmp(name,pre_book->next->name) == 0) //found the next book, check on it
	{	
		if(pre_book->next->copies > copies)
			pre_book->next->copies -= copies;
		else
		{	
			temp_book = pre_book->next;
			pre_book->next = pre_book->next->next;
			free(temp_book);
			temp_book = NULL;
		}
	}
	else if(pre_book != NULL && strcmp(name,pre_book->name) == 0) //last element
	{
		if(pre_book->copies > copies)
			pre_book->copies -= copies;
		else
		{

		free(pre_book);
		pre_book = NULL;
		}
	}
	}

void readCommands(Book **first, FILE *file){
	char single_line[MAX_LINE_LENGTH],single_command[COMMAND_LENGTH],single_name[NAME_LENGTH],*seperator_pointer, *name_start_pointer;
	int copies, command_length, name_length;
	while(fgets(single_line,MAX_LINE_LENGTH,file) != NULL){
		if(!strcmp(single_line,"Initialize\n")||!strcmp(single_line,"Finalize\n")){continue;}
		seperator_pointer = split_str(single_line,single_command);
		name_start_pointer = seperator_pointer+5;
		seperator_pointer = split_str(name_start_pointer,single_name);
		sscanf(seperator_pointer+5,"%d",&copies);

		if(single_command[0] == 'B')
			borrowBook(first, single_name, copies);
		if(single_command[0] == 'R')
			returnBook(first, single_name, copies);
	}}

void storeBooks(Book **first, FILE *file){
	Book *indicator, *temp_indicator;
	indicator = *first;
	while (indicator!=NULL){
		fprintf(file, "%s $$$ %d\n", indicator->name, indicator->copies);
		temp_indicator = indicator->next;
		indicator = temp_indicator;
		}
	}
