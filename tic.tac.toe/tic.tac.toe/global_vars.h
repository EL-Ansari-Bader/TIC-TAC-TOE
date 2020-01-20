#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H

#include <gtk/gtk.h>
#include <time.h>


GtkBuilder* builder;

typedef struct MyStruct
{
	GtkEntry* UN;
	GtkEntry* PW;

}Coord;
typedef struct _new
{
	GtkEntry* UN;
	GtkEntry* PW;
	GtkEntry* Re_PW;
	int score;
}New_Acc;
typedef struct _user
{
	GtkEntry* UN;
	GtkEntry* PW;
	GtkEntry* Re_PW;
	int score;
}User;

void Menu();

//int Find_User(char* username, char* password, FILE* fichier);
void Test_Pass_Word(GtkButton* button, Coord* data);
//void Create_New_Account(GtkButton* button, New_Acc* data);
void choose_opp(GtkButton* button, gpointer user_data);

#endif