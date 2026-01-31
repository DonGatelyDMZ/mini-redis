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
typedef account *accPtr;

void add_account(account * last_account);
void delete_account(char *name);
int hash_id(char *name);

account arr[10];

int main(void) {
    return 0;
}

