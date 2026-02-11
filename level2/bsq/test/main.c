 #include "bsq.h"

void free_map(t_map *map)
{
	if (!map || !map->data)
		return ;
	for(int i = 0; i < map->row; i++)
		free(map->data[i]);
	free(map->data);
}

void print_map(t_map *map)
{
	for(int i = 0; i < map->row; i++)
		fprintf(stdout, "%s\n", map->data[i]);
}

int main(int argc, char **argv)
{
	t_map map;

	map.row = 0;
	map.col = 0;
	map.data = NULL;

	if (argc == 1)
	{
		if (!read_from_stdin(&map))
		{
			fprintf(stdout, "Error: invalid map\n");
			return (1);
		}
	}
	else if(argc == 2)
	{
		if (!read_from_argv(argv[1], &map))
		{
			fprintf(stdout, "Error: invalid map\n");
			return (1);
		}
	}
	else
	{
		fprintf(stdout, "Error: invalid amount of arguments\n");
		return (1);
	}
	if (!alg_bsq(&map))
	{
		free_map(&map);
		fprintf(stdout, "Error: malloc error\n");
		return (1);
	}
	print_map(&map);
	free_map(&map);
	return (0);
}