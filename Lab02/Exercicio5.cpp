#include <iostream>

const int columnSize = 4;
const int lineSize = 3;

int multLine(int Matrix[][columnSize], int line, int number){
  for (int i = 0; i < columnSize; i++){
     Matrix[line][i] = number * Matrix[line][i]; 
  }
  return **Matrix;
}

int multColumn(int Matrix[][columnSize], int column, int number){
  for (int i = 0; i < lineSize; i++){
     Matrix[i][column] = number * Matrix[i][column]; 
  }
  return **Matrix;
}

void printMatrix(int Matrix[][columnSize], int lines, int cols) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << Matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
  std::cout << "\n\n";
}

int main(){

  int Matrix[][columnSize] = {
   { 32, 47, 31, 19 },
   { 11, 22, 33, 17 },
   { 41, 22, 9, 22 }
   };

  int lineToMult = 1;
  int columnToMult = 0;
  int number = 5;
  
  std::cout << "Matriz Original: \n";
  printMatrix(Matrix, lineSize, columnSize);

  std::cout << "Matriz depois de multiplicar a linha " << lineToMult + 1 << ": \n";
  multLine(Matrix, lineToMult, number);
  printMatrix(Matrix, lineSize, columnSize);
  
  std::cout << "Matriz depois de multiplicar a coluna " << columnToMult + 1 << ": \n";
  multColumn(Matrix, columnToMult, number);
  printMatrix(Matrix, lineSize, columnSize);
  
  return 0;
}
