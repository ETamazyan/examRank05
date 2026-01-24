#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"

void free_board(t_map *map)
{
    if(!map || map->grid) //bbb
        return ;
    for (int i = 0; i < map->row;i++)
    {
        free(map->grid[i]);
    }
    free(map->grid);
}
void print_grid(t_map *map)
{
    for(int i =0;i <map->row;i++)
        fprintf(stdout,"%s\n",map->grid[i]);
}
int main(int argc, char **argv)
{
    t_map map;

    map.row=0;
    map.col=0;
    map.grid=NULL;

    if(argc ==1)
    {
        if(!read_from_stdin(&map))
        {
            fprintf(stdout,"%s\n","Error:invalid map1");
            free_board(&map);
            return(1);
        }
        if(!alg_bsq(&map))
        {
             fprintf(stdout,"%s\n","Error:invalid map2");
            free_board(&map);
            return(1);
        }
        print_grid(&map);
        free_board(&map);
        return(1);
    }

    if(argc != 2)
    {
        fprintf(stdout,"%s\n","Error:invalid map3");
        free_board(&map);
            return(1);
    }

    if(!read_map(argv[1],&map))
    {
        fprintf(stdout,"%s\n","Error:invalid map4");
        free_board(&map);
        return(1);
    }
    if(!alg_bsq(&map))
    {
        fprintf(stdout,"%s\n","Error:invalid map5");
        free_board(&map);
        return(1);
    }
    printf("gndak\n");
    print_grid(&map);
    free_board(&map);
    return(0);
}