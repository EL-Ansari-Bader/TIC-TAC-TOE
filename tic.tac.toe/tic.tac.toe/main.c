#include <stdlib.h>
#include "Logic.h"
#include <string.h>


void Upload_game(GtkButton* button, gpointer data)
{
    FILE* fichier = fopen("parties.bin", "rb");

    fread(game_matrix, 1, sizeof(game_matrix), fichier);
    fclose(fichier);
    on_btn_2_clicked(button, data);
}


void View_scores(GtkButton* button, gpointer data)
{
    GtkWidget * win= GTK_WIDGET(gtk_builder_get_object(builder, "sc"));
    gtk_widget_show(win);
}

void destroy_window(GtkButton* button, gpointer data) {
    gtk_widget_destroy((GtkWidget*)data);
}

void choose_opp(GtkButton* button, Coord* data)
{
    GtkWidget* win = GTK_WIDGET(gtk_builder_get_object(builder, "vs_choose"));

    GtkButton* button_vs_rand = GTK_BUTTON(gtk_builder_get_object(builder, "Vs_RND"));

    GtkButton* button_vs_AI = GTK_BUTTON(gtk_builder_get_object(builder, "Vs_AI"));

    g_signal_connect(button_vs_rand, "clicked", G_CALLBACK(on_btn_1_clicked), data);
    g_signal_connect(button_vs_rand, "clicked", G_CALLBACK(destroy_window), win);

    g_signal_connect(button_vs_AI, "clicked", G_CALLBACK(on_btn_2_clicked), data);
    g_signal_connect(button_vs_AI, "clicked", G_CALLBACK(destroy_window), win);

    gtk_widget_show(win);

}

void Menu(Coord* data)
{
    GtkWidget* win = GTK_WIDGET(gtk_builder_get_object(builder, "Men"));

    GtkButton *button1 = GTK_BUTTON(gtk_builder_get_object(builder, "btn_1"));

    
    g_signal_connect(button1, "clicked", G_CALLBACK(choose_opp), NULL);
    g_signal_connect(button1, "clicked", G_CALLBACK(destroy_window), win);
    
    
    
    GtkButton *button2 = gtk_builder_get_object(builder, "btn_3");
    g_signal_connect(button2, "clicked", G_CALLBACK(View_scores), NULL);


    GtkButton* button3 = gtk_builder_get_object(builder, "btn_4");
    g_signal_connect(button3, "clicked", G_CALLBACK(Upload_game), NULL);



    gtk_widget_show(win);
    
    
}

//int Find_User(char* username, char* password, FILE* fichier)
//{
//
//    char* line[500];
//    const char* pass, * utilisateur;
//    fscanf_s(fichier, "%s", line);
//    utilisateur = strtok(line, ";");
//    pass = strtok(NULL, ";");
//    if (strcmp(password, pass) == 0 && strcmp(username, utilisateur) == 0)
//    {
//        fclose(fichier);
//        return 1;
//
//    }
//    fclose(fichier);
//    return 0;
//}

void Test_Pass_Word(GtkButton* button, Coord * data)
{
   GtkWidget* lbl = GTK_LABEL(gtk_builder_get_object(builder, "Auth_Label"));
   GtkButton *buttonn= GTK_WIDGET(gtk_builder_get_object(builder, "Confirm"));
  // FILE* fichier=NULL;
  
    const char* password_text = gtk_entry_get_text(GTK_ENTRY((GtkWidget*)(data->PW)));
    const char* username_text = gtk_entry_get_text(GTK_ENTRY((GtkWidget*)(data->UN)));
    int t = 0;
   //fichier = fopen("C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\Players.txt", "a+");
   
               
        char* pass, * utilisateur,*score;
        char line[] = "admin;admin;0";
      // fgets(line, 1000, fichier);
       utilisateur = strtok(line, ";");
       pass = strtok(NULL, ";");
       score= strtok(NULL, ";");
    //   g_print("%s", line);
   //    while (utilisateur != EOF) {
           if (strcmp(password_text, pass) == 0 && strcmp(username_text, utilisateur) == 0)
           {
               t = 1;
               gtk_label_set_label(lbl, "access successful");
               destroy_window(buttonn, data->window);
               Menu(data);
           }
     /*      utilisateur = strtok(line, ";");
           pass = strtok(NULL, ";");
           score = strtok(NULL, ";");
       }*/
       if(t==0) gtk_label_set_label(lbl, "access denied");
 //  fclose(fichier);
}


//void Create_New_Account(GtkButton* button, New_Acc* data)
//{
//    const char* username_text = gtk_entry_get_text(GTK_ENTRY((GtkWidget*)(data->UN)));
//    const char* password_text = gtk_entry_get_text(GTK_ENTRY((GtkWidget*)(data->PW)));
//    const char* repassword_text = gtk_entry_get_text(GTK_ENTRY((GtkWidget*)(data->Re_PW)));
//
//}


void SIGN_IN_OR_UP()
{
    GtkWidget* Main_Widget = GTK_WIDGET(gtk_builder_get_object(builder, "auth"));
    GtkButton* Log_IN_Button = GTK_WIDGET(gtk_builder_get_object(builder, "Confirm"));
   // GtkButton* Sign_UP_Button = GTK_WIDGET(gtk_builder_get_object(builder, "Crea"));


    Coord* user=NULL;
    user = malloc(sizeof(Coord));
    GtkEntry * UserName = GTK_WIDGET(gtk_builder_get_object(builder, "USER")) ;
    GtkEntry* PassWord = GTK_WIDGET(gtk_builder_get_object(builder, "PASSWORD"));
    
    user->UN = GTK_WIDGET(UserName);
    user->PW = GTK_WIDGET(PassWord);
    user->window= GTK_WIDGET(Main_Widget);
    /*New_Acc* New_User = NULL;
    New_User = malloc(sizeof(New_Acc));*/

    //GtkEntry* NUserName = GTK_WIDGET(gtk_builder_get_object(builder, "NvNOM"));
    //GtkEntry* NPassWord = GTK_WIDGET(gtk_builder_get_object(builder, "NvMDP"));
    //GtkEntry* CNPassWord = GTK_WIDGET(gtk_builder_get_object(builder, "ReNvMDP"));

    //New_User->UN = GTK_WIDGET(NUserName);
    //New_User->PW = GTK_WIDGET(NPassWord);
    //New_User->Re_PW = GTK_WIDGET(CNPassWord);
    //New_User->score = 0;
    
    g_signal_connect(Log_IN_Button, "clicked", G_CALLBACK(Test_Pass_Word), user);
   // g_signal_connect(Sign_UP_Button, "clicked", G_CALLBACK(Create_New_Account), New_User);
                              
   

    gtk_widget_show(Main_Widget);
}

int main(int argc, char** argv)
{
    

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
    gtk_builder_add_from_file(builder, "C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\VS.glade", NULL);
    gtk_builder_add_from_file(builder, "C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\scores.glade", NULL);

    GtkCssProvider* cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "C:\\Users\\ROG STRIX\\Desktop\\C project\\TIC-TAC-TOE\\TIC-TAC-TOE\\x64\\Debug\\theme.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(cssProvider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);

    SIGN_IN_OR_UP();


    gtk_main();
   
    return 0;
}