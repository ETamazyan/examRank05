#include "bsq.h"

int alg_bsq(t_map *map)
{
    int **ib = calloc(map->row,sizeof(int *));
    if(!ib)
        return(0);

    for(int i = 0; i < map->row; i++)
        ib[i]=calloc(map->col,sizeof(int));
    
    int best = 0; 
    int best_i=0; 
    int best_j=0;

    for(int i = 0; i < map->row; i++)
    {
        for(int j = 0;j < map->col; j++)
        {
            if(map->grid[i][j] == map->empty) //empty stugum
            {
                if(i ==0 || j == 0)
                    ib[i][j] = 1;
                else
                {
                    int up = ib[i-1][j];
                    int left =ib[i][j-1];
                    int diag = ib[i-1][j-1];
                    int min = up < left ? up:left;
                    if(diag < min)
                        min = diag;
                    ib[i][j] = 1 + min;//ogtagortsel miny
                }
                if (ib[i][j] > best)
                {
                    best = ib[i][j];
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }

    for(int i = best_i-best + 1; i <= best_i; i++)
    {
        for(int j = best_j-best + 1; j <= best_j; j++)
            map->grid[i][j] = map->full;
    }
    for (int i =0; i < map->row; i++)//free
        free(ib[i]);
    free(ib);
    return(1);
}