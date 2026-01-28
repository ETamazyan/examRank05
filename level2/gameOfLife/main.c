#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void free_board(char **new_board,int height)
{
    for(int i =0;i<height;i++)
        free(new_board[i]);
    free(new_board);
}
void print_board(char **new_board,int width,int height)
{
    for (int i =0;i<height;i++)
    {
        for(int j =0;j < width;j++)
            putchar(new_board[i][j]);
        putchar('\n');
    }
}
char **create_board(int width,int height)
{
    char **new_board = calloc(height,sizeof(char *));//calloc
    if(!new_board)
        return(NULL);

    for (int i =0;i<height;i++)
    {
       new_board[i]=calloc(width,sizeof(char));//calloc
       for(int j =0;j<width;j++)
        new_board[i][j]=' ';
    }
    return(new_board);
}
char **start_drawing(char **board,int width,int height)
{
    char n;//arac iniiti
    int i =0;
    int j =0;
    int draw=0;

    while(read(STDIN_FILENO,&n,1) > 0) //>0
    {
        if(n == 'x')
            draw=!draw;
        else if(n == 'a' && j  > 0)//j>0 only
            j--;
        else if(n == 'w' && i > 0)//i>0 only
            i--;
        else if(n == 's' && i + 1 < height)
            i++;
        else if(n == 'd' && j + 1 < width)
            j++;
        if(draw)
            board[i][j]='0';
    }
    return(board);
}
int har_count(char **new_board,int i,int j,int width,int height)
{
    int count=0;
    for(int di=-1;di <=1;di++)
    {
        for(int dj =-1;dj <= 1;dj++)
        {
            if(di == 0 && dj ==0)
                continue;
            
            int ni = i + di;
            int nj = j + dj;
            if(ni >= 0 && ni < height && nj >= 0 && nj < width)//ni>=0 && nj>=0
            {
                if(new_board[ni][nj] == '0')//tvyal harevany voghj e te voch
                count++;
            }
        }
    }
    return(count);
}
char **new_gen(char **new_board,int width,int height)
{
    char **board = create_board(width,height);
    for (int i =0;i<height;i++)
    {
        for(int j =0;j < width;j++)
        {
            int count=har_count(new_board,i,j,width,height);
            printf("%d\n",count);
            if(new_board[i][j] == '0')
            {
                if(count == 2 || count == 3)
                    board[i][j] = '0';
            }
            else
            {
                if(count == 3)
                    board[i][j] = '0';
            }

        }
    }
    free_board(new_board,height);//maqrel skzbnakan poxancvatsy
    return(board);

}
int main(int argc, char **argv)
{
    if(argc==4)//argc=4
    {
        int width = atoi(argv[1]);
        int height = atoi(argv[2]);
        int iter = atoi(argv[3]);
        char **board = create_board(width,height);
        char **new_board=start_drawing(board,width,height);
        while(iter--)
            new_board=new_gen(new_board,width,height);
        print_board(new_board,width,height);//verjin argumentnery
        free_board(new_board,height);//verjin argumenty
    }
    return(0);
}