#include "bsq.h"

void print_map(t_map *map)
{
    for(int i = 0;i < map->row; i++)
        fprintf(stdout,"%s\n",map->grid[i]);
}

void free_map(t_map *map)
{
    if(!map || !map->grid) //bbb
        return ;
    for(int i =0; i<map->row; i++)
        free(map->grid[i]);
    free(map->grid);
}

int main(int argc, char **argv)
{
    t_map map;

    map.row=0;
    map.col=0;
    map.grid=NULL;

    if (argc == 1)
    {
        if (!read_from_stdin(&map))
        {
            fprintf(stdout, "Error: invalid map\n");
            return (1);
        }
    }
    else if (argc == 2)
    {
        if (!read_from_argv(argv[1], &map))
        {
            fprintf(stdout, "Error: invalid map\n");
            return (1);
        }
    }
    else
    {
        fprintf(stdout, "Error: invalid number of arguments\n");
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

// int main(void)
// {
//     char *argv_stdin[] = {"bsq", NULL};
//     char *argv_invalid_argc[] = {"bsq", "file1", "file2", NULL};
//     char *argv_invalid_map[] = {"bsq", "invalid_map.txt", NULL};
//     char *argv_valid_map[] = {"bsq", "example_file", NULL};

//     fprintf(stdout, "\n--- TEST 1: argc == 1 (stdin) ---\n");
//     bsq_main(1, argv_stdin);

//     fprintf(stdout, "\n--- TEST 2: argc != 2 (error) ---\n");
//     bsq_main(3, argv_invalid_argc);

//     fprintf(stdout, "\n--- TEST 3: argc == 2, invalid map ---\n");
//     bsq_main(2, argv_invalid_map);

//     fprintf(stdout, "\n--- TEST 4: argc == 2, valid map ---\n");
//     bsq_main(2, argv_valid_map);

//     return (0);
// }


// ******** ARCHIVE ********

// don't use this.
// int bsq_main(int argc,char **argv)
// {
//     t_map map;

//     map.row=0;
//     map.col=0;
//     map.grid=NULL;

//     if(argc==1)
//     {
//         if(!read_from_stdin(&map))
//         {
//             free_map(&map);
//             fprintf(stdout, "Error: invalid map\n");
//             return(1);
//         }
//         if(!alg_bsq(&map))
//         {
//             free_map(&map);
//             fprintf(stdout, "Error: malloc error\n");
//             return(1);
//         }
//         print_map(&map);
//         free_map(&map);
//         return(0);
//     }
//     if(argc != 2)
//     {
//         free_map(&map);
//         fprintf(stdout, "Error: invalid number of arguments\n");
//             return(1);
//     }

//     if(!read_from_argv(argv[1],&map))
//     {
//         free_map(&map);
//         fprintf(stdout, "Error: invalid map\n");
//             return(1);
//     }
//     if(!alg_bsq(&map))
//     {
//         free_map(&map);
//             fprintf(stdout, "Error: malloc error\n");
//             return(1);
//     }
//      print_map(&map);
//         free_map(&map);
//     return(0);
// }

