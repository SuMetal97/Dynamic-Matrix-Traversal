#include <iostream>
#include <vector>

using namespace std;
int MatrixCreate();
int greatestPath(int SecondRow, int FirstRow, int currRow, int x, int y, int** matrix);
int* arr;

int main() {
  int x = MatrixCreate();
  cout << x;
  
}

int MatrixCreate(){
  int x, y, value = 0;
  int given_matrix_itt = 0;
  int SecondRow = 0, FirstRow = 0, currCol = 0;

  int it[12] = {2, 3, 4, 1,5, 1, 2, 4,4, 5, 3, 4} ;
  cin >> x >> y;

  

int** matrix = new int*[x];
if (x)
{
    matrix[0] = new int[x * y];
    for (int i = 1; i < x; ++i)
        matrix[i] = matrix[0] + i * y;
}

 for(int i = 0; i < x; i++){
   for (int j = 0; j < y; j++){
     matrix[i][j] = it[given_matrix_itt];
     given_matrix_itt++;
   }
 }

 for(int i = 0; i < x; i++){
   for (int j = 0; j < y; j++){
     if( i == 0 && j == 0){
       
     }
     cout <<matrix[i][j];
     cout<< " ";
   }
   cout << "\n";
 }
arr = new int[y];
  int answer = greatestPath(0,0, 0, x, y, matrix);

  cout << "\n";
  for (int i = 0; i <y; i++){
    cout << arr[i];
    cout << " ";
  }
  cout << "\n";
    return answer;
}



int greatestPath(int secondrow, int firstrow, int currcol, int x, int y, int** matrix){
  
  int temp = 0;

  if(currcol >= y){
   return 0;
 }

  int temp1 = 0, tempmatrix = 0;

  for (int i = 0; i < x; i ++){
  //trying to implement the algorithm to trace penalties here
   /* if (i < firstrow < secondrow){
      tempmatrix = (matrix[i][currcol] - ((firstrow - i)*2));
    }
    else if (i < secondrow < firstrow){
      tempmatrix = (matrix[i][currcol] - ((secondrow - i)*2));
    }
    else if (firstrow < secondrow < i){
      tempmatrix = (matrix[i][currcol] - ((i - firstrow)*2));
    }
    else if (secondrow < firstrow < i){
      tempmatrix = (matrix[i][currcol] - ((i - secondrow)*2));
    }
    else {*/
      tempmatrix = matrix[i][currcol];
    //}
    tempmatrix += greatestPath(firstrow, i, currcol+1, x, y, matrix);
    if(temp1 < tempmatrix){
      temp1 = tempmatrix;
      arr[currcol] = i;
    } 
  }
 
  return temp1;
}