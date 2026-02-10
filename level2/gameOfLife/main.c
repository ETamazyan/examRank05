#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print(char **map, int width,  int height)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
			putchar(map[i][j]);
		putchar('\n');
	}
}

void free_map(char **map, int height)
{
	for(int i = 0; i < height; i++)
		free(map[i]);
	free(map);
}

char **create_map(int width, int height)
{
	char **map = calloc(height, sizeof(char *));
	if (!map)
		return (NULL);
	for(int i = 0; i < height; i++)
	{
		map[i] = calloc(width, sizeof(char));
		for(int j = 0; j < width; j++)
			map[i][j] = ' ';
	}
	return (map);
}


char **paint_map(char **map, int width, int height)
{
	char n;
	int i = 0;
	int j = 0;
	int draw = 0;

	while(read(STDIN_FILENO, &n, 1) > 0)
	{
		if(n == 'x')
			draw = !draw;
		else if (n == 'w' && i > 0)
			i--;
		else if (n == 's' && i + 1 < height)
			i++;
		else if (n == 'a' && j > 0)
			j--;
		else if (n == 'd' && i + 1 < width)
			j++;
		if(draw)
			map[i][j] = '0';
	}
	return (map);
}

int count_neighbors(char **map, int i, int j, int width, int height)
{
	int count = 0;

	for(int di= -1; di <= 1; di++)
	{
		for(int dj = -1; dj <= 1; dj++)
		{
			if (di == 0 && dj == 0)
				continue ;
			int ni = di + i;
			int nj = dj + j;
			if (ni >= 0 && ni < height && nj >= 0 && nj < width)
			{
				if (map[ni][nj] == '0')
					count++;
			}
		}
	}
	return (count);
}

char **iter_map(char **old_map, int width, int height)
{
	char **map = create_map(width, height);
	for (int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			int count = count_neighbors(old_map, i, j, width, height);
			if (old_map[i][j] == '0')
			{
				if (count == 2 || count == 3)
					map[i][j] = '0';
			}
			else
			{
				if (count == 3)
					map[i][j] = '0';
			}
		}
	}
	free_map(old_map, height);
	return (map);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		int width = atoi(argv[1]);
		int height = atoi(argv[2]);
		int iterator = atoi(argv[3]);
		char **map = create_map(width, height);
		char **painted_map = paint_map(map, width, height);
		while(iterator--)
			painted_map = iter_map(painted_map, width, height);
		print(painted_map, width, height);
		free_map(painted_map, height);
	}
	return (0);
}

























// version begin

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

// void free_board(char **board,int height)
// {
//     for(int i = 0; i < height; i++)
//         free(board[i]);
//     free(board);
// }
// void print_board(char **new_board,int width,int height)
// {
//     for (int i = 0; i < height; i++)
//     {
//         for(int j =0; j < width; j++)
//             putchar(new_board[i][j]);
//         putchar('\n');
//     }
// }
// char **create_board(int width,int height)
// {
//     char **new_board = calloc(height,sizeof(char *));
//     if(!new_board)
//         return(NULL);

//     for (int i = 0; i < height; i++)
//     {
//        new_board[i]=calloc(width,sizeof(char));
//        for(int j = 0; j < width; j++)
//         new_board[i][j]=' ';
//     }
//     return(new_board);
// }
// char **start_drawing(char **board,int width,int height)
// {
//     char n;//aranc iniiti
//     int i = 0;
//     int j = 0;
//     int draw = 0;

//     while(read(STDIN_FILENO,&n,1) > 0) //>0
//     {
//         if(n == 'x')
//             draw=!draw;
//         else if(n == 'a' && j  > 0)//j>0 only
//             j--;
//         else if(n == 'w' && i > 0)//i>0 only
//             i--;
//         else if(n == 's' && i + 1 < height)
//             i++;
//         else if(n == 'd' && j + 1 < width)
//             j++;
//         if(draw)
//             board[i][j]='0';
//     }
//     return(board);
// }
// int har_count(char **map,int i,int j,int width,int height)
// {
//     int count=0;
//     for(int di=-1; di <= 1; di++)
//     {
//         for(int dj =-1; dj <= 1; dj++)
//         {
//             if(di == 0 && dj == 0)
//                 continue ;
//             int ni = i + di;
//             int nj = j + dj;
//             if(ni >= 0 && ni < height && nj >= 0 && nj < width)//ni>=0 && nj>=0
//             {
//                 if(map[ni][nj] == '0')//tvyal harevany voghj e te voch
//                 count++;
//             }
//         }
//     }
//     return(count);
// }
// char **iter_map(char **old_map,int width,int height)
// {
//     char **map = create_board(width,height);
//     printf("aaa\n");
//     print_board(old_map, width, height);
//     printf("aaa\n");
//     for (int i =0; i < height; i++)
//     {
//         for(int j =0;j < width;j++)
//         {
//             int count = har_count(old_map,i,j,width,height);
// 			printf("count = %d\n", count);
//             if(old_map[i][j] == '0')
//             {
//                 if(count == 2 || count == 3)
//                     map[i][j] = '0';
//             }
//             else
//             {
//                 if(count == 3)
//                     map[i][j] = '0';
//             }
//         }
//     }
//     free_board(old_map,height);//maqrel skzbnakan poxancvatsy
//     return(map);

// }
// int main(int argc, char **argv)
// {
//     if(argc==4)//argc=4
//     {
//         int width = atoi(argv[1]);
//         int height = atoi(argv[2]);
//         int iter = atoi(argv[3]);
//         char **board = create_board(width,height);
//         print_board(board,width,height);//verjin argumentnery
//         putchar('\n');
//         char **new_board=start_drawing(board,width,height);
//         while(iter--)
//             new_board=iter_map(new_board,width,height);
//         print_board(new_board,width,height);//verjin argumentnery
//         free_board(new_board,height);//verjin argumenty
//     }
//     return(0);
// }