#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account {
    char name[40];
    int id;
    int hashed_id;
    struct Account *next;
};

typedef struct Account account;

void add_account();
void delete_account(char **name);
int hash_id(char *name); //
void refresh_last_pointer(void); //refreshed last pointer for each array position

account *arr[10];
account *last_accounts[10] = {NULL};

int main(void) {
    return 0;
}

void add_account() {
    char temp_name[40];
    printf("Insert name: ");
    scanf("%s", temp_name);
    int hash = hash_id(temp_name);
    account *new_account = last_accounts[hash];
    if (new_account == NULL) {
        new_account = malloc(sizeof(account));
        strcpy(&(new_account->name), temp_name);
        new_account->hashed_id = hash;
        new_account->next = NULL;
    }
    else {
        ->next = malloc(sizeof(account))
    }
}

void refresh_last_pointer(void) {

}