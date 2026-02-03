#include "bsq.h"

int alg_bsq(t_map *map)
{
    int **ip=calloc(map->row,sizeof(int *));
        if(!ip)
            return(0);
    for(int i =0;i<map->row;i++)
        ip[i]=calloc(map->col,sizeof(int));

    int best=0;
    int best_i=0;
    int best_j=0;

    for (int i = 0; i < map->row; i++)
    {
        for(int j =0;j<map->col;j++)
        {
            if(map->grid[i][j]==map->empty)
            {
                if(i == 0 || j==0)
                    ip[i][j]=1;
                
                else
                {
                    int up = ip[i-1][j];
                    int left = ip[i][j-1];
                    int diag=ip[i-1][j-1];
                    int min=left<up?left:up;
                        if(diag<min)
                            min=diag;
                    ip[i][j] = min+1;
                }

                if(ip[i][j] > best)
                {
                    best=ip[i][j];
                    best_i=i;
                    best_j=j;
                }
            }
        }
    }

    for (int i = best_i-best +1; i <= best_i; i++)
    {
        for(int j =best_j-best +1;j<=best_j;j++)
        {
            map->grid[i][j]=map->full;
        }
    }

    for(int i=0;i<map->row;i++)
        free(ip[i]);
    free(ip);
    return(1);
}