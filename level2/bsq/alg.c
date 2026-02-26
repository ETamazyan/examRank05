#include "bsq.h"

int alg_bsq(t_map *map)
{
    int **dp = calloc(map->row, sizeof(int *));
    if (!dp)
        return 0;

    for (int row = 0; row < map->row; row++)
        dp[row] = calloc(map->col, sizeof(int));

    int max_size = 0;
    int max_row = 0;
    int max_col = 0;

    for (int row = 0; row < map->row; row++)
    {
        for (int col = 0; col < map->col; col++)
        {
            if (map->grid[row][col] == map->empty)
            {
                if (row == 0 || col == 0)
                    dp[row][col] = 1;
                else
                {
                    int up   = dp[row - 1][col];
                    int left = dp[row][col - 1];
                    int diag = dp[row - 1][col - 1];

                    int min = up < left ? up : left;
                    if (diag < min)
                        min = diag;

                    dp[row][col] = 1 + min;
                }

                if (dp[row][col] > max_size)
                {
                    max_size = dp[row][col];
                    max_row = row;
                    max_col = col;
                }
            }
        }
    }
    for (int i = max_row - max_size + 1; i <= max_row; i++)
        for (int j = max_col - max_size + 1; j <= max_col; j++)
            map->grid[i][j] = map->full;
    for (int row = 0; row < map->row; row++)
        free(dp[row]);
    free(dp);

    return 1;
}


// int alg_bsq(t_map *map)
// {
//     int **ib = calloc(map->row,sizeof(int *));
//     if(!ib)
//         return(0);

//     for(int i = 0; i < map->row; i++)
//         ib[i]=calloc(map->col,sizeof(int));
    
//     int best = 0; 
//     int best_i=0; 
//     int best_j=0;

//     for(int i = 0; i < map->row; i++)
//     {
//         for(int j = 0;j < map->col; j++)
//         {
//             if(map->grid[i][j] == map->empty) //empty stugum
//             {
//                 if(i ==0 || j == 0)
//                     ib[i][j] = 1;
//                 else
//                 {
//                     int up = ib[i-1][j];
//                     int left =ib[i][j-1];
//                     int diag = ib[i-1][j-1];
//                     int min = up < left ? up:left;
//                     if(diag < min)
//                         min = diag;
//                     ib[i][j] = 1 + min;//ogtagortsel miny
//                 }
//                 if (ib[i][j] > best)
//                 {
//                     best = ib[i][j];
//                     best_i = i;
//                     best_j = j;
//                 }
//             }
//         }
//     }

//     for(int i = best_i-best + 1; i <= best_i; i++)
//     {
//         for(int j = best_j-best + 1; j <= best_j; j++)
//             map->grid[i][j] = map->full;
//     }
//     for (int i =0; i < map->row; i++)//free
//         free(ib[i]);
//     free(ib);
//     return(1);
// }