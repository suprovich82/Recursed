#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "recursed.h"
#include <gtk/gtk.h>
 
int main(int argc, char *argv[])
{
    char path[100];
    char find[100];
    char replace[100];
    FILE *file_list;
    
    gtk_init(&argc, &argv);
    
    gui(path, find, replace);
    
    file_list = get_file_list(path, find); 
       
    substitution(file_list, find, replace);
      
    pclose(file_list);
    
    return 0;
}

