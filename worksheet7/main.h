
/* Book structure definition */
typedef struct booknode_t {
    char* title;
    char* author;
    long isbn;
    struct booknode_t* next;
} BookNode;

const int BUFFER_SIZE = 100;

/* Create an empty catalogue */
BookNode** create_catalogue();

/* Create a new book node */
BookNode* create_book_node(char* title, char* author, long isbn);

/* Add a new book to the catalogue */
void add_book(BookNode** catalogue, BookNode* new_node) ;

/* Compre the titles of two books */
int compare_titles(BookNode* a, BookNode* b);

/* Compre the authors of two books */
int compare_authors(BookNode* a, BookNode* b);

/* Find the correct place to insert a new book */
BookNode* find_insertion_position(BookNode* current, BookNode* new_node);

/* Insert the new node into the correct position */
void insert_node(BookNode* current, BookNode* new_node);

/* Swap two nodes so that new_node->next points to current */
void swap_nodes(BookNode* current, BookNode* new_node);

/* Print an entire catalogue */
void print_catalogue(BookNode** catalogue);

/* Print a single book */
void print_book(BookNode* book);

/* Free a catalogue data structure */
void free_catalogue(BookNode** catalogue);

/* Free list of books recursively */
void free_books(BookNode* book);
