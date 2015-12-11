#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int MSG_SIZE = 30;

char* read_message();
void print_message(char* message);

int main()
{
    const int TOTAL_MESSAGE_SIZE = 2*MSG_SIZE;
    char final_message[TOTAL_MESSAGE_SIZE];

    char* message1 = read_message();
    print_message(message1);

    char* message2 = read_message();
    print_message(message2);

    strcpy(final_message, message1);
    strcat(final_message, message2);

    print_message(final_message);
    
    free(meesage1);
    free(message2);
}


char* read_message()
{
    char* message = malloc(sizeof(char)*MSG_SIZE);

    printf("Enter some text (<30 chars)\n");
    scanf(" %[A-Za-z ]", message);

    return message;
}

void print_message(char* message)
{
    printf("The message was: %s\n", message);
    printf("The length of the message is %d\n", strlen(message));
}
