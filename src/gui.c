#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

char pathG[100], findG[100], replaceG[100];

void closeApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}

int button_clicked(GtkWidget *button, GtkWidget **entry)
{
    strcpy (pathG, gtk_entry_get_text(GTK_ENTRY(entry[0])));
    strcpy (findG, gtk_entry_get_text(GTK_ENTRY(entry[1])));
    strcpy (replaceG, gtk_entry_get_text(GTK_ENTRY(entry[2])));
    
    return 0;
}

int gui(char *path, char *find, char *replace)
{
    GtkWidget *window;
    GtkWidget *path_label, *find_label, *replace_label;
    GtkWidget **entry; 
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
    entry[0] = gtk_entry_new(); // path_entry
    entry[1] = gtk_entry_new(); //find_entry
    entry[2] = gtk_entry_new(); //  replace_entry
    
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
