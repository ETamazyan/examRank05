#include "bsq.h"
#include <sys/types.h>

static int ft_atoi(char *num)
{
    int sign = 1;
    int res = 0;

    if(*num == '-')
    {
        sign = -1;
        num++;
    }
    else if(*num == '+')
        num++;
    while(*num && (*num >= '0' && *num <= '9'))
    {
        res = 10 * res + (*num - '0');
        num++;
    }
    return (sign * res);
}
static int pars_map(FILE *file,t_map *map)
{
    char *line=NULL;
    size_t n =0;

    ssize_t len = getline(&line,&n,file);
    if(line[len - 1] == '\n')
        line[--len]='\0';

     map->row=ft_atoi(line);
     if(map->row <= 0) //=0 depqy ev anmijapes atoi ic heto
        return(free(line), 0);
    int i =0;
    while(line[i] && (line[i] >= '0' && line[i] <= '9'))
    i++;
    if(line[i] == '\0')
    return(free(line),0);
    map->empty=line[i];
    if(line[i + 1] == '\0')
    return(free(line),0);
    map->obs=line[++i];
    
    if(line[i + 1] == '\0')
    return(free(line),0);
    map->full=line[++i];
    
    if(line[i + 1] != '\0')
        return(free(line),0);

    if(map->empty == map->full || map->empty == map->obs || map->full == map->obs)
        return(free(line),0);
    return(free(line),1);
}


static int load_map(FILE *file,t_map *map)
{
    char *line = NULL;
    size_t n =0;
    ssize_t len;
    int row = 0;

    map->grid = calloc(map->row + 1,sizeof(char *));
    if(!map->grid)
        return(0);
    
    while((len = getline(&line,&n,file))!= -1)
    {
        if(line[len -1] == '\n')
            line[--len]='\0';
        
        if(row >= map->row) //= depqy nuynpes
            return(free(line),0);
        
        if(map->col == 0)
            map->col = len;
        else if((int)len != map->col)
            return(free(line),0);
        
        map->grid[row] = malloc(map->col + 1);//malloc

        for(int i =0; i < len;i++) //len
        {
            if(line[i] == map->empty || line[i] == map->obs)
                map->grid[row][i] = line[i];
            
            else
                return(free(line),0);
        }
        map->grid[row][map->col] = '\0';
        row++;
    }
    map->grid[row] = NULL;
    free(line); 
    return(row==map->row);//return value 
}
int read_from_argv(char* argv, t_map *map)
{
    FILE *fd = fopen(argv,"r");
    if(!fd)
    return(0);
    
    if(!pars_map(fd,map) || !load_map(fd,map))
    {
        fclose(fd);
        return(0);
    }
    fclose(fd);
    return(1);

}
int read_from_stdin(t_map *map)
{
    if(!pars_map(stdin,map))
    {
            fprintf(stdout, "Error: invalid map\n");
            return(0);
    }
    return(load_map(stdin,map));
}

// static int	ft_atoi(const char *str)
// {
// 	int	sign;
// 	int	res;

// 	sign = 1;
// 	res = 0;
	
// 	if (*str == '-')
// 	{
// 		sign *= -1;
// 		str++;
// 	}
// 	else if (*str == '+')
// 		str++;
// 	while (*str && (*str >= '0' && *str <= '9'))
// 	{
// 		res = res * 10 + (*str - '0');
// 		str++;
// 	}
// 	return (sign * res);
// }

// static int	pars_map(FILE *f, t_map *map)
// {
// 	char *line = NULL;
// 	size_t n = 0;

// 	ssize_t	len = getline(&line, &n, f);
// 	if (line[len - 1] == '\n')
// 		line[--len] = '\0';
	
//     while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
// {
//     line[len - 1] = '\0';
//     len--;
// }

// 	map->row = ft_atoi(line);
// 	if (map->row <= 0)
// 		return (free(line), 0);
// 	int	i = 0;
// 	while (line[i] && line[i] >= '0' && line[i] <= '9')
// 		i++;

// 	if (line[i] == '\0')
// 		return (free(line), 0);
// 	map->empty = line[i];
	
// 	if (line[i + 1] == '\0')
// 		return (free(line), 0);
// 	map->obs = line[++i];
	
// 	if (line[i + 1] == '\0')
// 		return (free(line), 0);
// 	map->full = line[++i];

// 	if (line[i + 1] != '\0')
//     return (free(line), 0);
//     printf("pars\n");

// 	if (map->row <= 0)
// 		return (free(line), 0);

// 	if (map->empty == map->obs ||
// 		map->empty == map->full ||
// 		map->obs == map->full)
// 		return (free(line), 0);
// 	return (free(line), 1);
// }

// static int	load_body(FILE *f, t_map *map)
// {
// 	char *line = NULL;
// 	size_t n = 0;
// 	ssize_t len;
// 	int row = 0;

// 	map->grid = calloc(map->row + 1, sizeof(char *));
// 	if (!map->grid)
// 		return 0;

// 	while ((len = getline(&line, &n, f)) != -1)
// 	{
// 		/* Skip the empty lines (not sure about this one by the way) */
// 		if ((len == 1 && line[0] == '\n'))
// 			continue;

// 		/* Remove trailing newline (if any) */
// 		if (line[len - 1] == '\n')
// 			line[--len] = '\0';

// 		if (row >= map->row)
// 		{
// 			free(line);
// 			return (0);
// 		}

// 		/* Determine column width from first row */
// 		if (map->col == 0)
// 			map->col = len;
// 		else if ((int)len != map->col)
// 		{
// 			free(line);
// 			return (0);
// 		}

// 		/* Validate characters and move to grid */
// 		map->grid[row] = malloc(map->col + 1);
// 		for (int i = 0; i < len; i++)
// 		{
// 			if (line[i] == map->empty || line[i] == map->obs)
// 			{
// 				map->grid[row][i] = line[i];
// 			}
// 			else
// 			{
// 				free(line);
// 				return (0);
// 			}
// 		}
// 		map->grid[row][map->col] = '\0';
// 		row++;
// 	}

// 	map->grid[row] = NULL;
// 	free(line);
// 	return (row == map->row);
// }

// /* -------------------- READ FROM FILE -------------------- */

// int	read_from_argv(const char *filename, t_map *map)
// {
// 	FILE *f = fopen(filename, "r");
// 	if (!f)
// 		return (0);

// 	if (!pars_map(f, map) || !load_body(f, map))
// 	{
//         printf("gndak\n");
// 		fclose(f);
// 		return (0);
// 	}

// 	fclose(f);
// 	return (1);
// }

// /* -------------------- READ FROM STDIN -------------------- */

// int	read_from_stdin(t_map *map)
// {
// 	if (!pars_map(stdin, map))
// 		return (0);

// 	return (load_body(stdin, map));
// }