#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ROWS = 22;
const int MAX_COL = 62;
const char fileName[]= "midlevel.txt";
const char SPACE = ' ';
const int WALL_SYMBOL = 176;

int openMapFile( const char fileName[], short mapArr[][ MAX_COL ]);

int main()
{
  short gameArr [MAX_ROWS][MAX_COL];

  openMapFile( fileName, gameArr );

  for(int i = 0; i < 22; i++)
  {
    for(int j = 0; j< 62; j++)
    {
      cout << gameArr[i][j]  << " ";
    }
    cout << endl;
  }
system ("PAUSE");

	return 0;
}

int openMapFile( const char fileName[], short mapArr[][ MAX_COL ] )
{
	ifstream inf;
	int x, y;
	int index, index_2;

	inf.clear();
	inf.open( fileName );

	for( index = 0; index < MAX_ROWS; index++ )
	{
		for( index_2 = 0; index_2 < MAX_COL; index_2++ )
		{
			mapArr[index][index_2] = SPACE;
		}
	}


	while( inf.peek() != EOF )
	{
		inf >> x >> y;

		mapArr[y][x] = WALL_SYMBOL;
	}

	return 0;
}
