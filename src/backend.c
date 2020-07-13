#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *time_stamp(char *time_S){ /* current datetime */
    time_t currentTime;
    time(&currentTime);
        
    struct tm *myTime = localtime(&currentTime);
    
    sprintf(time_S, "%i%i%i%i%i%i", myTime->tm_year + 1900, myTime->tm_mon + 1, myTime->tm_mday,  
                                    myTime->tm_hour, myTime->tm_min, myTime->tm_sec );
    
    return time_S;
}

int backup_file(char path[]){
    char command[256];
    char time_S[14];
    int status;
    char pathS[100];

    time_stamp(time_S);

    strncpy(pathS, path, strlen(path)-1);
    
    sprintf(command, "cp %s %s.%s && gzip %s.%s", pathS, pathS, time_S, pathS, time_S);
    
    status = system(command);
    return status;
    
}

FILE *get_file_list(char path[], char pattern[]) {
    FILE *output;
    char command[256]; /* https://issue.life/questions/19354870/bash-command-line-and-input-limit
                        Ограничение на длину командной строки накладывается не оболочкой, 
                        а операционной системой. Этот предел обычно находится в диапазоне сотен килобайт. 
                        POSIX обозначает этот предел, ARG_MAXи в POSIX-совместимых системах вы можете 
                        запросить его с помощью
                        $ getconf ARG_MAX    # Get argument limit in bytes */
    
    sprintf(command, "grep -rl %s %s 2>/dev/null", pattern, path);
    
    /* Open the command's stdout as file for reading. */
    output = popen(command, "r");
    
    if (output == NULL) {
        printf("Command failed\n" );
        exit(1);
    }
    return output;
}

int substitution(FILE *file_list, char pattern[], char replacement[]){
    char path[100];
    char *line;
    char command[256];
    int status;
    
    /* Read file from list. Modify file. Print status*/
    while(fgets (path, sizeof(path), file_list) != NULL ) {
        // char *strncpy(char *toHere, const char *fromHere, size_t n);
        
        backup_file(path);
        sprintf(command, "sed -i 's/%s/%s/g' %s", pattern, replacement, path);
        status = system(command);
        printf("%d - %s\n", status, path);
    }
    
    return 0;
}
