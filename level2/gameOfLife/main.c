#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void clear_map(char **map, int h)
{
	for(int i = 0; i < h; i++)
		free(map[i]);
	free(map);
}

void print_map(char**map, int w, int h)
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
			putchar(map[i][j]);
		putchar('\n');
	}
}

char **create_map(int width, int height)
{
	char **map = calloc(height, sizeof(char*));
	if(!map)
		return NULL;
	for(int i = 0; i < height; i++)
	{
		map[i] = calloc(width, sizeof(char));
		for(int j = 0; j < width; j++)
			map[i][j] = ' ';
	}
	return (map);
}

char **draw_map(char **map, int width, int height)
{
	char n;
	int i = 0;
	int j = 0;
	int draw = 0;

	while(read(0, &n, 1) > 0)
	{
		if (n == 'x')
			draw = !draw;
		else if(n == 'w' && i > 0)
			i--;
		else if(n == 's' && i + 1 < height)
			i++;
		else if(n == 'a' && j > 0)
			j--;
		else if(n == 'd' && j + 1 < width)
			j++;
		if(draw)
			map[i][j] = 'O';
	}
	return (map);
}

int countN(char **map, int i, int j,int width, int height)
{
	int count = 0;
	for(int di = -1; di <= 1; di++)
	{
		for(int dj = -1; dj <= 1; dj++)
		{
			if(di == 0 && dj == 0)
				continue ;
			int ni = di + i;
			int nj = dj + j;
			if(ni >= 0 && nj >= 0 && ni < height && nj < width)
			{
				if(map[ni][nj] == 'O')
					count++;
			}
		}
	}
	return (count);
}

char **iter_map(char **old_map, int width, int height)
{
	char **new = create_map(width, height);
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			int count = countN(old_map, i, j, width, height);
			if(old_map[i][j] == 'O')
			{
				if (count == 2 || count == 3)
					new[i][j] = 'O';
			}
			else
			{
				if (count == 3)
					new[i][j] = 'O';
			}
		}
	}
	clear_map(old_map, height);
	return (new);
}

int main(int argc, char **argv)
{
	if(argc == 4)
	{
		int width = atoi(argv[1]);
		int height = atoi(argv[2]);
		int itor = atoi(argv[3]);
		char **map  = create_map(width, height);
		char **drawn_map = draw_map(map, width, height);
		while(itor--)
			drawn_map = iter_map(drawn_map, width, height);
		print_map(drawn_map, width, height);
		free(drawn_map);
	}
	return (0);
}
