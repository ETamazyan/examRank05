#include "bsq.h"

static int ft_atoi(char *str)
{
    int res=0;
    int sign=1;

    if(*str == '-')
    {
        sign =-1;
        str++;
    }
    else if(*str=='+')
        str++;
    while(*str && (*str >='0' && *str <= '9'))
    {
        res=res*10+(*str - '0');
        str++;
    }
    return(sign*res);
}
static int pars(FILE *file,t_map *map)
{
    char *line=NULL;
    size_t n=0;
    
    ssize_t len = getline(&line,&n,file);
    printf("bulik\n");

    if(line[len-1] == '\n')
        line[--len] = '\0';
        
    int tiv = ft_atoi(line);
    if(tiv <= 0)
            return(free(line),0);
    int i =0;
    map->row=tiv;
    while(line[i] && (line[i] >='0' && line[i] <= '9'))
        i++;
    
    if(line[i] == '\0')
        return(free(line),0);
    map->empty=line[i];

    if(line[++i] == '\0')
        return(free(line),0);
    
    map->obs=line[i];
    if(line[++i] == '\0')
        return(free(line),0);
    map->full=line[i];
    if(line[++i] != '\0')
        return(free(line),0);
    
    if(map->empty==map->obs || map->empty==map->full || map->full==map->obs)
        return(free(line),0);
    
    return(free(line),1);

}

static int load_map(FILE *file,t_map *map)
{
    char *line=NULL;
    size_t n=0;
    ssize_t len=0;
    int row=0;

    map->grid=calloc(map->row+1,sizeof(char *));
    if(!map->grid)
        return(0);
    
    while((len=getline(&line,&n,file)) !=-1)
    {
        if(line[len-1] == '\n')
        line[--len] = '\0';

        if(row>=map->row)
            return(free(line),0);
        
        if(map->col == 0)
            map->col = len;
        else if((int)len != map->col)
             return(free(line),0);
        
        map->grid[row]=malloc(map->col + 1);
        for(int i =0;i<map->col;i++)
        {
            if(line[i] == map->empty || line[i] == map->obs)
                map->grid[row][i]=line[i];
            
            else
                return(free(line),0);
        }

        map->grid[row][map->col]='\0';
        row++;
    }
    map->grid[row]=NULL;
    free(line);
    return(row==map->row);
}
int read_map(char *argv,t_map *map)
{
    FILE *fd=fopen(argv,"r");
        if(!fd)
            return(0);
    if(!pars(fd,map) || !load_map(fd,map))
    {
        fclose(fd);
        return(0);
    }
      fclose(fd);
        return(1);
}
int read_from_stdin(t_map *map)
{
    if(!pars(stdin,map))
        return(0);
    return(load_map(stdin,map));
}

