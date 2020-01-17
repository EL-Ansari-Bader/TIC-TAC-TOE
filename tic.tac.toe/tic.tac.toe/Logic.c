#include "Logic.h"

int check_game(int game_matrix[3][3])   //return 1  if X won or2 if O won,0 if it's a tie or the game still on  
{
   
    if (game_matrix[0][0] == game_matrix[0][1] && game_matrix[0][1] == game_matrix[0][2] && game_matrix[0][2] != Void)
        if (game_matrix[0][0] == X) return 1;
        else return 2;

        else if (game_matrix[1][0] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[1][2] && game_matrix[1][2] != Void)
            if (game_matrix[1][0] == X) return 1;
            else return 2;

        else if (game_matrix[2][0] == game_matrix[2][1] && game_matrix[2][1] == game_matrix[2][2] && game_matrix[2][2] != Void)
             if (game_matrix[2][0] == X) return 1;
             else return 2;

        else if (game_matrix[0][0] == game_matrix[1][0] && game_matrix[1][0] == game_matrix[2][0] && game_matrix[2][0] != Void)
              if (game_matrix[0][0] == X) return 1;
              else return 2;

        else if (game_matrix[0][1] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[2][1] && game_matrix[2][1] != Void)
            if (game_matrix[2][1] == X) return 1;
            else return 2;

        else if (game_matrix[0][2] == game_matrix[1][2] && game_matrix[1][2] == game_matrix[2][2] && game_matrix[2][2] != Void)
             if (game_matrix[0][2] == X) return 1;
              else return 2;

        else if (game_matrix[0][0] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[2][2] && game_matrix[2][2] != Void)
                if (game_matrix[0][0] == X) return 1;
                else return 2;
        else if (game_matrix[0][2] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[2][0] && game_matrix[2][0] != Void)
                if (game_matrix[0][2] == X) return 1;
                else return 2;

        return 0;
            
    }

int Board_Is_Full(int game_matrix[3][3]) // return 1 if yes , 0 otherwise
{
    for ( int i = 0;  i < 3;  i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j]==Void)
            {
                return 0;
            }
        }
    }
    return 1;
}








