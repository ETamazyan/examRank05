#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void free_board(char **board,int row)
{
    for (int i = 0; i < row; i++)
        free(board[i]);
    free(board);
}
void print_board(char **board,int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
}
char **creat_board(int row,int col)
{
    char **new_board = calloc(row,sizeof(char *));

    for(int i =0;i<row;i++)
    {
        new_board[i]=calloc(col,sizeof(char));
        for(int j= 0;j<col;j++)
            new_board[i][j] = ' ';
    }
    return(new_board);
}
char **start_board(char **board,int row,int col)
{
    char n;
    int draw = 0;
    int i =0;
    int j =0;

    while(read(STDIN_FILENO,&n,1) > 0)
    {
        if(n == 'x')
            draw=!draw;
        else if(n == 'a' && j > 0)
            j--;
        else if(n == 'w' && i > 0)
            i--;
        else if(n=='s' && i+1<row)
            i++;
        else if(n=='d' && j+1 < col)
            j++;
        if(draw)
            board[i][j]='0';
    }
    return(board);
}
int n_count(char **new_board,int i,int j,int row,int col)
{
    int cont=0;
    for(int dr =-1;dr <=1;dr++)
    {
        for(int dc= -1;dc <= 1;dc++)
        {
            if(dr ==0 && dc==0)
                continue;
            int nr = i + dr;
            int nc = j + dc;

            if(nr >= 0 && nr < row  && nc >= 0 && nc < col)
                if(new_board[nr][nc] == '0')//[nr][nc] tvyal harevany
                    cont++;
        }
    }
    return(cont);
}
char **new_gen(char **new_board,int row,int col)
{
    char **board=creat_board(row,col);
    for (int i = 0; i < row; i++)
    {
        for(int j =0;j <col;j++)
        {
            int count=n_count(new_board,i,j,row,col);
            if(new_board[i][j] == '0')
            {
                if(count == 2 ||count==3)
                    board[i][j]='0';
            }
            else{
                if(count == 3)
                    board[i][j] = '0';
            }
        }
    }
    free_board(new_board,row);
    return(board);
    
}
int main(int argc,char **argv)
{
    if(argc==4)
    {
        int col=atoi(argv[1]);
        int row=atoi(argv[2]);
        int iter=atoi(argv[3]);
        char **board=creat_board(row,col);
        char **new_board=start_board(board,row,col);
        while(iter--)
            new_board=new_gen(new_board,row,col);
        print_board(new_board,row,col);
        free_board(new_board,row);
        return(0);
    }
}