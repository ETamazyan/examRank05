#include "bsq.h"

static int ft_atoi(char *num)
{
    int sign = 1;
    int res =0;

    if(*num == '-')
    {
            sign = -1;
            num++;
    }
    else if(*num =='+')//else
        num++;
    while(*num && (*num >= '0' && *num <= '9'))
    {
        res = res * 10 + (*num - '0');
        num++;
    }
    return((sign * res));
}
static int pars_line(FILE *file,t_map *map)
{
    char *line=NULL;
    size_t n =0;

    ssize_t len = getline(&line,&n,file);

    if(line[len -1] == '\n')
    {

        line[--len]='\0';
    }
    
    int tiv =ft_atoi(line);
        map->row = tiv;
        if(tiv <= 0)
        return(free(line),0);
        
    int i =0;
    while(line[i] && (line[i] >= '0' && line[i] <= '9'))
        i++;
    
    if(line[i] == '\0')
        return(free(line),0);
    map->empty = line[i];
    
    if(line[++i] == '\0')
        return(free(line),0);
    map->obs=line[i];
   
    if(line[++i] == '\0')
        return(free(line),0);
    map->full =line[i];
    
    if(line[++i] != '\0')
    {

        return(free(line),0);
    }
    if(map->empty == map->obs || map->empty == map->full || map->obs ==map->full)
        return(free(line),0);
    
    return(free(line),1);

}
static int load_map(FILE *file,t_map *map)
{
    char *line=NULL;
    size_t n =0;
    ssize_t len =0;
    int row =0;

    map->grid = calloc(map->row +1,sizeof(char *));
    if(!map->grid)
        return(0);

    while((len =getline(&line,&n,file)) != -1)
    {
        if(line[len -1] == '\n')
             line[--len]='\0';
        if(row >= map->row)
        {

        return(free(line),0);
        }

        if(map->col ==0)
            map->col=len;
        else if((int)len!=map->col)
            return(free(line),0);
        
        map->grid[row] = malloc(map->col + 1);
        for(int  i=0;i < map->col;i++)
        {
            if(line[i] == map->empty || line[i] == map->obs)
                map->grid[row][i] = line[i];
            
            else
                return(free(line),0);
        }
        map->grid[row][map->col] = '\0';
        row++;
    }
    map->grid[map->row +1]=NULL;
   free(line);
     printf("bulksssssssi\n");
    return(row==map->row);
}

int read_map(char *argv,t_map *map)
{
    FILE *fd=fopen(argv,"r");
    if(!fd)
        return(0);
    if(!pars_line(fd,map) || !load_map(fd,map))
    {
        fclose(fd);
        return(0);
    }
    fclose(fd);
    printf("gndaaaaaaaaaak\n");
    return(1);
}
int read_from_stdin(t_map *map)
{
    if(!pars_line(stdin,map))
        return(0);
    return(load_map(stdin,map));
}
