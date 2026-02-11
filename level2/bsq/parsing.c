#include "bsq.h"
#include <sys/types.h>


int ft_atoi(char *str)
{
    int res = 0;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*str++ - '0');
    return res;
}

static int  fail(char *line, t_map *map)
{
    free(line);
    free_map(map);
    return (0);
}

static int	load_map(FILE *f, t_map *map)
{
	char	*line = NULL;
	size_t	n = 0;
	ssize_t	len;
	int		r = 0;

	map->grid = calloc(map->row + 1, sizeof(char *));
	if (!map->grid)
		return (0);

	while ((len = getline(&line, &n, f)) != -1)
	{
		if (line[len - 1] == '\n')
			line[--len] = '\0';
		if (r >= map->row)
			return (free(line), free_map(map), 0);
		if (map->col == 0)
			map->col = len;
		else if (map->col != (int)len)
			return (free(line), free_map(map), 0);

		map->grid[r] = malloc(map->col + 1);
		if (!map->grid[r])
			return (free(line), free_map(map), 0);

		for (int i = 0; i < map->col; i++)
			if (line[i] == map->empty || line[i] == map->obs)
				map->grid[r][i] = line[i];
			else
				return (free(line), free_map(map), 0);

		map->grid[r++][map->col] = '\0';
	}
	free(line);
	return (r == map->row);
}

static int pars_map(FILE *file, t_map *map)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t len = getline(&line, &n, file);
    if (len <= 0)
        return 0;
    if (line[len - 1] == '\n')
        line[--len] = '\0';
    char *p = line;
    map->row = ft_atoi(p);
    if (map->row <= 0)
        return free(line), 0;
    while (*p >= '0' && *p <= '9')
        p++;
    if (!p[0] || !p[1] || !p[2] || p[3] != '\0')
        return free(line), 0;
    map->empty = p[0];
    map->obs   = p[1];
    map->full  = p[2];
    if (map->empty == map->obs || map->empty == map->full || map->obs == map->full)
        return free(line), 0;
    return free(line), 1;
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


// ******** ARCHIVE ********
/*

// // load map has gone

// static int ft_atoi(char *num)
// {
//     int sign = 1;
//     int res = 0;

//     if(*num == '-')
//     {
//         sign = -1;
//         num++;
//     }
//     else if(*num == '+')
//         num++;
//     while(*num && (*num >= '0' && *num <= '9'))
//     {
//         res = 10 * res + (*num - '0');
//         num++;
//     }
//     return (sign * res);
// }

// static int pars_map(FILE *file, t_map *map)
// {
//     char *line= NULL;
//     size_t n = 0;

//     ssize_t len = getline(&line, &n, file);
    
//     if(line[len - 1] == '\n')
//         line[--len]='\0';
//     map->row=ft_atoi(line);
//     if(map->row <= 0) //=0 depqy ev anmijapes atoi ic heto
//         return(free(line), 0);
//     int i = 0;
//     while (line[i] && (line[i] >= '0' && line[i] <= '9'))
//         i++;
//     if (line[i] == '\0')
//         return(free(line), 0);
//     map->empty=line[i];
//     if (line[i + 1] == '\0')
//         return(free(line),0);
//     map->obs=line[++i];
//     if(line[i + 1] == '\0')
//         return(free(line),0);
//     map->full=line[++i];
//     if(line[i + 1] != '\0')
//         return(free(line),0);
//     if(map->empty == map->full || map->empty == map->obs || map->full == map->obs)
//         return(free(line),0);
//     return(free(line),1);
// }



*/