#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    while (1) {
        int savecounter = 0;
        char command[50];
        printf(">>");
        scanf(" %s", command);
        char token = strtok(command, " ");
        if (token != NULL ) {
            if (!strcmp(token, "SET") || !(!strcmp(token, "set"))) {
                
            }
            else if (!strcmp(token, "GET") || !strcmp(token, "get")) {

            }
            else if (!strcmp(token, "DEL") || !strcmp(token, "del")) {

            }
            else if(!strcmp(token, "SAVE") || !strcmp(token, "save")) {

            }
            else if(!strcmp(token, "SAVE") || !strcmp(token, "save")) {
                if (savecounter == 0) printf("Are you sure to exit withoout saving? ") {

                }
            }
            else {
                puts("Command not found");
                continue;
            }
        }
    }
    return 0;
}
