#include <gtk/gtk.h>
//---------------------------------------------------------------
//                                GUI
//---------------------------------------------------------------

void closeApp(GtkWidget *window, gpointer data);

int button_clicked(GtkWidget *button, GtkWidget **entry);

int gui(char *path, char *find, char *replace);

//---------------------------------------------------------------
//                               Backend
//---------------------------------------------------------------

char *time_stamp(char *time_S);

int backup_file(char path[]);

FILE *get_file_list(char path[], char pattern[]); 

int substitution(FILE *file_list, char pattern[], char replacement[]);

//-------------------------------------------------------------
