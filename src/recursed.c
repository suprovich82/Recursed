#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utility.h"
#include <gtk/gtk.h>


// int main( int argc, char *argv[] )
// {

    // FILE *file_list;
    // char path[100]; /* path to file or folder */
    // char reg_expr[20]; /* pattern to be replaced */
    // char replacement[20]; /* replacement */
    // char command[256]; /* command to search files that contain pattern */
    // char file_name[100]; /* wariable to read command's output line by line */ 
  
    // // sprintf(path, "/home/sup/Desktop/GL/01_Introduction"); 
    // // sprintf(path, "/home/sup/01_Introduction"); 
    // // sprintf(reg_expr, "Main");
    // // sprintf(replacement, "main");

    // file_list = get_file_list(path, reg_expr); 
       
    // substitution(file_list, reg_expr, replacement);
      
    // pclose(file_list);
//     return 0;
// }    
    int main(int argc, char *argv[])
{
    char path[100];
    char find[100];
    char replace[100];
    
    gtk_init(&argc, &argv);
    
    gui(path, find, replace);
    
    printf("Path - %s %s %s \n", path, find, replace);
    
    return 0;
}

