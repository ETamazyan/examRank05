#pragma once
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    int row;
    int col;
    char empty;
    char obs;
    char full;
    char **grid;
}t_map;

int alg_bsq(t_map *map);
void free_board(t_map *map);
void print_grid(t_map *map);
int read_map(char *argv,t_map *map);
int read_from_stdin(t_map *map);
