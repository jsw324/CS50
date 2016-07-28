/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    //int grid[d][d];
    int tileNum = (d*d) - 1;
    int c = 0;
    for (int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            board[i][j] = tileNum - c;
            if (d % 2 == 0 && (tileNum - c) == 2){
                board[i][j] = 1;
            }
            if (d % 2 == 0 && (tileNum - c) == 1){
                board[i][j] = 2;
            }
            c++;
        }
    }

}

/**
 * Prints the board in its current state.
 */
int z;
int y;

void draw(void)
{
    for(int a = 0; a < d; a++) {
        for(int b = 0 ; b < d; b++){
           // printf("%2d  ", board[a][b]);
            if(board[a][b] == 0){
                z = a;
                y = b;
                printf(" %c  ", 0);
            } else {
                printf("%2d  ", board[a][b]);
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int a = 0;
    int b = 0;
    int zplus = z + 1;
    int zminus = z - 1;
    int yplus = y + 1;
    int yminus = y - 1;
    //int max = (d * d) -1;
    // TODO
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            //if i + 1 , i - 1, and j+1/j-1 aren't higher than (n-1) execute
            if (board[i][j] == tile) {
               // printf("%i %i %i\n", zplus, y, board[zplus][y]);
                if(board[i][j] == board[zplus][y] || board[i][j] ==  board[zminus][y] || board[i][j] == board[z][yminus] || board[i][j] == board[z][yplus]){
                    // printf("%2d\n", board[i][j]);
                    int temp[1][1];
                    temp[a][b] = board[z][y];
                    board[z][y] = board[i][j];
                    board[i][j] = temp[a][b];
                    return true;
                } 
            }
        } 
    }
    return false;
}
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
  int max = d * d; 
  int num = 1;
  int winCounter = 0;
  int winningBoard[max][max];
  
  for(int i = 0; i < d; i++){
   for(int j = 0; j < d; j++){
      winningBoard[i][j] = num;
      num++;
     
     if(board[i][j] == winningBoard[i][j]){
       winCounter++;
     }
     if(winCounter == max - 1){
       return true;
     }
   }
  }
  return false;
}