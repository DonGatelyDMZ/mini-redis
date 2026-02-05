#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

struct Account {
    char name[40];
    int hashed_id;
    int value;
    struct Account *next;
    struct Account *former;
};

typedef struct Account account;

/* Functions prototypes 
- add_account: adds an account
- delete_account: deletes an account
- hash_id: gives an id based on the account's name
- refresh_last_pointer: for every position in the table, it keeps the last account pointer
- search: looks for an account by his name
- print_account: you know
*/
void add_account(char name[40], int value);
void delete_account(char *name);
int hash_id(char *name); //
void refresh_last_pointer(int id, account *new_account);
account* search(int hashed_id, char *name);
void print_account(account *acc);

account *first_accounts[SIZE] = {NULL};
account *last_accounts[SIZE] = {NULL};

int main(void) {
    return 0;
}

void add_account(char name[40], int value) {
    int hash = hash_id(name);
    account *last = last_accounts[hash];
    if (last == NULL){
        last = malloc(sizeof(account));
        strcpy(last->name, name);
        last->hashed_id = hash;
        last->next = NULL;
        last->former = NULL;
        last->value = value;
        first_accounts[hash] = last;
        refresh_last_pointer(hash, last);
    }
    else if (last->next == NULL) {
        account *new_account = malloc(sizeof(account));
        strcpy(new_account->name, name);
        new_account->hashed_id = hash;
        new_account->next = NULL;
        new_account->former = last;
        new_account->value = value;
        refresh_last_pointer(hash, new_account);
    }
}

void refresh_last_pointer(int id, account *new_account) {
    account *temp = last_accounts[id];
    if (temp == NULL) {
        last_accounts[id] = new_account;
    }
    temp->next = new_account;
    last_accounts[id] = new_account;
}

int hash_id(char *name) {
    return ((int)*name)%SIZE;
}

void delete_account(char *name) { //todo: add cases 1) first one 2) last one
    account *acc = search(hash_id(name), name);
    if (acc != NULL) {
        acc->former->next = acc->next;
        free(acc);
    }
}

account* search(int hashed_id, char *name) {
    account *start = first_accounts[hashed_id];
    if (start == NULL) {
        puts("Account does not exists");
        return NULL;
    }
    account **curr = &start;
    char test[40];
    strcpy(test, (*curr)->name);
    while (strcmp((*curr)->name, name) != 0) {
        if (*curr == last_accounts[hashed_id]) {
            puts("Account does not exists");
            return NULL;
        }
        else *curr = (*curr)->next;
    }
    return *curr;
}

void print_account(account *acc) {
    printf("Name: %s\nValue: %d\n", acc->name, acc->value);
}