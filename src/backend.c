#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///  time_stamp(): funcion returns current date and time in format of 'YYYYMMDDhhmmss'.
///
char *time_stamp(char *time_S){
    time_t currentTime;
    time(&currentTime);
        
    struct tm *myTime = localtime(&currentTime);
    
    sprintf(time_S, "%i%i%i%i%i%i", myTime->tm_year + 1900, myTime->tm_mon + 1, myTime->tm_mday,  
                                    myTime->tm_hour, myTime->tm_min, myTime->tm_sec );
    
    return time_S;
}

/// backup_file(): funtion creates a backup copy of each modified file.
///
/// Backup copy is created as gzip archive that folows name convention <original_file_name>.<timestamp>.gz
///
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

/// get_file_list(): function to prepare list of files that have pattern in them. 
///* @path[]: path to file or folder to search in. Respective value provided by user in GUI as 'Path'.
///* @pattern[]: regular expression provided by user in GUI as 'Find'.
///
/// Return: function returnes *FILE that points to command's output which is list of required files.
/// 
FILE *get_file_list(char path[], char pattern[]) {
    FILE *output;
    char command[256]; 
    
    sprintf(command, "grep -rl '%s' %s 2>/dev/null", pattern, path);
  
    // Open the command's output as file for reading.
    output = popen(command, "r");
    
    if (output == NULL) {
        printf("Command failed\n" );
        exit(1);
    }
    
    return output;
}

/// substitution(): function that substitutes each pattern inclusion whith replacement.
///
///* @file_list: pointer to list of files that need to be modified.
///* @pattern[]: pattern to be replaced in form of regular expression.
///* @replacement[]: string that should replace each pattern inclusion.
/// 
int substitution(FILE *file_list, char pattern[], char replacement[]){
    char path[100];
    char *line;
    char command[256];
    int status;
    
    // Read file from list. Modify file.
    while(fgets (path, sizeof(path), file_list) != NULL ) {       
        backup_file(path);
        sprintf(command, "sed -i 's/%s/%s/g' %s", pattern, replacement, path);
        status = system(command);
    }
    
    return 0;
}
