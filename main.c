#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CHAR 255

char input[MAX_CHAR];
char backup[MAX_CHAR];
char *command;
char delim[2] = " ";
char *token;
char **args;
char **env;
char *currentDir;

void parser() {
    int argCount = 0;
    input[strnlen(input, MAX_CHAR) - 1] = 0;
        strncpy(backup, input, sizeof(input));

        token = strtok(input, delim);

        while(token != NULL) { //using this to grab how many tokens there actually are
            argCount++;
            token = strtok(NULL, delim);
        }

        token = strtok(backup, delim);
        command = token;

        args = malloc(argCount * sizeof(char *));

        for (int i = 0; i < argCount; i++) {
            args[i] = malloc(MAX_CHAR * sizeof(char));
        }

        for (int j = 0; j < argCount; j++) {
            strcpy(args[j], token);
            token = strtok(NULL, delim);
        }

        //code starts here
        
        

        //code ends here

        for (int k = 0; k < argCount; k++) {
            free(args[k]);
        }

    free(args);
}

int main() {

    char *username = getenv("USER");
    char *home = getenv("HOME");
    chdir(home);
    currentDir = home;

    while (1) {

        printf("%s@%s > ", username, currentDir);
        fgets(input, MAX_CHAR, stdin);

        parser();
    }
    return 0;
}