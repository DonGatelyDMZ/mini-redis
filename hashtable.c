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

void add_account(char name[40], int value);
void delete_account(char *name);
int hash_id(char *name); //
void refresh_last_pointer(int id, account *new_account); //refreshed last pointer for each array position
account* search(int hashed_id, char *name);
void print_account(account *acc);

account *arr[SIZE];
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
    temp->next = new_account;
    last_accounts[id] = new_account;
}

int hash_id(char *name) {
    return ((int)*name)%10;
}

void delete_account(char *name) {
    account *acc = search(hash_id(name), name);
    account *former = acc->former;
    account *next = acc->next;
    
    (acc->former)->(acc->next);
    
}

account* search(int hashed_id, char *name) {

}

void print_account(account *acc) {

}