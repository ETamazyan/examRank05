#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_map
{
	int col;
	int row;
	char empty;
	char obst;
	char full;
	char **data;
}t_map;

int read_from_stdin(t_map *map);
int read_from_argv(char *argv, t_map *map);
int alg_bsq(t_map *map);

void print_map(t_map *map);
void free_map(t_map *map);

#endif