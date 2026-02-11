#ifndef BSQ_H
#define BSQ_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct s_map
{
    int row;
    int col;
    char empty;
    char full;
    char obs;
    char **grid;

} t_map;

int read_from_stdin(t_map *map);
int read_from_argv( char* argv, t_map *map);//const char*
int alg_bsq(t_map *map);

void free_map(t_map *map);
void print_map(t_map *map);
#endif


// int myAtoi(char *s)
// {
//     int i = 0;
//     int sign = 1;
//     long result = 0;

//     while (s[i] == ' ')
//         i++;
//     if (s[i] == '+' || s[i] == '-') {
//         if (s[i] == '-')
//             sign = -1;
//         i++;
//     }
//     while (isdigit(s[i])) 
//     {
//         result = result * 10 + (s[i] - '0');
//         if (sign == 1 && result > INT_MAX)
//             return INT_MAX;
//         if (sign == -1 && -result < INT_MIN)
//             return INT_MIN;
//         i++;
//     }
//     return (int)(sign * result);
// }









