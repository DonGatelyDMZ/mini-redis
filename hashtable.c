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
- search: looks for an account by its name
- print_account: you know
*/
void add_account(char name[40], int value);
void delete_account(char *name);
int hash_id(char *name); //
account* search(int hashed_id, char *name);
void print_account(account *acc);
int save(void);
void load(void);

account *stack[SIZE] = {NULL};

int main(void) {
    return 0;
}

void add_account(char name[40], int value) {
    int hash = hash_id(name);
    account *new_node = malloc(sizeof(account));
    strcpy(new_node->name, name);

    new_node->value = value;
    new_node->hashed_id = hash;
    new_node->next = stack[hash];
    if (stack[hash] != NULL) {
        stack[hash]->former = new_node;
    }
    new_node->former = NULL;
    stack[hash] = new_node;
}

int hash_id(char *name) {
    int sum = 0;
    int k = 0;
    while (*(name + k) != '\0') {
        sum+=(int)*(name+k);
        k++;
    }
    return sum%SIZE;
}

void delete_account(char *name) {
    account *acc = search(hash_id(name), name);
    if (acc == stack[hash_id(name)]) {
        stack[hash_id(name)] = acc->next;
        free(acc);
    }
    else if (acc->next == NULL) {
        acc->former->next = NULL;
        free(acc);
    }
    else if (acc != NULL) {
        acc->former->next = acc->next;
        free(acc);
    }
}

account* search(int hashed_id, char *name) {
    account *curr = stack[hashed_id];
    while (curr != NULL) {
        if (!strcmp(curr->name, name)) return curr;
        curr = curr->next;
    }
    return NULL;
}

void print_account(account *acc) {
    printf("Name: %s\nValue: %d\n", acc->name, acc->value);
}

int save(void) {
    FILE *database = fopen("dump.db", "w+");
    if (database == NULL) {
        perror("absent database");
        return 1;
    }
    for (size_t i = 0; i < SIZE; i++) {
        account *sav_acc = stack[i];
        while (sav_acc != NULL) {
            fprintf(sav_acc, "%s %d\n", sav_acc->name, sav_acc->value);
            sav_acc = sav_acc->next;
        }
    }
    fclose(database);
    return 0;
}

void load(void) {
    FILE *database = fopen("dump.db", "r+");
    if (database == NULL) {
        perror("absent database");
        return 1;
    }
    char name[40];
    int value;
    while(fscanf(database, "%s %d", name, &value) != EOF) {
        add_account(name, value);
    }
    fclose(database);
}