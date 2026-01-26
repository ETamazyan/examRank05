#include "bsq.h"

void print_grid(t_map *map)
{
    for (int i = 0; i < map->row; i++)
    {
        fprintf(stdout,"%s\n",map->grid[i]);
    }
}
void free_grid(t_map *map)
{
    if(!map || map->grid) //moranum em misht 
        return ;
    for (int i = 0; i < map->row; i++)
    {
        free(map->grid[i]);
    }
    free(map->grid);
}
int main(int argc,char **argv)
{
    t_map map;

    map.row =0;
    map.col=0;
    map.grid=NULL;

    if(argc ==1)
    {
        if(!read_from_stdin(&map))
        {
            free_grid(&map);
            fprintf(stdout,"%s\n","map is invalid");
            return(1);//main um errori depwum 0 enq veradardznum
        }
        if(!alg_bsq(&map))
        {
            free_grid(&map);
            fprintf(stdout,"%s\n","malloc error");
            return(1);
        }
        print_grid(&map);
        free_grid(&map);
        return(0);
    }
    if(argc!=2)
    {
        free_grid(&map);
            fprintf(stdout,"%s\n","map is invalid");
            return(1);
    }

    if(!read_map(argv[1],&map))
    {
        free_grid(&map);
            fprintf(stdout,"%s\n","map is invalid");
            return(1);
    }

    if(!alg_bsq(&map))
    {
        free_grid(&map);
            fprintf(stdout,"%s\n","malloc error");
            return(1);
    }
    print_grid(&map);
        free_grid(&map);
        return(0);

}