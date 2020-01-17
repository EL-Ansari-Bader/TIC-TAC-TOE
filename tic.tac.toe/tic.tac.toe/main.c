#include <stdlib.h>
#include "Logic.h"




void Menu(GtkButton* Widget_Button,gpointer user_data)
{
    GtkWidget* win = GTK_WIDGET(gtk_builder_get_object(builder, "Men"));

    GtkButton *button1 = GTK_BUTTON(gtk_builder_get_object(builder, "btn_1"));

    g_signal_connect(button1, "clicked", G_CALLBACK(on_btn_1_clicked), NULL);
    
    //button2 = gtk_builder_get_object(builder, "btn_2");
    //g_signal_connect(button2, "clicked", G_CALLBACK(on_btn_2_clicked), NULL);

    gtk_widget_show(win);
}


void SIGN_IN_OR_UP()
{
    GtkWidget* Main_Widget = GTK_WIDGET(gtk_builder_get_object(builder, "auth"));
    GtkButton* Log_IN_Button = GTK_WIDGET(gtk_builder_get_object(builder, "Confirm"));
    GtkEntry* UserName = gtk_builder_get_object(builder, "User") ;
    char* Nom = gtk_entry_get_text(UserName);
    g_print("%s", Nom);


    g_signal_connect(Log_IN_Button, "clicked", G_CALLBACK(Menu), NULL);

    gtk_widget_show(Main_Widget);
}

int main(int argc, char** argv)
{
    /* Variables */
     //GtkWidget* MainWindow = NULL;

    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            game_matrix[i][j] = Void;
    }

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\menu.glade", NULL);
    gtk_builder_add_from_file(builder, "C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\tic.glade", NULL);
    gtk_builder_add_from_file(builder, "C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\auth.glade", NULL);
    GtkCssProvider* cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\theme.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(cssProvider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);

    SIGN_IN_OR_UP();


    gtk_main();

    return 0;
}