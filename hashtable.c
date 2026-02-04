#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account {
    char name[40];
    int id;
    int hashed_id;
    struct Account *next;
    struct Account *former;
};

typedef struct Account account;

void add_account();
void delete_account(char **name);
int hash_id(char *name); //
void refresh_last_pointer(int id, account *new_account); //refreshed last pointer for each array position
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
    account *last = last_accounts[hash];
    if (last->next == NULL) {
        account *new_account = malloc(sizeof(account));
        strcpy(&(new_account->name), temp_name);
        new_account->hashed_id = hash;
        new_account->next = NULL;
        new_account->former = last;
        refresh_last_pointer(hash, new_account);
    }
    else if (last == NULL){
        last = malloc(sizeof(account));
        strcpy(&(last->name), temp_name);
        last->hashed_id = hash;
        last->next = NULL;
        refresh_last_pointer(hash, last);
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