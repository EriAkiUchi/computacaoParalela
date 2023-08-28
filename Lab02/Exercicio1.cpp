#include <iostream>

const int lineSize = 3;
const int columnSize = 4;

void printMatrix(int Matrix[][columnSize], int lines, int cols) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << Matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
  std::cout << "\n";
}

int main() {

 int  Matrix[][columnSize] = {
   { 32, 47, 31, 19 },
   { 11, 22, 33, 17 },
   { 41, 22,  9, 22 }
 };
  
  int min = Matrix[0][0];
  int minLine = 0;
  for (int i = 0; i < lineSize; i++){
    for (int j = 0; j < columnSize; j++){
      if (min > Matrix[i][j]){
        min = Matrix[i][j];
        minLine = i+1;
      }
    }
  }
  
  std::cout << "Matriz: " << std::endl;
    
  printMatrix(Matrix, lineSize, columnSize);
  
  std::cout << "O menor elemento está na linha: " << minLine << std::endl;
}

