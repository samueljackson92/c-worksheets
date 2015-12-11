#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "main.h"

int main(int argc, char** argv) {
    BookNode** catalogue = create_catalogue();
    BookNode* book1 = create_book_node("For Whom a Bell Tolls", "Hemmingway", 1234567);
    BookNode* book2 = create_book_node("100 Years of Solitude", "Garcia Marquez", 7654321);
    BookNode* book3 = create_book_node("Ulysses", "Joyce", 1234321);
    BookNode* book4 = create_book_node("The Iliad", "Homer", 1234321);
    BookNode* book5 = create_book_node("The Odyssey", "Homer", 1234321);

    add_book(catalogue, book1);
    add_book(catalogue, book2);
    add_book(catalogue, book3);
    add_book(catalogue, book4);
    add_book(catalogue, book5);

    print_catalogue(catalogue);
    free_catalogue(catalogue);
    return 0;
}

BookNode* create_book_node(char* title, char* author, long isbn) {
    BookNode* node = malloc (sizeof(BookNode));
    node->title = title;
    node->author = author;
    node->isbn = isbn;
    node->next = NULL;
}

BookNode** create_catalogue() {
    BookNode** catalogue = malloc(sizeof(BookNode*));
    *catalogue = NULL;
    return catalogue;
}

void add_book(BookNode** catalogue, BookNode* new_node) {
    // first check the head to see if we have an empty list
    if (*catalogue == NULL) {
        *catalogue = new_node;
    } else if (compare_authors(*catalogue, new_node) > 0) {
        BookNode* current = *catalogue;
        new_node->next = current;
        *catalogue = new_node;
    } else {
        BookNode* current = find_insertion_position(*catalogue, new_node);
        insert_node(current, new_node);
    }
}

int compare_titles(BookNode* a, BookNode* b) {
    return strcmp(a->title, b->title);
}

int compare_authors(BookNode* a, BookNode* b) {
    return strcmp(a->author, b->author);
}

BookNode* find_insertion_position(BookNode* current, BookNode* new_node) {
    //cycle through nodes until the we reach the end of the list
    while (current->next != NULL && compare_authors(current->next, new_node) < 0) {
        current = current->next;
    }
    return current;
}

void insert_node(BookNode* current, BookNode* new_node) {
    if(current->next == NULL) {
        current->next = new_node;
    } else {
        BookNode* tmp = current->next;
        current->next = new_node;
        new_node->next = tmp;
    }
}

void swap_nodes(BookNode* current, BookNode* new_node) {
    BookNode* tmp = current->next;
    current->next = new_node;
    new_node->next = tmp;
}

void print_catalogue(BookNode** catalogue) {
    // first check the head to see if we have an empty list
    if(catalogue == NULL) {
        printf("Catalogue is empty!\n");
    } else {
        BookNode* current = *catalogue;
        printf("%-30s %-30s %-30s \n", "Title", "Author", "ISBN");
        //cycle through nodes until the we reach the end of the list
        do {
            //print book then move to next node
            print_book(current);
            current = current->next;
        } while (current != NULL);

    }
}

void print_book(BookNode* book) {
    printf("%-30s ", book->title);
    printf("%-30s ", book->author);
    printf("%-30lu ", book->isbn);
    printf("\n");
}

void free_catalogue(BookNode** catalogue) {
    if (catalogue != NULL) {
        BookNode* first = *catalogue;
        free_books(first);
    }
}

void free_books(BookNode* book) {
    // recursively free a chain of books
    if(book->next != NULL) {
        free_books(book->next);
    }
    free(book);
}
