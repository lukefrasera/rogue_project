// Header Files
#include <fstream>
#include "formatted_console_io_V18.h"

using namespace std;

// Global Constants

   const int MAX_COL = 2;
   const int NAME_MAX = 20;
   const int SCORE_NUMBERS = 10;
   const int MAP_SIZE = 500;
   const int ZERO = 0;
   const int HUNDRED = 100;
   const int MAX_ITEMS = 10;
   const int Y_INCREMENT = 2;
   const char COMMA = ',';
   const char SPACE = ' ';
   const char PLAYER = '*';
   const int GAME_MAX_X = 62;
   const int GAME_MAX_Y = 23;

   // title screen constants
   const int MAX_ROWS = 237;
   const int MAX_COLUMNS = 3;
   const int STD_STR_LEN = 40;
   const int COLUMN_ONE = 0;
   const int COLUMN_TWO = 1;
   const int COLUMN_THREE = 2;
   
   // displaySquare constants
   const short WALL_SYMBOL = 176;

   // instructions constants
   const int TITLE_SCRN_MIN_X = 9;
   const int TITLE_SCRN_MIN_Y = 2;
   const int TITLE_SCRN_MAX_X = 72;
   const int TITLE_SCRN_MAX_Y = 23;
   const short CLOAK = 247;
   const short HOLE = 178;
   const short TREASURE = 232;
   const short SPELL = 234;
   const short MONSTER = 206;
   const short SWORD = 157;
   const char DOWN_CHAR = 'D';
   const char UP_CHAR = 'U';
   const int CLOAK_X = 23;
   const int CLOAK_Y = 6;
   const int HOLE_X = 63;
   const int HOLE_Y = 6;
   const int TREASURE_X = 34;
   const int TREASURE_Y = 8;
   const int SPELL_X = 22;
   const int SPELL_Y = 10;
   const int MONSTER_X = 36;
   const int MONSTER_Y = 12;
   const int SWORD_X = 26;
   const int SWORD_Y = 14;
   const int UP_CHAR_X = 22;
   const int UP_CHAR_Y = 16;
   const int DOWN_CHAR_X = 28;
   const int DOWN_CHAR_Y = 16;

   // option display constants
   const int OPT_SCRN_MIN_X = 22;
   const int OPT_SCRN_MIN_Y = 4;
   const int OPT_SCRN_MAX_X = 57;
   const int OPT_SCRN_MAX_Y = 19;

   // difficulty prompt constants
   const int DIFF_SCRN_MIN_X = 14;
   const int DIFF_SCRN_MIN_Y = 11;
   const int DIFF_SCRN_MAX_X = 66;
   const int DIFF_SCRN_MAX_Y = 15;

   // name prompt constant
   const int NAME_SCRN_MIN_X = 17;
   const int NAME_SCRN_MIN_Y = 9;
   const int NAME_SCRN_MAX_X = 64;
   const int NAME_SCRN_MAX_Y = 15;

  // error display constants
   const int ERR_SCRN_MIN_X = 18;
   const int ERR_SCRN_MIN_Y = 9;
   const int ERR_SCRN_MAX_X = 62;
   const int ERR_SCRN_MAX_Y = 15;
   const int ERR_SCRN_CNTR = 40;

  // high score display constants
   const int TITLE_X = 30;
   const int TITLE_Y = 2;

   // spawn item constants
   const int ONE = 1;
   const int MAX_SPAWN = 100;
   const int MAX_RAND_X = 61;
   const int MAX_RAND_Y = 22;
   const int MAX_HOLE = 35;
   const int MIN_CLOAK = 36;
   const int MAX_CLOAK = 45;
   const int MIN_TREASURE = 46;
   const int MAX_TREASURE = 50;
   const int MIN_SPELL = 51;
   const int MAX_SPELL = 60;
   const int MIN_MONSTER = 61;
   const int MAX_MONSTER = 85;
   const int MIN_SWORD = 86;
   const int MAX_SWORD = 95;

// Function Prototypes

/*
Name: displayTitle
Process: displays the title screen with a loaded text file for the title name
Function Input/Parameter: none
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18, fstream I/O tools
Developer: Derek Dalbey
*/
void displayTitle();

/*
Name: displayInstruction
Process: displays the instruction screen
Function Input/Parameter: none
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18
Developer: Derek Dalbey
*/
void displayInstruction();

/*
Name: promptForDifficulty
Process: displays the prompt for difficulty screen
Function Input/Parameter: none
Function Output/Parameter: none
Function Output/Return: difficulty ( int )
Device Input: difficulty
Device Output: prompt
Dependencies: formatted console v_18
Developer: Derek Dalbey
*/
int promptForDifficulty();

/*
Name: promptForName
Process: prompts for the player's name
Function Input/Parameter: name ( char array )
Function Output/Parameter: none
Function Output/Return: none
Device Input: player name
Device Output: prompt
Dependencies: formatted console v_18
Developer: Jennifer Tang
*/
void promptForName( char name[] );

/*
Name: displayOptions
Process: displays the options screen
Function Input/Parameter: none
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: options menu
Dependencies: formatted console v_18
Developer: Jennifer Tang
*/
void displayOptions();

/*
Name: openMapFile
Process: opens the map file and puts into a short array
Function Input/Parameter: map name (char array), map array (short 2d array)
Function Output/Parameter: none
Function Output/Return: size of the map
Device Input: none
Device Output: none
Dependencies: formatted console v_18, fstream I/O tools
Developer: Jennifer Tang
*/
int openMapFile( const char fileName[], short mapArr[][ GAME_MAX_X ] );

/*
Name: displayMapError
Process: displays map error if maps aren't found
Function Input/Parameter: none
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18
Developer: Jennifer Tang
*/
void displayMapError();

/*
Name: startGame
Process: starts game process
Function Input/Parameter: difficulty, levels ( 3 shorts and 3 sizes ), gameField (2d short array)
Function Output/Parameter: none
Function Output/Return: score of game
Device Input: keyboard ( move )
Device Output: game
Dependencies: formatted console v_18, fstream I/O tools
Developer: Jennifer Tang & Derek Dalbey
*/
int startGame( int difficulty, short low[][ GAME_MAX_X ], short mid[][ GAME_MAX_X ], short high[][ GAME_MAX_X ],
                    int lowSize, int midSize, int highSize, short gameField[GAME_MAX_X] [GAME_MAX_X] );

/*
Name: spawnObject
Process: spawns an object based off of probabilty
Function Input/Parameter: gamefield (2d char array)
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: game
Dependencies: formatted console v_18
Developer: Derek Dalbey
*/
void spawnObject( short gameField [][GAME_MAX_X]);

/*
Name: getRandomBetween
Process: calculates random number between low and high specified limit
Function Input/Parameter: low, high limits (int)
Function Output/Parameter: none
Function Output/Return: value processed as specified
Device Input: none
Device Output: none
Dependencies: formatted console v_18, rand
Developer: Jennifer Tang
*/
int getRandomBetween( int lowVal, int highVal );

/*
Name: move
Process: moves the character based on the difficulty
Function Input/Parameter: x and y positions, x and y vectors
Function Output/Parameter: none
Function Output/Return: true of false if it moves
Device Input: none
Device Output: none
Dependencies: formatted console v_18
Developer: Derek Dalbey
*/
bool move( int &xPos, int &yPos, int xVect, int yVect);

/*
Name: uploadHighScore
Process: uploads high scores to program
Function Input/Parameter: file name for high score, scoreboard ( int ), name board ( char )
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18, fstream
Developer:  Jennifer Tang
*/
void uploadHighScore( char fileName[], int scoreBoard[], char nameBoard[][ NAME_MAX ] );

/*
Name: downloadHighScore
Process: sort and download scores to text file
Function Input/Parameter: new high score (int), player's name (char array), all scores (int array), all names ( 2d char array)
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18, fstream I/O tools
Developer: Derek Dalbey
*/
void downloadHighScore( int scoreBoard[], char nameBoard[][NAME_MAX], int score, char newName[] );

/*
Name: displayHighScore
Process: displays high score
Function Input/Parameter: scoreboard (int array), nameboard ( 2d char array )
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18, fstream I/O tools
Developer: Jennifer Tang
*/
void displayHighScore( int scoreBoard[], char nameBoard[][ NAME_MAX ] );

/*
Name: displaySquare
Process: displays colored square
Function Input/Parameter: 
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18
Developer: Derek Dalbey
*/
void displaySquare();

/*
Name: swapScores
Process: tests for new high score and sorts scores
Function Input/Parameter: new high score (int), player's name (char array), all scores (int array), all names ( 2d char array)
Function Output/Parameter: none
Function Output/Return: none
Device Input: none
Device Output: none
Dependencies: formatted console v_18, fstream I/O tools
Developer: Derek Dalbey
*/
void sortScores( int newScore, char newName[], int scoreBoard[], char nameBoard[][NAME_MAX] );


// Main Program
int main()
   {
    // initialize variables
       char userInput, scoreFile[STD_STR_LEN] = "scores.txt", playerName[ HUNDRED ],
            lowFile[ HUNDRED ] = "lowlevel.txt", midFile[ HUNDRED ] = "midlevel.txt",
            highFile[ HUNDRED ] = "highlevel.txt", nameBoard [ MAX_ITEMS][NAME_MAX];
       int difficulty, score, lowSize, midSize, highSize, scoreBoard [MAX_ITEMS];
       short low[ GAME_MAX_Y ][ GAME_MAX_X ], mid[ GAME_MAX_Y ][ GAME_MAX_X ], high[ GAME_MAX_Y ][ GAME_MAX_X ], gameField [GAME_MAX_Y] [GAME_MAX_X];
       bool continueGame = true;
       
       // seed random generator
          // function: srand
             srand( time( NULL ) );

       // start curses
          // function: startCurses
             startCurses();

    // initialize program

       // display title screen
          // function: displayTitle
             displayTitle();

    // display instruction screen
       // function: displayInstruction
          displayInstruction();

    // display main menu

       // display options
          // function: displayOptions
             while( continueGame == true )
                {
                 displayOptions();
                 userInput = waitForInput( FIXED_WAIT );
                 switch( userInput )
                  {
                   case '1':
                   case 'd':
                   case 'D':
                   difficulty = promptForDifficulty();
                   break;

                   case '2':
                   case 'p':
                   case 'P':   
                   promptForName( playerName );
                   
                   if( openMapFile( lowFile, low ) == -1 || openMapFile( midFile, mid ) || -1 && openMapFile( highFile, high ) == -1 )
                      {
                       displayMapError();
                       displayOptions();
                      }
                   else
                   {
                   score = startGame( difficulty, low, mid, high, lowSize,
                                                         midSize, highSize, gameField );
                   downloadHighScore( scoreBoard, nameBoard, score, playerName );
                   break;

                   case '3':
                   case 's':
                   case 'S':
                   uploadHighScore( scoreFile, scoreBoard, nameBoard );
                   displayHighScore( scoreBoard, nameBoard );
                   break;

                   case '4':          
                   case 'q':
                   case 'Q':
                   continueGame = false;
                   break;
                   }
                  }
               }
  
    // end program 
       
       // close curses
         // function: endCurses
            endCurses();

       // return success
          return 0;
   }

// Supporting Function Implementation

void displayTitle()
   {

    // initialize variables

       // set initial x and y positions
       int xPos = 0, yPos = 0;

       // declare other variables
       char inFileName [STD_STR_LEN] = "titlearr.txt";
       int coords [MAX_ROWS][ MAX_COLUMNS ], rowCounter = 0, row = 0;
       ifstream inf;

    // set color for initial screen
       // function: setColor
    setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

    // clear screen
       // function: clearScreen
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // clear and open input file
    inf.clear();
    inf.open( inFileName );   
       
    // get string from file
       // begin loop to end of file
       for( rowCounter = 0; rowCounter < MAX_ROWS; rowCounter++ )
          {         
           // get next character, place in array
              // function: inf
           inf >> coords [ rowCounter ][COLUMN_ONE] >> coords [rowCounter][COLUMN_TWO] >> coords [rowCounter][COLUMN_THREE];
          }               

    // close file
       // function: fstream.close
    inf.close();

       // begin update loop to print letter chars
       for( row = 0; row < MAX_ROWS; row++)
          {
       
               xPos = coords [ row ] [ COLUMN_ONE ];
               yPos = coords [ row ] [ COLUMN_TWO ];
               printCharAt( xPos, yPos, (char)coords[row][COLUMN_THREE]);

          }

    // give credits and hold screen

       // update x and y positions for credits
       xPos = 20;
       yPos = 20;

       // set color for text
          // function: setColor
       setColor( COLOR_CYAN, COLOR_BLACK, SET_BRIGHT );

       // print credit string
          // function: printStringAt
       printStringAt( xPos, yPos, "Implemented by Derek Dalbey and Jennifer Tang", "LEFT" );

       // update x and y positions for hold screen prompt
       xPos = 29;
       yPos = 22;

       // print prompt string
          // function: printStringAt
       printStringAt( xPos, yPos, "Press Any Key to Continue", "LEFT" );

       // hold screen
          // function: waitForInput
       waitForInput( FIXED_WAIT );
   }

void displayInstruction()
   {
    // initialize variables
    
       // set initial x and y positions
       int xPos = 40;
       int yPos = 3;

    // set color for background
       // function: setColor
    setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

    // clear screen
       // function: clearScreen
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );        

    // set color for instruction box
       // function: setColor
    setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );

    // clear screen for gray box
       // function: clearScreen
    clearScreen( TITLE_SCRN_MIN_X, TITLE_SCRN_MIN_Y, TITLE_SCRN_MAX_X, TITLE_SCRN_MAX_Y ); 

    // print title string
       // function: printStringAt
    printStringAt( xPos, yPos, "Rogue-Like Instructions", "CENTER");

    // update y position
    yPos++;

    // print title underline 
       // function: printStringAt
    printStringAt( xPos, yPos, "=======================", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print cloak and hole information
       // function: printStringAt
    printStringAt( xPos, yPos, "Green   are magic cloaks that can cover holes  ", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print treasure information
       // function: printStringAt
    printStringAt( xPos, yPos, "Yellow   are golden treasure", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print spell information
       // function: printStringAt
    printStringAt( xPos, yPos, "Green   are spells that let you walk through walls", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print monster information
       // function: printStringAt
    printStringAt( xPos, yPos, "Red   are monsters", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print sword information
       // function: printStringAt
    printStringAt( xPos, yPos, "Green   are swords than can slay monsters", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print ladder information
       // function: printStringAt
    printStringAt( xPos, yPos, "  and   lead to Upper and Lower floors", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print end game information
       // function: printStringAt
    printStringAt( xPos, yPos, "Hitting a hole or monster ends the game", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print goal
       // function: printStringAt
    printStringAt( xPos, yPos, "Try to keep moving for as long as possible", "CENTER");

    // update y position
    yPos = yPos + Y_INCREMENT;

    // print score information
       // function: printStringAt
    printStringAt( xPos, yPos, "More treasure, cloaks, spells, and swords get a better score", "CENTER");

    // set color for cloak, spell, and sword
       // function: setColor
    setColor( COLOR_GREEN, COLOR_WHITE, SET_BRIGHT );

    // print cloak symbol
       // function: printSpecialCharAt
    printSpecialCharAt( CLOAK_X, CLOAK_Y, CLOAK );

    // print spell symbol
       // function: printSpecialCharAt
    printSpecialCharAt( SPELL_X, SPELL_Y, SPELL );

    // print sword symbol
       // function: printSpecialCharAt
    printSpecialCharAt( SWORD_X, SWORD_Y, SWORD );

    // set color for hole and monster
       // function: setColor
    setColor( COLOR_RED, COLOR_WHITE, SET_BRIGHT ); 

    // print hole symbol
       // function: printSpecialCharAt
    printSpecialCharAt( HOLE_X, HOLE_Y, HOLE );

    // print monster symbol
       // function: printSpecialCharAt
    printSpecialCharAt( MONSTER_X, MONSTER_Y, MONSTER );

    // set color for up and down ladders
       // function: setColor
    setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT ); 

    // print down symbol
       // function: printCharAt
    printCharAt( DOWN_CHAR_X, DOWN_CHAR_Y, DOWN_CHAR );

    // print up symbol
       // function: printCharAt
    printCharAt( UP_CHAR_X, UP_CHAR_Y, UP_CHAR );

    // set color for treasure
       // function: setColor
    setColor( COLOR_YELLOW, COLOR_WHITE, SET_BRIGHT ); 

    // print treasure symbol
       // function: printSpecialCharAt
    printSpecialCharAt( TREASURE_X, TREASURE_Y, TREASURE );

    // update x and y positions
    xPos = 71;
    yPos = 22;

    // move cursor to final position
       // function: moveToXY
    moveToXY( xPos, yPos );

    // hold screen
       // function: waitForInput
    waitForInput( FIXED_WAIT );

   }

int promptForDifficulty()
   {
    // initialize program

       // initialize variables

          // set initial x and y positions
          int xPos = 40, yPos = 12;

          // declare other variables
          int difficulty;

       // set color for initial screen
          // function: setColor
       setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

       // clear screen
          // function: clearScreen
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // set color for difficulty prompt box
          // function: setColor
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

       // clear screen
          // function: clearScreen
       clearScreen( DIFF_SCRN_MIN_X, DIFF_SCRN_MIN_Y, DIFF_SCRN_MAX_X, DIFF_SCRN_MAX_Y );

       // print "Game Data Entry Module"
          // function: printStringAt
       printStringAt( xPos, yPos, "Game Data Entry Module", "CENTER");

       // update x and y position
       xPos = 20;
       yPos = 14;

       // prompt for game difficulty
          // function: printStringAt
       printStringAt(xPos, yPos, "Enter Game Difficulty <1-3>: ", "LEFT" );
       
       do
       {
         difficulty = waitForInput( FIXED_WAIT );  

         switch( difficulty )
          {
           case '1':
           difficulty = 1;
           break;

           case '2':
           difficulty = 2;
           break;

           case '3': 
           difficulty = 3;
           break;
           } 
       
       } 
       while( difficulty > 3 );

       return difficulty;
   }

void promptForName( char name[] )
   {
    // initialize variables
       int promptX = NAME_SCRN_MIN_X + 8, promptY = NAME_SCRN_MIN_Y + 3;

    // set background color
       // function: setColor
          setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

    // clear screen
       // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // set color for box
       // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // make a display box
       // function: clearScreen
          clearScreen( NAME_SCRN_MIN_X, NAME_SCRN_MIN_Y, NAME_SCRN_MAX_X, NAME_SCRN_MAX_Y );

    // prompt for the player's name
       // function: promptForStringAt
          promptForStringAt( promptX, promptY, "Enter your name: ", name );

   }

void displayOptions()
  {
    // initialize variables
       int displayX = OPT_SCRN_MIN_X + 8, oneY = OPT_SCRN_MIN_Y + 3, twoY = OPT_SCRN_MIN_Y + 4,
           threeY = OPT_SCRN_MIN_Y + 7, fourY = OPT_SCRN_MIN_Y + 8, fiveY = OPT_SCRN_MIN_Y + 9,
           sixY = OPT_SCRN_MIN_Y + 10, sevenY = OPT_SCRN_MIN_Y + 12;

    // set background color
       // function: setColor
          setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

    // clear screen
       // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // set color for box
       // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // make a display box
       // function: clearScreen
          clearScreen( OPT_SCRN_MIN_X, OPT_SCRN_MIN_Y, OPT_SCRN_MAX_X, OPT_SCRN_MAX_Y );

    // display text
       // function: printStringAt
          printStringAt( displayX, oneY, "MENU SELECTIONS", "LEFT" );
          printStringAt( displayX, twoY, "===============", "LEFT" );
          printStringAt( displayX, threeY, "1. Set <D>ifficulty", "LEFT" );
          printStringAt( displayX, fourY, "2. <P>lay Game", "LEFT" );
          printStringAt( displayX, fiveY, "3. <S>how Top Scores", "LEFT" );
          printStringAt( displayX, sixY, "4. <Q>uit Program", "LEFT" );
          printStringAt( displayX, sevenY, "Enter Selection: ", "LEFT" );

  }

int openMapFile( const char fileName[], short mapArr[][ GAME_MAX_X ] )
{
  ifstream inf;
  int x, y;
  int index, index_2;

  inf.clear();
  inf.open( fileName );

  if(!inf.good())
  {
    return -1;
  }

  for( index = 0; index < GAME_MAX_Y; index++ )
  {
    for( index_2 = 0; index_2 < GAME_MAX_X; index_2++ )
    {
      mapArr[index][index_2] = SPACE;
    }
  }


  while( inf.peek() != EOF )
  {
    inf >> x >> y;

    mapArr[y][x] = WALL_SYMBOL;
  }
  
  inf.close();

  return 0;
}

void displayMapError()
   {
    // initialize variables
       int xPos = 35, yPos = ERR_SCRN_MIN_Y + 1;

    // set background color
       // function: setColor
          setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

    // clear screen
       // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // set color for box
       // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // make a display box
       // function: clearScreen
          clearScreen( ERR_SCRN_MIN_X, ERR_SCRN_MIN_Y, ERR_SCRN_MAX_X, ERR_SCRN_MAX_Y );

    // print error message
       // function: printStringAt
          printStringAt( ERR_SCRN_CNTR, yPos, "ERROR MESSAGE WINDOW", "CENTER" );
          yPos = yPos + Y_INCREMENT;
          printStringAt( ERR_SCRN_CNTR, yPos, "Maps not found, game play aborted", "CENTER" );
          yPos = yPos + Y_INCREMENT;
          printStringAt( xPos, yPos, "Press any key to continue", "LEFT");
          
          waitForInput( FIXED_WAIT );

   }

int startGame( int difficulty, short low[][ GAME_MAX_X ], short mid[][ GAME_MAX_X ], short high[][ GAME_MAX_X ],
                    int lowSize, int midSize, int highSize, short gameField [GAME_MAX_Y][GAME_MAX_X] )
   {
    // initialize variables
    int xPos = 0, yPos = 0, cloak_counter = 0, sword_counter = 0, spell_counter = 0, treasure_counter = 0, score_counter = 0, randX, randY, currentVal, prevFloorIndex = 2,
        floorIndex = 2, xVector = 0, yVector = 0,preXvect = 0, preYvect = 0, userInput, waitTime = 3, statusX, statusY, rowIndex, colIndex;
    bool alive = true, complete = false;

    // set interface color
       // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // clear screen for interface
       // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, 15, SCRN_MAX_Y );

    //update x and y positions for ROGUE - LIKE
       xPos = 2;
       yPos = 1;

    // print "ROGUE - LIKE" title
       // function: printStringAt
       printStringAt ( xPos, yPos, "ROGUE - LIKE", "LEFT");

    // update x and y for cloak status
       xPos = 1;
       yPos = 4;

    // print cloak
       // function: printStringAt
       printStringAt ( xPos, yPos, "Cloak:", "LEFT");

    // update y for sword status
       yPos++;

    // print swords
       // function: printStringAt
       printStringAt ( xPos, yPos, "Sword:", "LEFT");

    // update y for spell status
       yPos++;

    // print spell
       // function: printStringAt
       printStringAt ( xPos, yPos, "Spell:", "LEFT");

    // update y for treasure
       yPos = yPos + Y_INCREMENT;

    // print treasure
       // function: printStringAt
       printStringAt ( xPos, yPos, "Treasure:", "LEFT");

    // update y for score
       yPos = yPos + Y_INCREMENT;

    // print score
       // function: printStringAt
       printStringAt ( xPos, yPos, "Score:", "LEFT");

    // update x & y for instructions
       xPos = 7;
       yPos++;
       yPos = yPos + Y_INCREMENT;

    // print instructions
       // function: printStringAt
       printStringAt ( xPos, yPos, "Arrows set", "CENTER");
       yPos++;
       printStringAt ( xPos, yPos, "direction", "CENTER");
       yPos = yPos + Y_INCREMENT;
       printStringAt ( xPos, yPos, "Follow U/D", "CENTER");      
       yPos++;
       printStringAt ( xPos, yPos, "to change", "CENTER");
       yPos++;
       printStringAt ( xPos, yPos, "level", "CENTER");
       yPos = yPos + Y_INCREMENT;
       printStringAt ( xPos, yPos, "Falling into", "CENTER");      
       yPos++;
       printStringAt ( xPos, yPos, "a hole or", "CENTER");      
       yPos++;
       printStringAt ( xPos, yPos, "pressing ESC", "CENTER");      
       yPos++;
       printStringAt ( xPos, yPos, "ends game", "CENTER");     


    // make game square
       // function: displaySquare
       displaySquare();

       // spawn map
          // function: printSpecialCharAt

       for(rowIndex = 0; rowIndex < GAME_MAX_Y; rowIndex++ )
       {
        for(colIndex = 0; colIndex < GAME_MAX_X; colIndex++)
        {
          gameField [rowIndex][colIndex] = mid[rowIndex][colIndex];
        }
       }

       // generate u and d
       setColor ( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT);
       while(!complete)
       {
            randX = getRandomBetween(17, 78);
            randY = getRandomBetween(1, 23);
            if(gameField[randY][randX] != WALL_SYMBOL)
            {
                                      
                gameField[randY][randX] = UP_CHAR;
                complete = true;
            }
       }
       complete = false;

       while(!complete)
       {
            randX = getRandomBetween(17, 78);
            randY = getRandomBetween(1, 23);
            if(gameField[randY][randX] != WALL_SYMBOL && gameField[randY][randX] != UP_CHAR)
            {
                gameField[randY][randX] = DOWN_CHAR;
                complete = true;
            }
       }


       // update difficulty waitTime
          // if difficulty = 3, set waitTime to 1;
          if (difficulty == 3)
             {
              waitTime = 1;
             }

          // if difficulty = 2, set waitTime to 2;
          else if (difficulty == 2)
             {
              waitTime = 2;
             }

       // update x & y for player
          xPos = 45;
          yPos = 2;                   
                         

    // loop game until player dies or esc is pressed
      do
       {
        // get an input key, waiting for user input
        userInput = waitForInput( waitTime );
        // if user input, set direction, otherwise ignore

        preXvect = xVector;
        preYvect = yVector;
        switch( userInput )
           {
            case KB_RIGHT_ARROW:
               xVector = 1;
               yVector = 0;
               break;

            case KB_LEFT_ARROW:
               xVector = -1;
               yVector = 0;
               break;
 
            case KB_UP_ARROW:
               xVector = 0;
               yVector = -1;
               break;

            case KB_DOWN_ARROW:
               xVector = 0;
               yVector = 1;
               break;

            case KB_ESCAPE:
               alive = false;
           }
           
       // print game field
       for(rowIndex = 0; rowIndex < GAME_MAX_Y; rowIndex++ )
       {
        for(colIndex = 0; colIndex < GAME_MAX_X; colIndex++)
        {
          if( gameField[rowIndex][colIndex] == SPACE )
          {
            setColor(COLOR_BLACK, COLOR_WHITE, SET_BRIGHT);
          }
          else if(gameField[rowIndex][colIndex] == UP_CHAR || gameField[rowIndex][colIndex] == DOWN_CHAR )
          {
            setColor(COLOR_WHITE, COLOR_BLUE, SET_BRIGHT);
          }
          else if(gameField[rowIndex][colIndex] == CLOAK || gameField[rowIndex][colIndex] == SWORD || gameField[rowIndex][colIndex] == SPELL)
          {
            setColor(COLOR_GREEN, COLOR_WHITE, SET_BRIGHT);
          }
          else if(gameField[rowIndex][colIndex] == HOLE || gameField[rowIndex][colIndex] == MONSTER )
          {
            setColor(COLOR_RED, COLOR_WHITE, SET_BRIGHT);
          }
          else if(gameField[rowIndex][colIndex] == TREASURE)
          {
            setColor(COLOR_YELLOW, COLOR_WHITE, SET_BRIGHT);
          }
          else if(gameField[rowIndex][colIndex] == WALL_SYMBOL)
          {
            setColor(COLOR_BLUE, COLOR_WHITE, SET_BRIGHT);
          }
          if( gameField[rowIndex][colIndex] <= 127)
          {
           printCharAt( colIndex + 17, rowIndex +1, (char)gameField [rowIndex][colIndex]);
          }
          else 
          {
            printSpecialCharAt ( colIndex + 17, rowIndex +1, (char)gameField [rowIndex][colIndex]);
          }
        }
       }

       currentVal = gameField [yPos - 1 + yVector][xPos - 17 + xVector];

       // if character moves over spawned object, check for effect ( status )
       if( currentVal == HOLE)
          {
           if( cloak_counter == 0)
             {
               alive = false;
             }
           else
             {
               cloak_counter--;
               score_counter--;
               gameField [yPos - 1 + yVector][xPos - 17 + xVector] = SPACE;
             }
          }

       if( currentVal == CLOAK)
          {
            cloak_counter++;
            score_counter++;
            gameField [yPos - 1 + yVector][xPos - 17 + xVector] = SPACE;
          }
          
       if( currentVal == SWORD)
          {
            sword_counter++;
            score_counter++;
            gameField [yPos - 1 + yVector][xPos - 17 + xVector] = SPACE;           
          }

       if( currentVal == SPELL)
          {
            spell_counter++;
            score_counter++;
            gameField [yPos - 1 + yVector][xPos - 17 + xVector] = SPACE;
          }
          
       if( currentVal == MONSTER)
          {
           if( sword_counter == 0)
             {
               alive = false;       
             }
           else
             {
               sword_counter--;
               score_counter--;
               gameField [yPos - 1 + yVector][xPos - 17 + xVector] = SPACE;
             }
          }

        if( currentVal == TREASURE)
        {
            score_counter += 5;
            treasure_counter++;
            gameField [yPos - 1 + yVector][xPos - 17 + xVector] = SPACE;
        }  
        
        if( currentVal == WALL_SYMBOL)
        {
            if( spell_counter == 0 )
            {
              xVector = 0;
              yVector = 0;
            }
            else 
            {
                spell_counter--;
            }
        }
        
        prevFloorIndex = floorIndex;
        
        if( currentVal == UP_CHAR )
        {
            floorIndex++;
        }
            
        if( currentVal == DOWN_CHAR )
        {
            floorIndex--;
        }          
        
        if( prevFloorIndex != floorIndex )
        {
         for(int i = 0; i < GAME_MAX_Y; i++ )
         {
            for( int j = 0; j < GAME_MAX_X; j++ )
            {
                if( floorIndex == 1)
                {
                  gameField[i][j] = low[i][j];
                }
                if( floorIndex == 2)
                {
                  gameField[i][j] = mid[i][j];
                }
                if( floorIndex == 3)
                {
                  gameField[i][j] = high[i][j];
                }
            }     
         }
           xPos = 45;
           yPos = 3;    
           xVector = 0;
           yVector = 0;
           complete = false;
           if( floorIndex == 3)
           {

                complete = false;

               while(!complete)
               {
                    randX = getRandomBetween(17, 78);
                    randY = getRandomBetween(1, 23);
                    if(gameField[randY][randX] != WALL_SYMBOL && gameField[randY][randX] != UP_CHAR)
                    {
                        gameField[randY][randX] = DOWN_CHAR;
                        complete = true;
                    }
               }    
           }    

        if( floorIndex == 2)
        {
            while(!complete)
           {
                randX = getRandomBetween(17, 78);
                randY = getRandomBetween(1, 23);
                if(gameField[randY][randX] != WALL_SYMBOL)
                {
                                          
                    gameField[randY][randX] = UP_CHAR;
                    complete = true;
                }
           }
           complete = false;

           while(!complete)
           {
                randX = getRandomBetween(17, 78);
                randY = getRandomBetween(1, 23);
                if(gameField[randY][randX] != WALL_SYMBOL && gameField[randY][randX] != UP_CHAR)
                {
                    gameField[randY][randX] = DOWN_CHAR;
                    complete = true;
                }
           }
        }

        if( floorIndex == 1)
        {
                   while(!complete)
           {
                randX = getRandomBetween(17, 78);
                randY = getRandomBetween(1, 23);
                if(gameField[randY][randX] != WALL_SYMBOL)
                {
                                          
                    gameField[randY][randX] = UP_CHAR;
                    complete = true;
                }
           }
           complete = false;
        }
    }
            
            
    // if dead
    if ( alive == false )
       {
           move( xPos, yPos, 0, 0 );
       }
    else
     {
       // move the character
       if( preXvect == xVector && preYvect == yVector && userInput != ERR )
       {
           move( xPos, yPos, 0, 0 );
       }
       else
       {
           move( xPos, yPos, xVector, yVector );
       }
       // spawn random generated objects
          // function: spawnObject
       spawnObject( gameField );
     }
       
         // set x and y position for cloak counter
           statusX = 13;
           statusY = 4;
           printIntAt(statusX, statusY, cloak_counter, "RIGHT");
           statusY++;
           printIntAt(statusX, statusY, sword_counter, "RIGHT");
           statusY++;
           printIntAt(statusX, statusY, spell_counter, "RIGHT");
           statusY+=2;
           printIntAt(statusX, statusY, treasure_counter, "RIGHT");
           statusY+=2;      
           printIntAt(statusX, statusY, score_counter, "RIGHT");
       }while( alive == true );

    // display game over screen
       // update x and y positions
       statusX = ONE;
       statusY = 13;

       // set color for game over 
       setColor( COLOR_YELLOW, COLOR_RED, SET_BRIGHT);

       // clear screen
       clearScreen(statusX, statusY, 13, 23);
       
       // update x and y positions for text
       statusX = 7;
       statusY = 17;
       
       
       // print GAME ENDS
       printStringAt( statusX, statusY, "GAME", "CENTER");
       statusY = statusY + Y_INCREMENT;
       printStringAt( statusX, statusY, "ENDS", "CENTER");

    // return score
    return score_counter; 

   }

void spawnObject( short gameField [] [GAME_MAX_X] )
   {
    // initialize variables
       int itemNum, randX, randY, index = 0;
       bool counter = true;

    // generate random number
       // function: getRandomBetween
    itemNum = getRandomBetween( ONE, MAX_SPAWN);

    // loop while counter < 1
    while (counter)
       {
        // generate random x position
        randX = getRandomBetween( ZERO, GAME_MAX_X);

        // generate random y position
        randY = getRandomBetween( ZERO, GAME_MAX_Y);

        // spawn item
           // test if position in array == space
           if( gameField [randY] [randX] == SPACE )  
              { 
               // and itemNum is between 1 and 35, print hole, increment counter
               if( itemNum >= ONE && itemNum <= MAX_HOLE)
                  {
                   gameField [randY][randX] = HOLE;
                   counter = false;
                  }

               // and itemNum is between 36 and 45, print cloak, increment counter
               if( itemNum >= MIN_CLOAK && itemNum <= MAX_CLOAK)
                  {
                   gameField [randY][randX] = CLOAK;
                   counter = false;
                  }

               // and itemNum is between 46 and 50, print treasure, increment counter
               if( itemNum >= MIN_TREASURE && itemNum <= MAX_TREASURE)
                  {
                   gameField [randY][randX] = TREASURE;
                   counter = false;
                  }

               // and itemNum is between 51 and 60, print spell, increment counter
               if( itemNum >= MIN_SPELL && itemNum <= MAX_SPELL)
                  {
                   gameField [randY][randX] = SPELL;
                   counter = false;
                  }

               // and itemNum is between 61 and 85, print monster, increment counter
               if( itemNum >= MIN_MONSTER && itemNum <= MAX_MONSTER)
                  {
                   gameField [randY][randX] = MONSTER;
                   counter = false;
                  }     

               // and itemNum is between 86 and 95, print sword, increment counter
               if( itemNum >= MIN_SWORD && itemNum <= MAX_SWORD)
                  {
                   gameField [randY][randX] = SWORD;
                   counter = false;
                  }
                   index++;
                   if( index > 2000 )
                   {
                      counter = false;
                   }
               // and itemNum is between 96 and 100, counter = 0
              }
       }
   }

int getRandomBetween( int lowVal, int highVal )
   {
    // initialize function/variables

       // initialize range value to inclusive difference 
       //   between low and high limits

    // return randomly generated value between low and high, starting at low
       // function: rand
    return ( (int)((rand() + lowVal) % highVal ));

   }

bool move( int &xPos, int &yPos, int xVect, int yVect )
   {
    // initialize function/variables
    bool moved = false;
    int oldX = xPos, oldY = yPos;

    // if x vector is live, test for acceptable movement limits
    if( ( xVect != 0 ) // is meant to move
          && ( xPos + xVect >= 17 ) // won't go off left side of screen 
               && ( xPos + xVect <= SCRN_MAX_X-1 )  ) // won't go off right side of screen
       {
        // cover up the old marker
        setColor( COLOR_BLACK, COLOR_WHITE, SET_BRIGHT );
        printCharAt( oldX, oldY, SPACE );

        // reset the x position
        xPos = xPos + xVect;

        // set moved flag to indicate success
        moved = true;
       }

    // if y vector is live, test for acceptable movement limits
    else if( ( yVect != 0 ) // is meant to move
               && ( yPos + yVect >= SCRN_MIN_Y+1 ) // won't go off top of screen (!= WALL_SYMBOL)?
                    && ( yPos + yVect <= SCRN_MAX_Y-1 ) ) // won't go off bottom of screen
       {
        // cover up the old marker
        setColor( COLOR_BLACK, COLOR_WHITE, SET_BRIGHT );
        printCharAt( oldX, oldY, SPACE );

        // reset the y position
        yPos = yPos + yVect;

        // set the moved flag to indicate success
        moved = true;
       }

    // set char color
    setColor(COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // print the marker at the specified location
    printCharAt( xPos, yPos, PLAYER );

    // return successful move
    return moved;
   }


void uploadHighScore( char fileName[], int scoreBoard[], char nameBoard[][ NAME_MAX ] )
   {
    // initialize variables
       ifstream inf;
       int index = 0, value, numChar = 0;
       char name, dummy;
    
    // clear file
       // function: inf.clear
          inf.clear();

    // open downloaded score file
       // function: inf.open
          inf.open( fileName );

    // input char values into char array
       // function: inf.good   
          inf >> value;         
         
          while( inf.good() )
             {
              scoreBoard[ index ] = value;
              inf >> dummy;
              inf >> name;
              while( name != '\n' )
                 {
                  nameBoard[ index ][ numChar ] = name;
                  inf >> name;
                  numChar++;
                 }
               numChar = 0;
               inf >> value;
               index++;
             }

    // close file
       // function: inf.close
          inf.close();
   }

void downloadHighScore( int scoreBoard[], char nameBoard[][NAME_MAX], int score, char newName[] )
   {
    // initialize variables
	ofstream fout;
	int index = 0;
    char fileName [STD_STR_LEN] = "scores.txt";

    // sort scores
       // function: sortScores
    sortScores( score, newName, scoreBoard, nameBoard );

	// clear ifstream flags
       // function: .clear
	fout.clear();

	// open file
       // function: .open
	fout.open( fileName );
 
	// loop through all names and scores printing to file
	while( index < SCORE_NUMBERS )
	   {
	
		// store score and comma to file
		fout << scoreBoard[index] << ",";
		
		// loop name and store to file
		fout << nameBoard[index] << '\n';
	   }

	// close file
	fout.close();

   }

void displayHighScore( int scoreBoard[], char nameBoard[][ NAME_MAX ] )
   {
    // initialize variables
       int lineOneY = TITLE_Y + 1, lineTwoY = TITLE_Y + 4,
           namesTitleX = TITLE_X - 6, scoresTitleX = TITLE_X + 19,
           titleY = TITLE_Y + 3, inputY = lineTwoY + 2, scoresX = scoresTitleX + 3,
           counterIndex = 10, index = 0;

    // set background color
       // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
   
    // clear screen
       // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // print title and subtitles
       // function: printStringAt
          printStringAt( TITLE_X, TITLE_Y, "TOP SCORING PLAYERS", "LEFT"  );
          printStringAt( TITLE_X, lineOneY, "===================", "LEFT" );
          printStringAt( namesTitleX, titleY, "NAMES", "LEFT" );
          printStringAt( namesTitleX, lineTwoY, "=====", "LEFT" );
          printStringAt( scoresTitleX, titleY, "SCORES", "LEFT" );
          printStringAt( scoresTitleX, lineTwoY, "======", "LEFT" );

    // print names and scores
       // function: printCharAt, printIntAt
          while( counterIndex >> 0 )
             {
              printStringAt( namesTitleX, inputY, nameBoard[ index ], "LEFT" );
              printIntAt( scoresX, inputY, scoreBoard[ index ], "LEFT" );
              index++;
              counterIndex--;
             }

    // print press any key to continue, update y position
       // function: printStringAt
          inputY = inputY + 2;
          setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
          printStringAt( namesTitleX, inputY, "Press any Key to Continue . . .", "LEFT" );

    // hold screen for user
       // function: waitForInput
          waitForInput( FIXED_WAIT );

   }

void displaySquare()
   {
    // initialize function/variables
    int row = 0, column = 16;

    // set color
    setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );

    // iterate from left to right across box
    for( row = 0; row < SCRN_MAX_Y+1; row++ )
       {
        for( column = 16; column < SCRN_MAX_X+1; column++)
         {
           printSpecialCharAt(column, row, WALL_SYMBOL);
         }     
       }
   }

void sortScores( int score, char playerName[ ], int scoreBoard[], char nameBoard[][NAME_MAX] )
   {
	// intitalize temporary arrays
	int scoreTemp, index = 0, indexTwo = 0, indexThree = 0;
	char nameTemp[NAME_MAX];

	// loop through scoreboard
	for( index = 0; index < SCORE_NUMBERS; index++ )
	   {
    
		// test if score is higher than current highscores
		if( score > scoreBoard[index] )
		   {

			// if score is higher loop through the rest of the array shifting
			// names down the list
			
			for( indexTwo = index; indexTwo < SCORE_NUMBERS; indexTwo++)
			   {

				// shift score down the score array // this step is the confusing part
				scoreTemp = scoreBoard[indexTwo];
				scoreBoard[indexTwo] = score;
				score = scoreTemp;

				// shift names down the array // also confusing
				for( indexThree = 0; indexThree < NAME_MAX; indexThree++ )
				   {
					nameTemp[indexThree] = nameBoard[indexTwo][indexThree];
					nameBoard[indexTwo][indexThree] = playerName[indexThree];
					playerName[indexThree] = nameTemp[indexThree];
				   }
			   }
		   }
	   }
   }
