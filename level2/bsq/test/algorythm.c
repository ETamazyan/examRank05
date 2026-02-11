#include "bsq.h"

int alg_bsq(t_map *map)
{
    int *dp = calloc(map->col, sizeof(int));
    if (!dp) return 0;

    int best = 0, best_i = 0, best_j = 0;

    for (int i = 0; i < map->row; i++)
    {
        int prev_diag = 0;              // dp[j-1] from previous row
        for (int j = 0; j < map->col; j++)
        {
            int up = dp[j];             // value from row i-1
            int val = 0;

            if (map->data[i][j] == map->empty)
            {
                if (i == 0 || j == 0)
                    val = 1;
                else
                {
                    int left = dp[j - 1];
                    int min = up < left ? up : left;
                    if (prev_diag < min) min = prev_diag;
                    val = 1 + min;
                }

                if (val > best)
                {
                    best = val;
                    best_i = i;
                    best_j = j;
                }
            }

            dp[j] = val;                // store current row result
            prev_diag = up;             // next cell's diagonal = old up
        }
    }
    // fill the best square with 'full'
    for (int i = best_i - best + 1; i <= best_i; i++)
        for (int j = best_j - best + 1; j <= best_j; j++)
            map->data[i][j] = map->full;

    free(dp);
    return 1;
}