#ifndef PLAYER2_SCENE
#define PLAYER2_SCENE

#include "global_vars.h"

enum GAME_SIGN {Void, X, O};

int game_matrix[3][3];
int Detect_free_case(int game_matrix[3][3]);


void on_canvas_draw(GtkWidget* widget, cairo_t* cr, gpointer data);
void on_btn_1_clicked(GtkButton* button, gpointer user_data);
void human_move(GtkWidget* Widget, GdkEventButton* event, gpointer user_data);
void Restart_New_Game(GtkWidget* Widget, gpointer user_data);

#endif // !2PLAYER_SCENE
