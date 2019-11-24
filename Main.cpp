#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int ***keptScores;
int ***keptRows;
int **givenmatrix;

int greatestPath(int curcol, int x);
int Penalty(int row, int rowold, int rownew);


int main()
{
  ifstream input_file;  // create input file stream object
  ofstream output_file; // create output file stream object

  // read input.txt and display matrix, allocate space for the given matrix here
  int x = 0, y = 0;
  input_file.open("input.txt");
  input_file >> x >> y; 
  givenmatrix = new int *[x];
  for (int i = 0; i < x; i++)
  {
    givenmatrix[i] = new int[y];
  } 
  while (input_file.is_open())
  {
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        input_file >> givenmatrix[i][j];
      }
    }
    input_file.close();
  }
  /////////////////////////////////////////////////////////////////////////////////

  //allocate space for ramaing data as they are needed in next function call
  keptScores = new int **[y];
  for (int i = 0; i < y; i++)
  {
    keptScores[i] = new int *[x];
    for (int j = 0; j < x; j++)
    {
      keptScores[i][j] = new int[x];
    }
  }
  keptRows = new int **[y];
  for (int i = 0; i < y; i++)
  {
    keptRows[i] = new int *[x];
    for (int j = 0; j < x; j++)
    {
      keptRows[i][j] = new int[x];
    }
  }
  ///////////////////////////////////////////////////////////////////////////

  //Calculate path and values///////////////////////////////////////////////
  int finalSum = greatestPath(y, x);
  /////////////////////////////////////////////////////////////////////////

  //free space for no longer needed data
  free(givenmatrix);
  free(keptScores);
  ////////////////////////////////////////
  
  output_file.open("output.txt");
  output_file << finalSum << "\n";
  int old = 0, New = 0;
  for (int i = 0; i < y; i++)
  {

    output_file << keptRows[i][old][New];
    output_file << " ";
    old =New;
    New = keptRows[i][old][New];
  }
  output_file.close();
  ////////////////////////////////////////////////////////////////////////////

  //free remaing data///////////////////////////////////////////
  free(keptRows);
  //////////////////////////////////////////////////////////////

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Penalty (int row, int high, int low) {
    if (low > high) {
        int temp = high;
        high = low;
        low = temp;
    }
    if (row < low) {
      return (low - row) * 2;
    }
    else if (row > high) {
      return(row - high) * 2;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Iterate Through the given matrix while dynamically using previous values///////////////////////////////////
int greatestPath(int curcol, int x)
{
  for (int i = curcol - 1; i >= 0; i--)
  {
    for (int j = 0; j < x; j++)
    {
      for (int k = 0; k < x; k++)
      {
        int maxRow = 0;
        int maxValue = 0;
        if (i == (curcol - 1))
        {
          for (int currentRow = 0; currentRow < x; currentRow++)
          {
            int temp = givenmatrix[currentRow][i] - Penalty(currentRow, j, k);
            if (maxValue < temp)
            {
              maxValue = temp;
              maxRow = currentRow;
            }
          }
        }
        else
        {
          for (int currentRow = 0; currentRow < x; currentRow++)
          {
            int temp = givenmatrix[currentRow][i] + keptScores[i + 1][k][currentRow]- Penalty(currentRow, j, k);
            if (maxValue < temp)
            {
              maxValue = temp;
              maxRow = currentRow;
            }
          }
        }
        keptScores[i][j][k] = maxValue;
        keptRows[i][j][k] = maxRow;
      }
    }
  }
  return keptScores[0][0][0];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////