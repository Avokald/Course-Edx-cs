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
char blank = '_';
static int d2R;
static int d2C;

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
    d2C = d2R = d-1;
    
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
    //int l = d;
    for (int i = 0, m = (d*d)-1; i < d; i++){
        for (int j =0; j < d; j++, m--){
            board[i][j] = m;
        }
    }
    board[d-1][d-1] = 0;
    if (d%2 == 0){
                int u = board[d-1][d-2];
                board[d-1][d-2] = board[d-1][d-3];
                board[d-1][d-3] = u;
            }
    // TODO
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            
            if ( board[i][j] == 0 ){
                printf("%2c\t", blank);
              }
            else {
                printf("%2d\t", board[i][j]);
            }
        }
        printf("\n");
    }
    // TODO
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{   
    int k = -1, l = -1;
    for ( int i = d2R-1; i <= d2R  + 1; i++){
        for (int j = d2C-1; j <= d2C + 1; j++){
            if ( ( board[i][j] == tile) && ( (i == d2R) || ( j == d2C ) ) && ( ( i < d) && ( j < d )) ){
                k = i;
                l = j;
            }
        }
    }
    if ( ( k == -1 ) || ( l == -1) ) return false; 
    
    int u = board[d2R][d2C];
    board[d2R][d2C] = board[k][l];
    board[k][l] = u;
    if (d2R != k) d2R -= d2R - k;
    if (d2C != l) d2C -= d2C -l;
     
     
  /*  int posR = d2R - 1;
    int posC = d2C - 1;
    int posTR, posTC;
    for (int i = d2R - 1-1; i <= d2R - 1+1; i++){
        for (int j = d2C - 1-1; j <= d2C - 1+1; j++){
            if (board[i][j] == tile){
                int u = board[i][j]; 
                board[i][j] = board[d2R - 1][d2C - 1];
                board[d2R - 1][d2C - 1] = u; 
                d2C -= j;
                d2R -= i;
                
            }
        }
        return false;
    }*/
    return 1;
}
  /*  if ((tile ==   board[posR][posC-1]) ||  (tile ==   board[posR][posC+1]) || (tile == board[posR-1][posC-1]) || 
        (tile == board[posR-1][posC+1]) ||  (tile == board[posR+1][posC-1]) || (tile == board[posR+1][posC+1]) ){
        
    }*/

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int m = -1;
    int n = 0;
    for ( int i = 0; i < d; i++){
        for ( int j = 0; j < d; j++){
                if ( (board[i][j] > m) && (m!= 0) ){
                    m = board[i][j];
                    n++;
                   
                    continue;
                }
                else if ( (board[d-1][d-1] == 0) && (n == (d*d)-1)){
                    return true;
                }
                else{
                    return false;
                }
                
               

                
        }
    }
    // TODO
    printf("Your won\n");
    return true;
}