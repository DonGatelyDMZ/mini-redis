#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Instructions: \n");
    printf("1) SET key:value\n");
    printf("2) GET key\n");
    printf("3) DEL key\n");
    printf("4) SAVE\n");
    printf("5) Any other: Exit\n\n");
    int savecounter = 0;
    load();
    while (1) {
        char istruction[50];
        printf(">> ");
        fgets(istruction, 50, stdin);
        char *command = strtok(istruction, " ");
        if (command != NULL ) {
            if (!strcmp(command, "SET") || !(!strcmp(command, "set"))) {
                char *name = strtok(NULL, ":");
                int value = atoi(strtok(NULL, " "));
                add_account(name, value);
            }

            else if (!strcmp(command, "GET") || !strcmp(command, "get")) {
                char *name = strtok(NULL, " ");
                print_account(search(hash_id(name), name));
            }

            else if (!strcmp(command, "DEL") || !strcmp(command, "del")) {
                char *name = strtok(NULL, " ");
                delete(name);
            }
            else if(!strcmp(command, "SAVE") || !strcmp(command, "save")) {
                save();
                savecounter++;
            }
            else if(!strcmp(command, "EXIT") || !strcmp(command, "exit")) {
                if (savecounter == 0) {
                    printf("Are you sure to exit withoout saving? y/n");
                }
                else exit(0);
            }
            else {
                puts("Error: Command not found");
                continue;
            }
        }
    }
    return 0;
}
