#include <iostream>
#include <vector>

using namespace std;

int*** threedmatrix;
int** givenmatrix;
void matrixCreate(int x, int y);
int greatestPath(int row2, int row1,int curcol);

int main() {
  int x, y;
  cin >> x >> y;
  matrixCreate(x,y);
  
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//allocate space for a 3 d array, then the given 2d array
void matrixCreate(int x, int y){
  

  //use size input x and y to make space for the 3d array
  int ***threedmatrix = new int**[x];
  for (int i = 0; i < x; ++i) {
    threedmatrix[i] = new int*[y];
    for (int j = 0; j < y; ++j)
      threedmatrix[i][j] = new int[x];
  }

  //use x and y to make space for the given matrix
  givenmatrix = new int*[x];
  if (x)
  {
    givenmatrix[0] = new int[x * y];
    for (int i = 1; i < x; ++i)
        givenmatrix[i] = givenmatrix[0] + i * y;
  }

  int p = 0;
  int arr[12] = {2,3,4,1,5,1,2,4,4,5,3,4};
  for (int i = 0; i < x; i ++){
    for (int j = 0; j < y; j++){
      givenmatrix[i][j] = arr[p];
      p++;
    }
  }
  for (int i = 0; i < x; i ++){
    for (int j = 0; j < y; j++){
      cout << givenmatrix[i][j];
      cout << " ";
    }
    cout << "\n";
  }

//
  int row1 = 0, row2 = 0, tempx=0, tempy=0;
  for (int i = 0; i < x; i++){
    row1 = i;
    threedmatrix[i][tempy][tempx] = (givenmatrix[i][tempy] - (2*row1));
    cout << threedmatrix[i][tempy][tempx];
    cout << " ";
    //greatestPath(x,i,0);
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////