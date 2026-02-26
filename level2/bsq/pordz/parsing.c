#include "bsq.h"

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
	int res;
	while(*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res);
}

int parse_data(FILE *fd, t_map *map)
{
	char *line = NULL; //not init
    size_t n = 0; // not init
    ssize_t len = getline(&line, &n, fd);
    if (len <= 0) // changed to -1
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
		printf("bulki\n");
    return free(line), 1;
	// size_t n = 0;
	// // ssize_t len =0;
	// char *line = NULL;
	// ssize_t len = getline(&line, &n, fd);
	// if (len <= 0)
	// 	return 0;
	// if(line[len - 1] == '\n')
	// 	line[--len] = '\0';
	// char *p = line;
	// map->row = ft_atoi(p);
	// if (map->row <= 0)
	// 	return (free(line), 0);
	// while(*p >= '0' && *p <= '9')
	// 	p++;
	// if(!p[0] || !p[1] || !p[2] || p[3] != '\0')
	// 	return (free(line), 0);
	// map->empty = p[0];
	// map->obst = p[1];
	// map->full = p[2];
	// if(map->empty == map->full || map->empty == map->obst || map->obst == map->full)
	// 	return (free(line), 0);
	// return (free(line), 1);
}

int store_data(FILE *fd, t_map *map)
{
		char	*line = NULL;
	size_t	n = 0;
	ssize_t	len;
	int		r = 0;
	// printf("blablal\n");
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
	// size_t n = 0;
	// ssize_t len = 0;
	// char *line = NULL;
	// int row = 0;

	// printf("sddsdasd\n");
	// map->data = calloc(map->row + 1, sizeof(char *));
	// if(!map->data)
	// 	return (0);
	// while((len = getline(&line, &n, fd)) != -1)
	// {
	// 	printf("eeeeeee\n");
	// 	if(line[len - 1] == '\n')
	// 		line[--len] = '\0';
	// 	if(row >= map->row)
	// 		return (free(line), free_map(map), 0);
	// 	if(map->col == 0)
	// 		map->col = len;
	// 	else if (map->col != len)
	// 		return (free(line), free_map(map), 0);
	// 	// map->data[row] = calloc(map->col + 1, sizeof(char));
	// 	map->data[row] = malloc(map->col + 1);
	// 	if(!map->data[row])
	// 		return (free(line), free_map(map), 0);
	// 	for(int i = 0; i < map->col; i++)
	// 	{
	// 		if(line[i] == map->empty || line[i] == map->obst)
	// 			map->data[row][i] = line[i];
	// 		else
	// 			return (free(line), free_map(map), 0);
	// 	}
	// 	map->data[row++][map->col] = '\0';
	// }
	// free(line);
	// return (row == map->row);

}

int r_stdin(t_map *map)
{
	if(!parse_data(stdin, map))
	{
		return (0);
	}
	return (store_data(stdin, map));
}

int r_argv(char *argv, t_map *map)
{
	FILE *fd = fopen(argv, "r");
	if (!fd)
		return (0);
	if (!parse_data(fd, map) || !store_data(fd, map))
	{
		fclose(fd);
		return (0);
	}
	fclose(fd);
	return (1);
}
