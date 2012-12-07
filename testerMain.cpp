#include <iostream>
#include <fstream>


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


int openMapFile( char fileName[], short mapArr[][ MAX_COL ]);

int main()
{
	return 0;
}

int openMapFile( char fileName[], short mapArr[][ MAX_COL ] )
{
	ifstream inf;
	int x, y;
	int index, index_2;

	inf.clear();
	inf.open( fileName );

	for( index = 0; index < GAME_MAX_X; index++ )
	{
		for( index_2 = 0; index_2 < GAME_MAX_Y; index_2++ )
		{
			mapArr[index][index_2] = SPACE;
		}
	}


	while( inf.peak() != EOF )
	{
		inf >> x >> y;

		mapArr[x][y] = WALL_SYMBOL;
	}
	return 0;
}