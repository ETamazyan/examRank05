#include "bsq.h"
#include <sys/types.h>

int bsq(t_map *map)
{
	int **dp = calloc(map->row, sizeof(int *));
	if(!dp)
		return (0);
	
	for (int i = 0; i < map->row; i++)
		dp[i] = calloc(map->col, sizeof(int));
	int max_size = 0;
	int max_row = 0;
	int max_col = 0;

	for(int row = 0; row < map->row; row++)
	{
		for(int col = 0; col < map->col; col++)
		{
			if(map->data[row][col] == map->empty)
			{
				if(col == 0 || row == 0)
					dp[row][col] = 1;
				else
				{
					int up = dp[row - 1][col];
					int left = dp[row][col -1];
					int diag = dp[row-1][col -1];

					int min = up < left ? up : left;
					if(min > diag)
						min = diag;
					dp[row][col] = 1 + min;
				}
				if(dp[row][col] > max_size)
				{
					max_size = dp[row][col];
					max_row = row;
					max_col = col;
				}
			}
		}
	}
	for(int row = max_row - max_size + 1; row <= max_row; row++)
		for(int col = max_col - max_size + 1; col <= max_col; col++)
			map->data[row][col] = map->full;
	for (int row = 0; row < map->row; row++)
		free(dp[row]);
	free(dp);
	return 1;

}

int ft_atoi(char *str)
{
    int res = 0;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*str++ - '0');
    return res;
}

static int store_data(FILE *fd, t_map *map)
{
		char	*line = NULL;
	size_t	n = 0;
	ssize_t	len;
	int		r = 0;
	
	map->data = calloc(map->row + 1, sizeof(char *));

	if (!map->data)
		return (0);
	while ((len = getline(&line, &n, fd)) != -1)
	{
		if (line[len - 1] == '\n')
			line[--len] = '\0';
		if (r >= map->row)
			return (free(line), free_map(map), 0);
		if (map->col == 0)
			map->col = len;
		else if (map->col != (int)len)
			return (free(line), free_map(map), 0);

		map->data[r] = malloc(map->col + 1);
		if (!map->data[r])
			return (free(line), free_map(map), 0);

		for (int i = 0; i < map->col; i++)
			if (line[i] == map->empty || line[i] == map->obst)
				map->data[r][i] = line[i];
			else
				return (free(line), free_map(map), 0);

		map->data[r++][map->col] = '\0';
	}
	free(line);
	return (r == map->row);
}

static int parse_data(FILE *fd, t_map *map)
{
	char *line = NULL;
    size_t n = 0;
    ssize_t len = getline(&line, &n, fd);
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
    map->obst   = p[1];
    map->full  = p[2];
    if (map->empty == map->obst || map->empty == map->full || map->obst == map->full)
        return free(line), 0;
    return free(line), 1;
}

int read_from_argv(char* argv, t_map *map)
{
    FILE *fd = fopen(argv,"r");
    if(!fd)
    return(0);
    
    if(!parse_data(fd,map) || !store_data(fd,map))
    {
        fclose(fd);
        return(0);
    }
    fclose(fd);
    return(1);
}

int read_from_stdin(t_map *map)
{
    if(!parse_data(stdin,map))
    {
            fprintf(stdout, "Error: invalid map\n");
            return(0);
    }
    return(store_data(stdin,map));
}





/*
// //for test
static int	store_data(FILE *f, t_map *map)
{
	char	*line = NULL;
	size_t	n = 0;
	ssize_t	len;
	int		r = 0;

	map->data = calloc(map->row + 1, sizeof(char *));
	if (!map->data)
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
		map->data[r] = malloc(map->col + 1);
		if (!map->data[r])
			return (free(line), free_map(map), 0);
		for (int i = 0; i < map->col; i++)
			if (line[i] == map->empty || line[i] == map->obst)
				map->data[r][i] = line[i];
			else
				return (free(line), free_map(map), 0);

		map->data[r++][map->col] = '\0';
	}
	free(line);
	return (r == map->row);
}

static int parse_map(FILE *file, t_map *map)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t len = getline(&line, &n, file);
	if (len <= 0)
		return (0);
	if (line[len - 1] == '\n')
		line[--len] = '\0';
	char *p = line;
	map->row = ft_atoi(p);
	if (map->row <= 0)
		return (free(line), 0);
	while(*p >= '0' && *p <= '9')
		p++;
	if (!p[0] || !p[1] || !p[2] || p[3] != '\0')
		return (free(line), 0);
	map->empty = p[0];
	map->obst = p[1];
	map->full = p[2];
	if (map->empty == map->obst || map->empty == map->full || map->obst == map->full)
		return (free(line), 0); // fail
	return (free(line), 1); // success
}
*/


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
