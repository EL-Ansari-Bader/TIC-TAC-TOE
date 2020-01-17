#include "Logic.h"


void on_canvas_draw(GtkWidget* widget, cairo_t* cr, gpointer data)
{
    guint width, height;
    GdkRGBA color;
    GtkStyleContext* context;

    context = gtk_widget_get_style_context(widget);

    width = gtk_widget_get_allocated_width(widget);
    height = gtk_widget_get_allocated_height(widget);

    int cell_width = width / 3;
    int cell_height = height / 3;

    gtk_render_background(context, cr, 0, 0, width, height);

    gtk_style_context_get_color(context,
        gtk_style_context_get_state(context),
        &color);
    gdk_cairo_set_source_rgba(cr, &color);

    cairo_rectangle(cr, width / 3, 0, 1, height);
    cairo_rectangle(cr, 2 * cell_width + 1, 0, 1, height);

    cairo_rectangle(cr, 0, height / 3, width, 1);
    cairo_rectangle(cr, 0, 2 * cell_height + 1, width, 1);

    for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j] == X)
            {
                cairo_move_to(cr, j * cell_width , i * cell_height);
                cairo_line_to(cr, (j + 1) * cell_width, (i + 1) * cell_height);
                cairo_move_to(cr, (j + 1) * cell_width, i * cell_height);
                cairo_line_to(cr, j * cell_width, (i + 1) * cell_height);
                cairo_close_path(cr);
                cairo_stroke(cr);
            }
            if (game_matrix[i][j] == O)
            {
                cairo_arc(cr,
                            j * cell_width + (cell_width / 2), i * cell_height + (cell_height / 2),
                            (MIN(cell_width, cell_height) / 2) - 10,
                            0, 2 * G_PI);
                cairo_close_path(cr);
                cairo_stroke(cr);
            }
        }

    cairo_fill(cr);
}
int Detect_free_case(int game_matrix[3][3])
{   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j] == Void) return 1;
        }
    }
    return 0;
}
void Computer_random_move()
{
    int x, y;
    GtkDrawingArea* cr = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "canvas"));
    int width = gtk_widget_get_allocated_width(cr);
    int height = gtk_widget_get_allocated_height(cr);
    while (Detect_free_case(game_matrix) && check_game(game_matrix)==0)
    {
        y = rand() % 3;
        x = rand() % 3;
        if (game_matrix[y][x] == Void ) 
        { 
            game_matrix[y][x] = O ; 
            gtk_widget_queue_draw_area(cr, 0, 0, width, height); 
            break; 
        }
    }

}
void human_move(GtkWidget* Widget, GdkEventButton* event, gpointer user_data)
{
    int x = event->x, y = event->y;
    int width = gtk_widget_get_allocated_width(Widget);
    int height = gtk_widget_get_allocated_height(Widget);
    int x1 = x / (width / 3);
    int y1 = y/(height /3) ;
    GtkWidget* label = GTK_LABEL(gtk_builder_get_object(builder, "lbl"));

    if (game_matrix[y1][x1] == Void && check_game(game_matrix)==0)
    {
        game_matrix[y1][x1] = X;
        Computer_random_move();
        gtk_widget_queue_draw_area(Widget, 0, 0, width, height);
        
    }
    if (check_game(game_matrix) == 1)
    {
        gtk_label_set_label(label, "X won");
    }
    else
    {
        if (check_game(game_matrix) == 2)
        {
            gtk_label_set_label(label, "O won");
        }
        else if (Board_Is_Full(game_matrix) == 1) gtk_label_set_label(label, " The game is a tie ");
    }
  
    
}

void Restart_New_Game(GtkWidget* Widget, gpointer user_data)
{
    GtkWidget* label = GTK_LABEL(gtk_builder_get_object(builder, "lbl"));
    GtkDrawingArea* cr = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "canvas"));

    int width = gtk_widget_get_allocated_width(cr);
    int height = gtk_widget_get_allocated_height(cr);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            game_matrix[i][j] = Void;
    }

    gtk_widget_queue_draw_area(cr, 0, 0, width, height);
    gtk_label_set_label(label, " Make a Move by clicking a block ");

}


void on_btn_1_clicked(GtkButton* button, gpointer user_data)
{

    GtkWidget * player2_scene = GTK_WIDGET(gtk_builder_get_object(builder, "tic"));
	GtkDrawingArea* cr = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "canvas"));
    
    gtk_widget_add_events(cr, GDK_BUTTON_PRESS_MASK);
    
    g_signal_connect(cr, "draw", G_CALLBACK(on_canvas_draw), NULL);
    
    
    g_signal_connect(cr, "button-press-event", G_CALLBACK(human_move), NULL);
   
   
    
    GtkButton *New_Game_button = GTK_WIDGET(gtk_builder_get_object(builder, "RePLAY"));
    g_signal_connect(New_Game_button, "clicked", G_CALLBACK(Restart_New_Game), NULL);
   



	gtk_widget_show(player2_scene);
}
