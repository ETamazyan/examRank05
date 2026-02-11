#include "bsq.h"
#include <sys/types.h>

int ft_atoi(char *str)
{
	int res = 0;
	while(*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res);
}

static int	load_map_body(FILE *f, t_map *map)
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
			if (line[i] == map->empty || line[i] == map->obs)
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

int read_from_argv(char *argv, t_map *map)
{
	FILE *fd = fopen(argv, "r");
	if (!fd)
		return (0);
	if (!parse_map(fd, map) || !store_data(fd, map))
	{
		fclose(fd);
		return (0);
	}
	fclose(fd);
	return (1);
}

int read_from_stdin(t_map *map)
{
	if (!parse_map(stdin, map))
	{
		fprintf(stdout, "Error: invalid map\n");
		return (0);
	}
	return (store_map(stdin, map));
}