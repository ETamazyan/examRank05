#include "bsq.h"

void free_map(t_map *map)
{
	if(!map || !map->data)
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

	if(argc == 1)
	{
		if(!r_stdin(&map))
		{
			fprintf(stderr, "Error: inv map\n");
			return (1);
		}
	}
	else if (argc == 2)
	{
		if(!r_argv(argv[1], &map))
		{
			fprintf(stderr, "Error: inv map\n");
			return (1);
		}
	}
	else
	{
		{
			fprintf(stderr, "Error: inv argc\n");
			return (1);
		}
	}
	if(!bsq(&map))
	{
		free_map(&map);
		fprintf(stderr, "Error: inv bsq\n");
		return (1);
	}
	print_map(&map);
	free_map(&map);
	return (0);
}