#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

/// @pathG: global variable to pull out Path value entered in GUI
char pathG[100];
/// @findG: global variable to pull out Find value entered in GUI
char findG[100];
/// @replaceG: global variable to pull out Replace value entered in GUI  * 
char replaceG[100];

/// closeApp(): funcion to close graphical window. 
void closeApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}

/// button_clicked(): funcion that defines ations to be taken once 'OK' button clicked.
///* @button: actual button that was clicked. Not used in function's body.
///* @entry: array of Gtk entries to extract data from: 
///         - entry[0]: path to file of folder where pattern need to be replaced.
///         - entry[1]: pattern that need to be replaced (regular expression).
///         - entry[2]: string to be substituted insted of pattern inclusions.
///
int button_clicked(GtkWidget *button, GtkWidget **entry)
{
    strcpy (pathG, gtk_entry_get_text(GTK_ENTRY(entry[0])));
    strcpy (findG, gtk_entry_get_text(GTK_ENTRY(entry[1])));
    strcpy (replaceG, gtk_entry_get_text(GTK_ENTRY(entry[2])));
    
    return 0;
}

/// gui(): function that implements GUI as text form to collect parameters from user.
///        Parameters are pushed to upsream function via arguments.
///
///* @path, @find, @replace: variables declared in upstring function that are used to push entered data back.           
///
int gui(char *path, char *find, char *replace)
{
    GtkWidget *window;
    GtkWidget *path_label, *find_label, *replace_label;
    GtkWidget **entry; // array of gtk entries.
    GtkWidget *ok_button;
    GtkWidget *hbox1, *hbox2, *hbox3;
    GtkWidget *vbox;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GtkEntryBox");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 220);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);

    path_label = gtk_label_new("Path: ");
    find_label = gtk_label_new("Find: ");
    replace_label = gtk_label_new("Replace: ");
    
    gtk_label_set_width_chars(GTK_LABEL(path_label), 5);
    gtk_label_set_width_chars(GTK_LABEL(find_label), 5);
    gtk_label_set_width_chars(GTK_LABEL(replace_label), 5);

    entry = malloc(3 * sizeof(GtkWidget));
    entry[0] = gtk_entry_new(); 
    entry[1] = gtk_entry_new(); 
    entry[2] = gtk_entry_new(); 
    
    gtk_entry_set_width_chars(GTK_ENTRY(entry[0]), 55);
    gtk_entry_set_width_chars(GTK_ENTRY(entry[1]), 55);
    gtk_entry_set_width_chars(GTK_ENTRY(entry[2]), 55);
    
    ok_button = gtk_button_new_with_label("OK"); 
   
    g_signal_connect(G_OBJECT(ok_button), "clicked", G_CALLBACK(button_clicked), entry);
    g_signal_connect(G_OBJECT(ok_button), "clicked", G_CALLBACK(closeApp), NULL);
    
    hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    hbox3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    gtk_box_pack_start(GTK_BOX(hbox1), path_label, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox1), entry[0], TRUE, FALSE, 40);

    gtk_box_pack_start(GTK_BOX(hbox2), find_label, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox2), entry[1], TRUE, FALSE, 40);
    
    gtk_box_pack_start(GTK_BOX(hbox3), replace_label, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox3), entry[2], TRUE, FALSE, 40);
    
    
    gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox3, FALSE, FALSE, 5);
    
    gtk_box_pack_start(GTK_BOX(vbox), ok_button, FALSE, FALSE, 40);
    
    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_show_all(window);

    gtk_main();
    
    strcpy (path, pathG);
    strcpy (find, findG);
    strcpy (replace, replaceG);
    
    return 0;
}
