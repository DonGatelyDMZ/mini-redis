#ifndef HASHTABLE_H
#define HASHTABLE_H

#define SIZE 1000

typedef struct Account {
    char name[40];
    int hashed_id;
    int value;
    struct Account *next;
    struct Account *former;
} account;

void add_account(char name[40], int value);
void delete_account(char *name);
account* search(int hashed_id, char *name);
void print_account(account *acc);
int save(void);
void load(void);
int hash_id(char *name);

#endif