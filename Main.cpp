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

  int it[50] = {6, 1, 9 ,2, 1, 7 ,3, 7, 3, 1,10, 3, 6, 8, 8 ,5, 5, 2, 1, 1,2, 4 ,9 ,2, 1 ,7 ,1, 9, 2, 2,3, 10 ,1, 5, 3, 9, 5, 4, 7, 9,7, 3 ,10, 1, 7, 5, 10, 6 ,5, 6} ;
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

  if(currcol == y){
   return 0;
 }

  int temp1 = 0, tempmatrix = 0;

  for (int i = 0; i < x; i ++){
    if(i < secondrow<=firstrow || firstrow <= secondrow < i){
      tempmatrix = matrix[i][currcol] - abs(2*(i-secondrow));
    }else if (i < firstrow<= secondrow|| secondrow<= firstrow <i){
      tempmatrix = matrix[i][currcol] - abs(2*(i-firstrow));
    }else{
      tempmatrix = matrix[i][currcol];
    }
    tempmatrix += greatestPath(firstrow, i, currcol+1, x, y, matrix);
    if(temp1 < tempmatrix){
      temp1 = tempmatrix;
      arr[currcol] = i;
    } 
  }
  
 
  return temp1;
}