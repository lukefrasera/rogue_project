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
int openMapFile( char name[], short mapArr[][ MAX_COL ] );

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
int startGame( int difficulty, short low[][ MAX_COL ], short mid[][ MAX_COL ], short high[][ MAX_COL ],
                    int lowSize, int midSize, int highSize, short gameField[GAME_MAX_X] [GAME_MAX_Y] );

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
void spawnObject( short gameField [GAME_MAX_X][GAME_MAX_Y]);

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
       short low[ MAP_SIZE ][ MAX_COL ], mid[ MAP_SIZE ][ MAX_COL ], high[ MAP_SIZE ][ MAX_COL ], gameField [GAME_MAX_X] [GAME_MAX_Y];
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
                   lowSize = openMapFile( lowFile, low );
                   midSize = openMapFile( midFile, mid );
                   highSize = openMapFile( highFile, high );
                   if( lowSize <= 0 || midSize <= 0 || highSize <= 0 )
                      {
                       displayMapError();
                       waitForInput( FIXED_WAIT );
                       displayOptions();
                      }
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

int openMapFile( char fileName[], short mapArr[][ MAX_COL ] )
   {
    // initialize variables
       ifstream inf;
       int mapSize = 0, rowIndex = 0;

    // clear file
       // function: inf.clear
          inf.clear();

    // open file
       // function: inf.open
          inf.open( fileName );

    // extract data to map array
       // function: while

          while( inf.good() )
            {     
              // get next character, place in array
                // function: inf
                  inf >> mapArr [ rowIndex ][COLUMN_ONE] >> mapArr [ rowIndex ][COLUMN_TWO];
                  rowIndex++;
                  mapSize++;
                  mapSize++;
            }         
          
    // close file
       // function: inf.close
          inf.close();

    // return the size of the map
       return mapSize;
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

   }

int startGame( int difficulty, short low[][ MAX_COL ], short mid[][ MAX_COL ], short high[][ MAX_COL ],
                    int lowSize, int midSize, int highSize, short gameField [GAME_MAX_X][GAME_MAX_Y] )
   {
    // initialize variables
    int xPos = 0, yPos = 0, cloak_counter = 0, sword_counter = 0, spell_counter = 0, treasure_counter = 0, score_counter = 0,
        floorIndex = 2, mapX, mapY, xVector = 0, yVector = 0, index = 0, x, y, userInput, waitTime = 3, statusX, statusY, row =0, column=0;
    bool alive = true;

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
             while( index < midSize )
                   {
                    mid[ index ][ x ] = mapX;
                    mid[ index ][ y ] = mapY;
                    printCharAt( mapX, mapY, WALL_SYMBOL );
                    index++;
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
          yPos = 5;                   
                         

    // loop game until player dies or esc is pressed
      do
       {
        // get an input key, waiting for user input
        userInput = waitForInput( waitTime );

        // if user input, set direction, otherwise ignore
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

       // move the character
       move( xPos, yPos, xVector, yVector );

       // spawn random generated objects
          // function: spawnObject
       spawnObject( gameField );

       for( row = 0; row < GAME_MAX_X; row++)
          {
           for( column = 0; column < GAME_MAX_Y; column++)
              {
               printIntAt(17, 1, gameField[ row ][ column ], "LEFT" );
              }
          }

       // if character moves over spawned object, check for effect ( status )

       
         // set x and y position for cloak counter
           statusX = 13;
           statusY = 4;

       }
    while( alive == true );

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

void spawnObject( short gameField [GAME_MAX_X] [GAME_MAX_Y] )
   {
    // initialize variables
       int itemNum, randX, randY, counter = 0;

    // generate random number
       // function: getRandomBetween
    itemNum = getRandomBetween( ONE, MAX_SPAWN);

    // loop while counter < 1
    while (counter << ONE)
       {
        // generate random x position
        randX = getRandomBetween( ZERO, MAX_RAND_X);

        // generate random y position
        randY = getRandomBetween( ZERO, MAX_RAND_Y);

        // spawn item
           // test if position in array == space
           if( gameField [randX] [randY] == SPACE )  
              { 
               // and itemNum is between 1 and 35, print hole, increment counter
               if( itemNum >= ONE && itemNum <= MAX_HOLE)
                  {
                   gameField [randX][randY] = HOLE;
                   counter++;
                  }

               // and itemNum is between 36 and 45, print cloak, increment counter
               else if( itemNum >= MIN_CLOAK && itemNum <= MAX_CLOAK)
                  {
                   gameField [randX][randY] = CLOAK;
                   counter++;
                  }

               // and itemNum is between 46 and 50, print treasure, increment counter
               else if( itemNum >= MIN_TREASURE && itemNum <= MAX_TREASURE)
                  {
                   gameField [randX][randY] = TREASURE;
                   counter++;
                  }

               // and itemNum is between 51 and 60, print spell, increment counter
               else if( itemNum >= MIN_SPELL && itemNum <= MAX_SPELL)
                  {
                   gameField [randX][randY] = SPELL;
                   counter++;
                  }

               // and itemNum is between 61 and 85, print monster, increment counter
               else if( itemNum >= MIN_MONSTER && itemNum <= MAX_MONSTER)
                  {
                   gameField [randX][randY] = MONSTER;
                   counter++;
                  }     

               // and itemNum is between 86 and 95, print sword, increment counter
               else if( itemNum >= MIN_SWORD && itemNum <= MAX_SWORD)
                  {
                   gameField [randX][randY] = SWORD;
                   counter++;
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
       int range = highVal - lowVal + 1;

    // return randomly generated value between low and high, starting at low
       // function: rand
    return ( rand() % range + lowVal );
   }

bool move( int &xPos, int &yPos, int xVect, int yVect )
   {
    // initialize function/variables
    bool moved = false;
    int oldX = xPos, oldY = yPos;

    // if x vector is live, test for acceptable movement limits
    if( ( xVect != 0 ) // is meant to move
          && ( xPos + xVect >= SCRN_MIN_X ) // won't go off left side of screen 
               && ( xPos + xVect <= SCRN_MAX_X )  ) // won't go off right side of screen
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
               && ( yPos + yVect >= SCRN_MIN_Y ) // won't go off top of screen (!= WALL_SYMBOL)?
                    && ( yPos + yVect <= SCRN_MAX_Y ) ) // won't go off bottom of screen
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
    int counter;
    int leftUpperX = 16;
    int leftUpperY = 0;
    int rightLowerX = 79;
    int rightLowerY = 24;

    // set color
    setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
    
    // clear screen in shape of box
    clearScreen( leftUpperX, leftUpperY, rightLowerX, rightLowerY );

    // iterate from left to right across box
    for( counter = leftUpperX; counter < leftUpperX; counter++ )
       {
        // print top frame character
        printSpecialCharAt( counter, leftUpperY, WALL_SYMBOL );

        // print bottom frame character
        printSpecialCharAt( counter, rightLowerY, WALL_SYMBOL );
       }
    
    for( counter = leftUpperY; counter < leftUpperY; counter++ )
       {
        // print left frame character
        printSpecialCharAt( leftUpperX, counter, WALL_SYMBOL );

        // print right frame character
        printSpecialCharAt( rightLowerX, counter, WALL_SYMBOL );
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
