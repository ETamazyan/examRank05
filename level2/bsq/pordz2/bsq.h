#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    int row;
    int col;
    char empty;
    char full;
    char obs;
    char **grid;
}t_map;

int read_map(char *argv,t_map *map);
int read_from_stdin(t_map *map);
int alg_bsq(t_map *map);