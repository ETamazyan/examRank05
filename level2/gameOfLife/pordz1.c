#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void print_board(char **new_board,int width,int high)
{
    for (int i = 0; i < high; i++)
    {
        for (int j = 0; j < width; j++)
        {
            putchar(new_board[i][j]);
        }
        putchar('\n');       
    }
}
void free_board(char **new_board,int high)
{
    for(int i =0;i<high;i++)
        free(new_board[i]);
    free(new_board);
}
char **creat_board(int width,int high)
{
    char **new_board = calloc(high,sizeof(char *));
    if(!new_board)//stugum
        return(NULL);
    for (int i = 0; i < high; i++)
    {
        new_board[i]=calloc(width,sizeof(char));//width
        for (int j = 0; j < width; j++)
        {
            new_board[i][j]=' ';
        }
    }
    return(new_board);
}
char **search_draw(char **board,int width,int high)
{
    int draw =0;
    char n;
    int i =0;
    int j =0;
    
    while(read(STDIN_FILENO,&n,1) > 0)//>0
    {
        // for (int i = 0; i < high; i++)
        // {                                    SXALLLLLLL
        //     for (int j = 0; j < width; j++)
        //     {
                if(n == 'x')
                    draw=!draw;
                else if(n == 'w' && i > 0)
                    i--;
                else if(n == 's' && i + 1 < high) //i +1
                    i++;
                else if(n== 'd' && j +1 < width) //j+1
                    j++;
                 else if(n == 'a' && j > 0)
                    j--;

                if(draw)
                    board[i][j] = '0';
            
    }
    return(board);
}
int count_n(char **board,int i,int j,int width, int higth)
{
    int count =0;
    for(int ip =-1;ip<=1;ip++)//<=1
    {
        for(int jp = -1;jp <=1;jp++)//<=1
        {
            if(ip == 0 && jp==0)
                continue;
            int ni = i + ip;
            int nj = j + jp;
            if(ni >= 0 && ni < higth && nj >=0 && nj < width )//higth,width
                if(board[ni][nj] == '0')
                    count++;
        }
    }
    return(count);
}
char **new_gen(char **new_board,int width,int high)
{
    char **board = creat_board(width,high);
    int count = 0;
    
    for (int i = 0; i < high; i++)
        {
            for (int j = 0; j < width; j++)
            {
                count=count_n(new_board,i,j,width,high);
                if(new_board[i][j] == '0')
                {
                    if (count == 2 || count == 3)
                        board[i][j]='0';
                }
                else{
                    if(count == 3)
                        board[i][j] ='0';
                }
            }
        }
        free_board(new_board,high);
        return(board);
    }

int main(int argc,char **argv)
{
  //  (void)argv;
    if(argc == 4)
    {
        int width = atoi(argv[1]);
        int high = atoi(argv[2]);
        int iter=atoi(argv[3]);
        char **board=creat_board(width,high);
        char **new_board=search_draw(board,width,high);
        while(iter--)
            new_board=new_gen(new_board,width,high);
        print_board(new_board,width,high);
        free_board(new_board,high);
    }
    printf("argc=%d\n",argc);
    return(0);
}
