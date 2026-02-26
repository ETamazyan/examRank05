#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct s_map
{
	int row;
	int col;
	char empty;
	char obst;
	char full;
	char **data;
} t_map;

void print_map(t_map *map);
void free_map(t_map *map);

int r_stdin(t_map *map);
int r_argv(char *argv, t_map *map);
int bsq(t_map *map);

#endif