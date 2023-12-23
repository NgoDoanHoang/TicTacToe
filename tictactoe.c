#include <stdio.h>

void human();
void AI();
void display(char board[]);
int move(char board[], int position, char symbol);
int check_win(char board[], char symbol);
int check_draw(char board[]);

int main()
{
    printf("Welcome to my XOX game! \n");
    printf("1. 2 players\n");
    printf("2. versus AI \n");
    printf("3. exit now!\n");
    printf("Your choice is: ");
    int choice; 
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        /* code */
        human();
        break;

    case 2: 
        AI();       //mini max
        break;

    default:
        break;
    }

    return 0;
}


void human()
{
    int turn = 1;
    char symbol;
    
    printf("\nP1. X\n");
    printf("P2. O\n");

    char board[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  //  display(board);


    while (check_win(board, 'X') == 0 && check_win(board, 'O') == 0)
    {   
        display(board);
    
        if (turn % 2 != 0)
        {
            turn = 1;
            symbol = 'X';
        }
        else
        {
            turn = 2;
            symbol = 'O';
        }


        printf("P%d enter position 1-9: ", turn);
        int pos = 0;
        scanf("%d", &pos);

        if (move(board, pos, symbol) == 0)
        {
            continue;
        }

        if(check_win(board, symbol) == 1)
        {
            printf("Congrat P%d. U win!", turn);
            display(board);
            break;
        }

        if (check_draw(board) == 1)
        {
            break;
        }        


        turn++;
    }


}

void display(char board[])
{
    printf(" %c | %c | %c \n", board[1], board[2], board[3]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[4], board[5], board[6]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[7], board[8], board[9]);
}

int move(char board[], int position, char symbol)
{
    if(board[position] == ' ')
    {
        board[position] = symbol;
        return 1;
    }
    else
    {
        printf("already taken. try again\n");
        return 0;
    }
}

int check_win(char board[], char symbol) 
{
    if ((board[1] == symbol && board[2] == symbol && board[3] == symbol) ||
        (board[4] == symbol && board[5] == symbol && board[6] == symbol) ||
        (board[7] == symbol && board[8] == symbol && board[9] == symbol) ||
        (board[1] == symbol && board[4] == symbol && board[7] == symbol) ||
        (board[2] == symbol && board[5] == symbol && board[8] == symbol) ||
        (board[3] == symbol && board[6] == symbol && board[9] == symbol) ||
        (board[1] == symbol && board[5] == symbol && board[9] == symbol) ||
        (board[3] == symbol && board[5] == symbol && board[7] == symbol)) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int check_draw(char board[])
{
    if (board[1] != ' ' && board[2] != ' ' && board[3] != ' ' &&
        board[4] != ' ' && board[5] != ' ' && board[6] != ' ' &&
        board[7] != ' ' && board[8] != ' ' && board[9] != ' ') 
    {
        printf("The game is a draw.\n");
        return 1;
    } return 0;
}

void AI()
{

}